%{
#include "smiles_scanner.h"
#include "smiles_grammar.hh"

#undef YY_DECL
#define YY_DECL int smiles_parser::SmilesTokenScanner::lex(smiles_parser::SmilesTokenParser::semantic_type* const lval, smiles_parser::SmilesTokenParser::location_type* location)

#define YY_USER_ACTION std::cout << location->begin.column << ":" << yyleng <<std::endl; \
                       location->step(); location->columns(yyleng);
%}

%option c++
%option full
%option never-interactive
%option nodefault
%option noyywrap
%option yylineno
%option yyclass="smiles_parser::SmilesTokenScanner"
%option outfile="smiles_lexer.yy.cc"

%s IN_ATOM_STATE

%%


<*>[1-9]+ {  std::cout << "any num:: " << yytext << std::endl; return 0; }
<*>[a-z]  { std::cout << "any organic:: " << yytext << std::endl; return 0; }
<IN_ATOM_STATE>[A-Z][a-z]*? {  std::cout << "atom atom:: " << yytext << std::endl; return 0; }
<IN_ATOM_STATE>si|as|se|te { std::cout << "atom organic:: " << yytext << std::endl; return 0; }

[A-Z][a-z]*? {  std::cout << "atom:: " << yytext << std::endl; return 0; }
@[' ']*[A-Z]+? {  std::cout << "ctag:: " << yytext << std::endl; return 0;}
\[  { BEGIN IN_ATOM_STATE;  std::cout << "begin atom:: " << yytext << std::endl; return 0; }


<IN_ATOM_STATE>\]	{ BEGIN INITIAL;  std::cout << "]:: " << yytext << std::endl; return 0; }
<IN_ATOM_STATE>. 	{  std::cout << "atom any:: " << yytext << std::endl; return 0; }

.		{  std::cout << "any:: " << yytext << std::endl; return 0; }
<<EOF>>		{ std::cout << "EOS" << std::endl; return 1; }

%%
