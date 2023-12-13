%require  "3.8"

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

%token NUM 0;
%token EOS 1;

%start ii

%%
ii: input EOS;

input : NUM
      | input NUM;

%%

void smiles_parser::SmilesTokenParser::error(const location&, const std::string& msg) {
    std::cerr << "error ++++: " << msg << std::endl;
}
