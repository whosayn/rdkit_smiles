#pragma once

#include <memory>
#include <string_view>

namespace RDKit {
class RWMol;
}

namespace smiles_parser {
std::unique_ptr<::RDKit::RWMol> SmilesToMol(std::string_view smiles);
}
