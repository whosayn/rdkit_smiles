%{
#include "smiles_scanner.h"
#include "smiles_grammar.hh"

#undef YY_DECL
#define YY_DECL int smiles_parser::SmilesTokenScanner::lex(smiles_parser::SmilesTokenParser::semantic_type* const lval, smiles_parser::SmilesTokenParser::location_type* location)

#define YY_USER_ACTION std::cout << location->begin.column << ":" << yyleng <<std::endl; \
                       location->step(); location->columns(yyleng);

    using token = smiles_parser::SmilesTokenParser::token_kind_type;
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


<*>[1-9]+ {  std::cout << "any num:: " << yytext << std::endl; return token::NUMBER; }

<*>H { std::cout << "any h:: " << yytext << std::endl; return token::H_TOKEN; }
<*>B|C|N|O|P|S|F|Cl|Br|I { std::cout << "any organic:: " << yytext << std::endl; return token::ORGANIC_ATOM; }


<*>[a-z]  { std::cout << "any aromatic:: " << yytext << std::endl; return token::SIMPLE_ATOM; }
<IN_ATOM_STATE>[A-Z][a-z]*? {  std::cout << "atom atom:: " << yytext << std::endl; return token::NESTED_ATOM ; }
<IN_ATOM_STATE>si|as|se|te { std::cout << "atom organic:: " << yytext << std::endl; return token::NESTED_ATOM; }

@[' ']*[A-Z]+? {  std::cout << "ctag:: " << yytext << std::endl; return token::CHIRAL_TAG;}
\[  { BEGIN IN_ATOM_STATE;  std::cout << "begin atom:: " << yytext << std::endl; return yytext[0]; }


<IN_ATOM_STATE>\]	{ BEGIN INITIAL;  std::cout << "]:: " << yytext << std::endl; return yytext[0]; }
<IN_ATOM_STATE>. 	{  std::cout << "atom any:: " << yytext << std::endl; return yytext[0]; }

.		{  std::cout << "any:: " << yytext << std::endl; return yytext[0]; }
<<EOF>>		{ std::cout << "EOS" << std::endl; return token::YYEOF; }

%%
