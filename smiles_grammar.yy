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
%parse-param { SmilesASTBuilder& ast }
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

%token <std::string_view> ATOM_SYMBOL NESTED_ATOM H_TOKEN ORGANIC_ATOM BIOVIA_ATOM CHIRAL_TAG NUMBER;

%type <std::pair<std::string_view, bool>> ring_number;
%type <std::string_view> bond;
%type <int> minus_signs plus_signs atom_charge explicit_h;
%type <mol_info> mol;


%start mol

%%
// FIX: mol MINUS DIGIT
mol: atom {  auto i = ast.get_num_atoms(); $$ = { i, i, 1}; }
   | mol atom  { $$ = $1;  $$.tail = $$.head + $$.size; ast.add_bond($1.tail, $$.tail); ++$$.size; }
   | mol '.' atom  { $$ = $1;  $$.tail = $$.head + $$.size; ++$$.size; }
   | mol bond atom  { $$ = $1; ast.add_bond($$.tail, ++$$.tail, $2); ++$$.size; }
   | mol ring_number  { $$ = $1; ast.add_ring_info($2.first, "-", $2.second); }
   | mol bond ring_number { $$ = $1; ast.add_ring_info($3.first, $2, $3.second); }
   | mol '(' mol ')'  { $$ = $1; ast.add_bond($1.tail, $3.head); $$.size += $3.size; }
   | mol '(' bond mol ')'  { $$ = $1; ast.add_bond($1.tail, $4.head, $3); $$.size += $4.size; }
   ;

bond: '-' { $$ = "-"; }
    | '=' { $$ = "="; }
    | '#' { $$ = "#"; }
    | ':' { $$ = ":"; }
    | '$' { $$ = "$"; }
    | '~' { $$ = "~"; }
    | '-' '>' { $$ = "->"; }
    | '<' '-' { $$ = "<-"; }
    | '\\' { $$ = "\\"; }
    | '\\' '\\' { $$ = "\\\\"; }
    | '/' { $$ = "/"; };

// ways to represent atom info
atom: ATOM_SYMBOL { ast.add_atom($1); }
    | ORGANIC_ATOM { ast.add_atom($1); }
    | '[' complex_atom ':' atom_map_number ']'
    | '[' complex_atom ']';

atom_map_number: NUMBER { ast.add_atom_map_number(stoi($1)); };

complex_atom: uncharged_atom | charged_atom;

charged_atom: uncharged_atom atom_charge { ast.add_atom_charge($2); };

atom_charge: plus_signs | '+' NUMBER { $$ = stoi($2); }
           | minus_signs | '-' NUMBER { $$ = -1 * stoi($2); };
plus_signs: '+' { $$ = 1; } | plus_signs '+' { $$ = $1 + 1; };
minus_signs: '-' { $$ = -1; } | minus_signs '-' { $$ = $1 - 1; };

uncharged_atom: singular_atom | atom_with_hs;

atom_with_hs: singular_atom explicit_h { ast.add_explicit_h($2); };
explicit_h: H_TOKEN { $$ = 1; } | H_TOKEN NUMBER { $$ = stoi($2); };

singular_atom: hydrogen_atom | achiral_atom | chiral_atom;

hydrogen_atom: H_TOKEN { ast.add_atom($1); }
             | NUMBER H_TOKEN { ast.add_atom($2);
                                ast.add_isotope_num(stoi($1)); }

chiral_atom: achiral_atom '@' { ast.add_chirality_tag("@"); }
           | achiral_atom '@' '@' { ast.add_chirality_tag("@@"); }
           | achiral_atom CHIRAL_TAG { ast.add_chirality_class($2); }
           | achiral_atom CHIRAL_TAG NUMBER { ast.add_chirality_class($2, $3); }

achiral_atom: non_hydrogen_atom | non_hydrogen_isotope;

non_hydrogen_isotope: NUMBER non_hydrogen_atom { ast.add_isotope_num(stoi($1)); }

non_hydrogen_atom: ATOM_SYMBOL { ast.add_atom($1); }
                 | ORGANIC_ATOM { ast.add_atom($1); }
                 | NESTED_ATOM { ast.add_atom($1); }
                 | '#' NUMBER { ast.add_atom($2); }
                 | BIOVIA_ATOM { ast.add_atom($1); }

ring_number: NUMBER { $$ = { $1, false }; }
           | '%' NUMBER { $$ = { $2, true }; }
           | '%' '(' NUMBER ')' { $$ = { $3, true }; };
%%

void smiles_parser::SmilesTokenParser::error(const location& loc, const std::string& msg) {
    std::cerr << "'"<< token_scanner.d_input << "' failed because of " << msg <<
" at position: " << loc.begin.column << std::endl;

}
