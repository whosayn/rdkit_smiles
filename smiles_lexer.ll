%{
#include "smiles_scanner.h"
#include "smiles_grammar.hh"

#undef YY_DECL
#define YY_DECL int smiles_parser::SmilesTokenScanner::lex(smiles_parser::SmilesTokenParser::semantic_type* const lval, smiles_parser::SmilesTokenParser::location_type* location)

#define YY_USER_ACTION \
    lval->build<std::string_view>(d_input.substr(location->begin.column, yyleng)); \
    location->begin += yyleng; location->columns(yyleng);

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


<*>[0-9]+ { return token::NUMBER; }

<*>H { return token::H_TOKEN; }
<*>Cl|Br|B|C|N|O|P|S|F|I|\* { return token::ORGANIC_ATOM; }


<*>[a-z]  { return token::ATOM_SYMBOL; }
<IN_ATOM_STATE>[A-Z][a-z]*? {  return token::NESTED_ATOM ; }
<IN_ATOM_STATE>si|as|se|te { return token::NESTED_ATOM; }
<IN_ATOM_STATE>\'[A-Z][a-z]*?\' {  return token::BIOVIA_ATOM ; }

@[' ']*[A-Z][A-Z] {  return token::CHIRAL_TAG;}
<INITIAL>\[  { BEGIN IN_ATOM_STATE;  return yytext[0]; }

<IN_ATOM_STATE>\]	{ BEGIN INITIAL; return yytext[0]; }

<*>.		{  return yytext[0]; }

%%
