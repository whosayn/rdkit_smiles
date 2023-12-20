#include "mol_builder.h"

#include <array>
#include <charconv>
#include <unordered_map>
#include <utility>

#include <GraphMol/RWMol.h>
#include <GraphMol/Bond.h>
#include <GraphMol/QueryBond.h>
#include "smiles_parser.h"

namespace smiles_parser {

namespace {

[[nodiscard]] static size_t stoi(std::string_view s) {
  size_t result;
  std::from_chars(s.data(), s.data() + s.size(), result);
  return result;
}

void add_atoms(::RDKit::RWMol& mol, const std::vector<AtomInfo>& atoms) {
  for (auto& atom_info : atoms) {
    auto atom = std::make_unique<::RDKit::Atom>(atom_info.atomic_number);
    atom->setIsotope(atom_info.isotope);
    atom->setNumExplicitHs(atom_info.explicit_h_count);
    atom->setProp(RDKit::common_properties::molAtomMapNumber,
                  atom_info.map_number);
    atom->setFormalCharge(atom_info.formal_charge);

    std::optional<AtomChiralityInfo> chirality;
    if (atom_info.chirality != std::nullopt) {
      // TODO: add chirality info
    }
    mol.addAtom(atom.release(), true, true);
  }
}

void add_bonds(::RDKit::RWMol& mol, const std::vector<BondInfo>& bonds) {
  using BondType = ::RDKit::Bond::BondType;

  static constexpr std::array<
      std::pair<std::string_view, ::RDKit::Bond::BondType>, 10>
      info{{
          {"-", BondType::SINGLE},
          {"=", BondType::DOUBLE},
          {"#", BondType::TRIPLE},
          {":", BondType::AROMATIC},
          {"$", BondType::QUADRUPLE},
          {"->", BondType::DATIVER},
          {"<-", BondType::DATIVEL},
          {"\\", BondType::UNSPECIFIED},
          {"\\\\", BondType::UNSPECIFIED},
          {"/", BondType::UNSPECIFIED},
      }};

  for (auto& bond_info : bonds) {
    auto bond_type = std::find_if(info.begin(), info.end(), [&](auto& entry) {
      return entry.first == bond_info.bond_token;
    });
    if (bond_type != info.end()) {
      mol.addBond(bond_info.begin_atom, bond_info.end_atom, bond_type->second);
    } else if (bond_info.bond_token == "~") {
      auto querybond = std::make_unique<::RDKit::QueryBond>();
      querybond->setQuery(::RDKit::makeBondNullQuery());
    }

    if (bond_info.bond_token[0] == '\\') {
      auto bond =
          mol.getBondBetweenAtoms(bond_info.begin_atom, bond_info.end_atom);
      bond->setBondDir(::RDKit::Bond::BondDir::ENDDOWNRIGHT);
    } else if (bond_info.bond_token == "/") {
      auto bond =
          mol.getBondBetweenAtoms(bond_info.begin_atom, bond_info.end_atom);
      bond->setBondDir(::RDKit::Bond::BondDir::ENDUPRIGHT);
    }

    // std::cout << bond_info.begin_atom << bond_info.bond_token
    //          << bond_info.end_atom << std::endl;
  }
}

void add_rings(::RDKit::RWMol& mol, const std::vector<RingInfo>& rings) {
  std::unordered_map<std::string_view, const RingInfo&> seen_rings;
  std::vector<BondInfo> bonds;

  seen_rings.reserve(rings.size());
  bonds.reserve(rings.size());
  for (auto& ring_info : rings) {
    if (seen_rings.find(ring_info.ring_number) == seen_rings.end()) {
      seen_rings.insert({ring_info.ring_number, ring_info});
      continue;
    }

    std::string_view bond_token = "-";

    auto& ring_start = seen_rings.at(ring_info.ring_number);
    if (!ring_start.bond_token.empty()) {
      bond_token = ring_start.bond_token;
    } else if (!ring_info.bond_token.empty()) {
      bond_token = ring_info.bond_token;
    }
    bonds.push_back({ring_start.atom, ring_info.atom, bond_token});
    seen_rings.erase(ring_info.ring_number);
  }

  add_bonds(mol, bonds);
}
}  // namespace
std::unique_ptr<::RDKit::RWMol> SmilesToMol(std::string_view smiles) {
  // std::cout << "smiles: " << smiles << std::endl;
  auto smiles_ast = parse(smiles);
  auto mol = std::make_unique<::RDKit::RWMol>();
  if (smiles_ast == std::nullopt) {
    return mol;
  }

  add_atoms(*mol, smiles_ast->atoms);
  add_bonds(*mol, smiles_ast->bonds);
  add_rings(*mol, smiles_ast->rings);
  return mol;
}
}  // namespace smiles_parser
