%require  "3.8"

%debug
%defines
%define api.namespace {smiles_parser}
%define api.parser.class {SmilesTokenParser}
%define api.value.type variant
//%define api.value.automove
%defines "smiles_grammar.hh"
%output "smiles_grammar.cc"

%language "c++"
%locations


%code requires {
namespace smiles_parser {
class SmilesTokenScanner;
}
}

%parse-param { SmilesTokenScanner& token_scanner }
%initial-action { @$.begin.column = 0; };

%code {
#include "smiles_scanner.h"
#include "smiles_parser.h"

#undef yylex
#define yylex token_scanner.lex


}

%token NUMBER CHIRAL_TAG SIMPLE_ATOM NESTED_ATOM H_TOKEN ORGANIC_ATOM;

%start mols

%%
/* --------------------------------------------------------------- */
/*
meta_start:
| meta_start EOS_TOKEN
;
*/

mols: mol
    | mols '.' mol
    ;

/* --------------------------------------------------------------- */
// FIX: mol MINUS DIGIT
mol: atom
   | mol atom
   | mol bond atom
   | mol ring_number
   | mol bond ring_number
   | mol '(' atom
   | mol '(' bond atom
   | mol ')'
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
atom:	SIMPLE_ATOM
    | ORGANIC_ATOM
    | '[' charge_element ':' NUMBER ']'
    | '[' charge_element ']'
    ;

/* --------------------------------------------------------------- */
charge_element:	h_element
              | h_element '+'
              | h_element '+' '+'
              | h_element '+' NUMBER
              | h_element '-'
              | h_element '-' '-'
              | h_element '-' NUMBER
              ;

/* --------------------------------------------------------------- */
h_element: H_TOKEN
         | NUMBER H_TOKEN
         | H_TOKEN H_TOKEN
         | NUMBER H_TOKEN H_TOKEN
         | H_TOKEN H_TOKEN NUMBER
         | NUMBER H_TOKEN H_TOKEN NUMBER
         | chiral_element
         | chiral_element H_TOKEN
         | chiral_element H_TOKEN NUMBER
         ;

/* --------------------------------------------------------------- */
chiral_element:	 element
              | element '@'
              | element '@' '@'
              | element CHIRAL_TAG
              | element CHIRAL_TAG NUMBER
              ;

/* --------------------------------------------------------------- */
element:	SIMPLE_ATOM
	   |	NUMBER SIMPLE_ATOM
       |	ORGANIC_ATOM
	   |	NUMBER ORGANIC_ATOM
       |	NESTED_ATOM
       |	NUMBER NESTED_ATOM
       |   '#' NUMBER
       |	NUMBER '#' NUMBER
       ;

/* --------------------------------------------------------------- */
ring_number:  NUMBER
           | '%' NUMBER
           | '%' '(' NUMBER ')' '%'
           ;

%%

void smiles_parser::SmilesTokenParser::error(const location&, const std::string& msg) {
    std::cerr << "error ++++: " << msg << std::endl;
}
