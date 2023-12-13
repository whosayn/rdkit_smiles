#include "smiles_parser.h"

#include <sstream>
#include "smiles_grammar.hh"
#include "smiles_scanner.h"

std::vector<MolInfo> parse(std::string_view val) {
    std::istringstream iss(val.data());
    smiles_parser::SmilesTokenScanner sc(&iss, val);
    smiles_parser::SmilesTokenParser pp(sc);
    pp.parse();

    return {};
}
