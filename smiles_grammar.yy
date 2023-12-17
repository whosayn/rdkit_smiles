%require  "3.8"

%debug
%defines
%define api.namespace {smiles_parser}
%define api.parser.class {SmilesTokenParser}
%define api.value.type variant
%defines "smiles_grammar.hh"
%output "smiles_grammar.cc"

%language "c++"
%locations


%code requires {
#include <cstddef>

namespace smiles_parser {

class SmilesTokenScanner;
class SmilesASTBuilder;

namespace {
struct mol_info {
    size_t head;
    size_t tail;
    size_t size;
};
}

}
}

%parse-param { SmilesTokenScanner& token_scanner }
%parse-param { SmilesASTBuilder& ast_builder }
%initial-action { @$.begin.column = 0; };

%code {
#include <charconv>
#include <utility>

#include "smiles_scanner.h"
#include "smiles_parser.h"

#undef yylex
#define yylex token_scanner.lex

namespace {
[[nodiscard]] size_t stoi(std::string_view s) {
    size_t result;
    std::from_chars(s.data(), s.data() + s.size(), result);
    return result;
}
}

}

%token <std::string_view> SIMPLE_ATOM NESTED_ATOM H_TOKEN ORGANIC_ATOM BIOVIA_ATOM CHIRAL_TAG NUMBER;

%type <std::string_view> ring_number;
%type <int> minus_signs plus_signs atom_charge explicit_h;
%type <mol_info> mol;


%start mol

%%
/* --------------------------------------------------------------- */
// FIX: mol MINUS DIGIT
mol: atom {  auto i = ast_builder.get_num_atoms(); $$ = { i, i, 1}; }
   | mol atom  { $$ = $1;  $$.tail = $$.head + $$.size; ast_builder.add_bond($1.tail, $$.tail); ++$$.size; }
   | mol '.' atom  { $$ = $1;  $$.tail = $$.head + $$.size; ast_builder.add_bond($1.tail, $$.tail); ++$$.size; }
   | mol bond atom  { $$ = $1; ast_builder.add_bond($$.tail, ++$$.tail); ++$$.size; }
   | mol ring_number  { $$ = $1; }
   | mol bond ring_number { $$ = $1; }
   | mol '(' mol ')'  { $$ = $1; ast_builder.add_bond($1.tail, $3.head); $$.size += $3.size; }
   | mol '(' bond mol ')'  { $$ = $1; ast_builder.add_bond($1.tail, $4.head); $$.size += $4.size; }
   ;

/* --------------------------------------------------------------- */
bond: '-'
    | '='
    | '#'
    | ':'
    | '$'
    | '~'
    | '-' '>'
    | '<' '-'
    | '\\'
    | '\\' '\\'
    | '/' ;
    ;

/* --------------------------------------------------------------- */
atom: simple_atom
    | '[' needs_sq_bracs ':' atom_map_number ']'
    | '[' needs_sq_bracs ']'
    ;

atom_map_number: NUMBER { ast_builder.add_atom_map_number(stoi($1)); }

needs_sq_bracs: atom_that_can_have_charge | atom_with_charge;

atom_with_charge: atom_that_can_have_charge atom_charge {
                                              ast_builder.add_atom_charge($2); }

atom_charge: plus_signs
           | '+' NUMBER { $$ = stoi($2); }
           | minus_signs
           | '-' NUMBER { $$ = -1 * stoi($2); }
           ;
plus_signs: '+' { $$ = 1; } | plus_signs '+' { $$ = $1 + 1; };
minus_signs: '-' { $$ = -1; } | minus_signs '-' { $$ = $1 - 1; };

atom_that_can_have_charge: atom_that_can_have_hydrogens | atom_with_hydrogens;

atom_with_hydrogens: atom_that_can_have_hydrogens explicit_h { ast_builder.add_explicit_h($2); };

explicit_h: H_TOKEN { $$ = 1; } | H_TOKEN NUMBER { $$ = stoi($2); }

atom_that_can_have_hydrogens: hydrogen_atom
           | element
           | chiral_element;


hydrogen_atom: H_TOKEN { ast_builder.add_atom($1); }
             | NUMBER H_TOKEN { ast_builder.add_atom($2);
                                ast_builder.add_isotope_num(stoi($1)); }

chiral_element:	element '@' { ast_builder.add_chirality_tag("@"); }
              | element '@' '@' { ast_builder.add_chirality_tag("@@"); }
              | element CHIRAL_TAG { ast_builder.add_chirality_class($2); }
              | element CHIRAL_TAG NUMBER { ast_builder.add_chirality_class($2, $3); }
              ;

element: non_isotope | isotope;

isotope: NUMBER non_isotope { ast_builder.add_isotope_num(stoi($1)); }

non_isotope: simple_atom
       |	NESTED_ATOM { ast_builder.add_atom($1); }
       |   '#' NUMBER { ast_builder.add_atom($2); }
       |    BIOVIA_ATOM { ast_builder.add_atom($1); }
       ;

simple_atom: SIMPLE_ATOM { ast_builder.add_atom($1); }
           | ORGANIC_ATOM { ast_builder.add_atom($1); }
           ;

ring_number:  NUMBER { $$ = $1; }
           | '%' NUMBER { $$ = $2; }
           | '%' '(' NUMBER ')' { $$ = $3; }
           ;

%%

void smiles_parser::SmilesTokenParser::error(const location& loc, const std::string& msg) {
    std::cerr << "'"<< token_scanner.d_input << "' failed because of " << msg <<
" at position: " << loc.begin.column << std::endl;

}
