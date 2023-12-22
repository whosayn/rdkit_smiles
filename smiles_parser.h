#pragma once

#include <optional>
#include <string>
#include <variant>
#include <vector>

namespace smiles_parser {

struct AtomChiralityInfo {
  std::string_view chirality_tag;
  std::string_view chirality_class;
  std::string_view chiral_permutation;
};

struct AtomInfo {
  std::string_view name;
  std::optional<AtomChiralityInfo> chirality;
  size_t isotope = 0;
  size_t explicit_h_count = 0;
  size_t map_number = 0;
  int formal_charge = 0;
  size_t atomic_number = 0;
};

struct BondInfo {
  std::string_view token;
};

// idk what info is needed yet
struct RingInfo {
  std::string_view token;
};

struct BranchInfo {
    std::string_view token;
};

struct SepInfo {
};

struct MolInfo {
  std::vector<AtomInfo> atoms;
  std::vector<BondInfo> bonds;
  std::vector<RingInfo> rings;

  MolInfo() = default;
  MolInfo(const MolInfo&) = delete;
  MolInfo& operator=(const MolInfo&) = delete;
  MolInfo(MolInfo&&) = default;
  MolInfo& operator=(MolInfo&&) = default;
};

class SmilesASTBuilder {
 public:
  void add_atom(std::string_view atom_name);
  void add_explicit_h(size_t count = 1);
  void add_isotope_num(size_t isotope_num);
  void add_chirality_tag(std::string_view chirality_tag);
  void add_chirality_class(std::string_view chirality_class,
                           std::string_view chiral_permutation = {});
  void add_atom_charge(int atom_charge);
  void add_atom_map_number(size_t atom_map_number);

  void add_branch_info(std::string_view branch_token);

  void add_sep_info();

  void add_bond(std::string_view bond_token);

  void add_ring_info(std::string_view ring_number, bool use_as_is = false);
  MolInfo finalize();

 private:
  std::vector<std::variant<SepInfo, BranchInfo, AtomInfo, BondInfo, RingInfo>> d_events;
};

std::optional<MolInfo> parse(std::string_view val);
}  // namespace smiles_parser
