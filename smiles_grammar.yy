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

%type <std::string_view> bond_token;
%type <int> minus_signs plus_signs atom_charge explicit_h;


%start mol

%%
// FIX: mol MINUS DIGIT
mol: atom
   | mol atom
   | mol sep atom
   | mol bond atom
   | mol ring_number
   | mol bond ring_number
   | mol branch_open mol branch_close
   | mol branch_open bond mol branch_close
   ;

sep: '.' { ast.add_sep_info(); }
branch_open: '('  { ast.add_branch_info("("); }
branch_close: ')'  { ast.add_branch_info(")"); }

bond: bond_token { ast.add_bond($1); }
bond_token: '-' { $$ = "-"; }
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
    | '[' complex_atom ':' atom_map_number ']' { ast.set_no_implicit_hs(); }
    | '[' complex_atom ']' { ast.set_no_implicit_hs(); };

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

ring_number: NUMBER { ast.add_ring_info($1, false); }
           | '%' NUMBER { ast.add_ring_info($2, true); }
           | '%' '(' NUMBER ')' { ast.add_ring_info($3, true); };
%%

void smiles_parser::SmilesTokenParser::error(const location& loc, const std::string& msg) {
    auto bad_position = loc.begin.column -1;
    std::cerr << "'"<< token_scanner.d_input << "' failed because of " << msg <<
" at position: " << bad_position << std::endl;
    std::cerr << token_scanner.d_input << std::endl;
    std::cerr << std::string(bad_position, '-') << '^' << std::endl;
}
