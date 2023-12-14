#pragma once

#include <istream>
#include <string_view>


#undef yyFlexLexer
#define yyFlexLexer smilesFlexLexer
#include <FlexLexer.h>

#include "smiles_grammar.hh"

namespace smiles_parser {
    class SmilesTokenScanner : public smilesFlexLexer {
        public:
            SmilesTokenScanner(std::istream* input_stream, std::string_view ss) : smilesFlexLexer(input_stream),
            d_input(ss) { }

            int lex(smiles_parser::SmilesTokenParser::semantic_type* const lval,
                    smiles_parser::SmilesTokenParser::location_type* location);

            std::string_view d_input;

    };
}

// don't know why these aren't generated
inline int smilesFlexLexer::yylex() { return 0; }
inline int smilesFlexLexer::yywrap() { return 1; }
