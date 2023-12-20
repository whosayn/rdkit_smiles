#include "smiles_parser.h"

#include <charconv>
#include <optional>
#include <sstream>
#include <unordered_map>

#include "smiles_grammar.hh"
#include "smiles_scanner.h"

namespace smiles_parser {

void SmilesASTBuilder::add_atom(std::string_view atom_name) {
  d_mol.atoms.push_back({atom_name});
}

void SmilesASTBuilder::add_explicit_h(size_t count) {
  d_mol.atoms.back().explicit_h_count += count;
}

void SmilesASTBuilder::add_isotope_num(size_t isotope_num) {
  d_mol.atoms.back().isotope = isotope_num;
}

void SmilesASTBuilder::add_chirality_tag(std::string_view chirality_tag) {
  if (!d_mol.atoms.back().chirality) {
    d_mol.atoms.back().chirality = AtomChiralityInfo{};
  }

  auto& chirality_info = *d_mol.atoms.back().chirality;
  chirality_info.chirality_tag = chirality_tag;
}

void SmilesASTBuilder::add_chirality_class(
    std::string_view chirality_class, std::string_view chiral_permutation) {
  if (!d_mol.atoms.back().chirality) {
    d_mol.atoms.back().chirality = AtomChiralityInfo{};
  }

  auto& chirality_info = *d_mol.atoms.back().chirality;
  chirality_info.chirality_class = chirality_class;
  chirality_info.chiral_permutation = chiral_permutation;
}

void SmilesASTBuilder::add_atom_charge(int atom_charge) {
  d_mol.atoms.back().formal_charge = atom_charge;
}

void SmilesASTBuilder::add_atom_map_number(size_t atom_map_number) {
  d_mol.atoms.back().map_number = atom_map_number;
}

size_t SmilesASTBuilder::get_num_atoms() { return d_mol.atoms.size(); }

void SmilesASTBuilder::add_bond(size_t atom1, size_t atom2,
                                std::string_view bond_token) {
  d_mol.bonds.push_back({atom1 - 1, atom2 - 1, bond_token});
}

// NOTE: Add test about this example i.e what bond determines the bond type of
// the closing bond
// >>> Chem.MolToSmiles(Chem.MolFromSmiles("c-1ccc=1"))
// 'C1=CC=C1'
// >>> Chem.MolToSmiles(Chem.MolFromSmiles("c=1ccc-1"))
// 'C1=C=CC=1'
void SmilesASTBuilder::add_ring_info(std::string_view ring_number,
                                     std::string_view bond_token,
                                     bool use_as_is) {
  auto ring_atom = get_num_atoms() - 1;
  // NOTE: if the ring number consists of multiple numbers, we should count
  // each number as a separate ring. This doesn't apply to '10' or when the
  // token follows a '%' token
  if (use_as_is) {
    d_mol.rings.push_back({ring_number, ring_atom, bond_token});
    return;
  }

  // Checking for 10
  if (ring_number.size() == 2 && ring_number == "10") {
    d_mol.rings.push_back({ring_number, ring_atom, bond_token});
    return;
  }

  for (size_t i = 0; i < ring_number.size(); ++i) {
    d_mol.rings.push_back({ring_number.substr(i, 1), ring_atom, bond_token});
  }
}

MolInfo SmilesASTBuilder::finalize() {
  auto mol = std::exchange(d_mol, {});
  std::sort(mol.bonds.begin(), mol.bonds.end(),
            [](auto& b1, auto& b2) { return b1.end_atom < b2.end_atom; });
  return mol;
}

static size_t get_atomic_number(std::string_view& atom_symbol) {
  static constexpr std::array<std::pair<std::string_view, size_t>, 138> info{{
      {"*", 0},     {"H", 1},     {"He", 2},    {"Li", 3},    {"Be", 4},
      {"B", 5},     {"b", 5},     {"C", 6},     {"c", 6},     {"N", 7},
      {"n", 7},     {"O", 8},     {"o", 8},     {"F", 9},     {"Ne", 10},
      {"Na", 11},   {"Mg", 12},   {"Al", 13},   {"Si", 14},   {"si", 14},
      {"P", 15},    {"p", 15},    {"S", 16},    {"s", 16},    {"Cl", 17},
      {"Ar", 18},   {"K", 19},    {"Ca", 20},   {"Sc", 21},   {"Ti", 22},
      {"V", 23},    {"Cr", 24},   {"Mn", 25},   {"Fe", 26},   {"Co", 27},
      {"Ni", 28},   {"Cu", 29},   {"Zn", 30},   {"Ga", 31},   {"Ge", 32},
      {"As", 33},   {"as", 33},   {"Se", 34},   {"se", 34},   {"Br", 35},
      {"Kr", 36},   {"Rb", 37},   {"Sr", 38},   {"Y", 39},    {"Zr", 40},
      {"Nb", 41},   {"Mo", 42},   {"Tc", 43},   {"Ru", 44},   {"Rh", 45},
      {"Pd", 46},   {"Ag", 47},   {"Cd", 48},   {"In", 49},   {"Sn", 50},
      {"Sb", 51},   {"Te", 52},   {"te", 52},   {"I", 53},    {"Xe", 54},
      {"Cs", 55},   {"Ba", 56},   {"La", 57},   {"Ce", 58},   {"Pr", 59},
      {"Nd", 60},   {"Pm", 61},   {"Sm", 62},   {"Eu", 63},   {"Gd", 64},
      {"Tb", 65},   {"Dy", 66},   {"Ho", 67},   {"Er", 68},   {"Tm", 69},
      {"Yb", 70},   {"Lu", 71},   {"Hf", 72},   {"Ta", 73},   {"W", 74},
      {"Re", 75},   {"Os", 76},   {"Ir", 77},   {"Pt", 78},   {"Au", 79},
      {"Hg", 80},   {"Tl", 81},   {"Pb", 82},   {"Bi", 83},   {"Po", 84},
      {"At", 85},   {"Rn", 86},   {"Fr", 87},   {"Ra", 88},   {"Ac", 89},
      {"Th", 90},   {"Pa", 91},   {"U", 92},    {"Np", 93},   {"Pu", 94},
      {"Am", 95},   {"Cm", 96},   {"Bk", 97},   {"Cf", 98},   {"Es", 99},
      {"Fm", 100},  {"Md", 101},  {"No", 102},  {"Lr", 103},  {"Rf", 104},
      {"Db", 105},  {"Sg", 106},  {"Bh", 107},  {"Hs", 108},  {"Mt", 109},
      {"Ds", 110},  {"Rg", 111},  {"Cn", 112},  {"Nh", 113},  {"Fl", 114},
      {"Mc", 115},  {"Lv", 116},  {"Ts", 117},  {"Og", 118},  {"Uun", 110},
      {"Uuu", 111}, {"Uub", 112}, {"Uut", 113}, {"Uuq", 114}, {"Uup", 115},
      {"Uuh", 116}, {"Uus", 117}, {"Uuo", 118},
  }};

  if (atom_symbol[0] == '\'') {
    atom_symbol = atom_symbol.substr(1, atom_symbol.size() - 2);
  }

  auto entry = std::find_if(info.begin(), info.end(), [&](auto target) {
    return target.first == atom_symbol;
  });
  return entry == info.end() ? std::numeric_limits<size_t>::max()
                             : entry->second;
}

[[nodiscard]] static size_t stoi(std::string_view s) {
  size_t result;
  std::from_chars(s.data(), s.data() + s.size(), result);
  return result;
}

static void validate_atoms(std::vector<AtomInfo>& atoms) {
  for (auto& atom : atoms) {
    if (std::isdigit(atom.name[0])) {
      atom.atomic_number = stoi(atom.name);
    } else {
      atom.atomic_number = get_atomic_number(atom.name);
      if (atom.atomic_number == std::numeric_limits<size_t>::max()) {
        std::cout << "bad atom: " << atom.name << std::endl;
      }
    }
  }
}

static void validate_rings(const std::vector<RingInfo>& rings) {
  std::unordered_map<std::string_view, const RingInfo&> seen_rings;
  seen_rings.reserve(rings.size());
  for (auto& ring_info : rings) {
    if (stoi(ring_info.ring_number) == 0) {
      std::cerr << "'" << ring_info.ring_number << "'"
                << " is not a valid ring number" << std::endl;
      continue;
    }

    if (seen_rings.find(ring_info.ring_number) == seen_rings.end()) {
      seen_rings.insert({ring_info.ring_number, ring_info});
      continue;
    }

    auto& ring_start = seen_rings.at(ring_info.ring_number);
    if (ring_start.bond_token.empty() || ring_info.bond_token.empty()) {
      // pass
    } else if (ring_start.bond_token != ring_info.bond_token) {
      std::cerr << "ring '" << ring_info.ring_number
                << "' has different closing bond types" << std::endl;
    }

    seen_rings.erase(ring_info.ring_number);
  }

  if (seen_rings.size() != 0) {
    std::cerr << "The following rings are unclosed: " << std::endl;
    for (auto& [ring_number, unused] : seen_rings) {
      std::cerr << ring_number << std::endl;
    }
  }
}

std::optional<MolInfo> parse(std::string_view val) {
  std::istringstream iss(val.data());
  SmilesTokenScanner sc(&iss, val);
  SmilesASTBuilder ast_builder;

  if (auto exit_code = SmilesTokenParser(sc, ast_builder).parse(); exit_code) {
    // pass
    return std::nullopt;
  }

  auto mol = ast_builder.finalize();
  validate_atoms(mol.atoms);
  validate_rings(mol.rings);
  return std::make_optional<MolInfo>(std::move(mol));
}
}  // namespace smiles_parser
