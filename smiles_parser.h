#pragma once

#include <string>
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
};

struct BondInfo {
    size_t begin_atom;
    size_t end_atom;
    std::string_view bond_token;
};

// idk what info is needed yet
struct RingInfo {
    std::string_view token;
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
        void add_explicit_h(size_t count=1);
        void add_isotope_num(size_t isotope_num);
        void add_chirality_tag(std::string_view chirality_tag);
        void add_chirality_class(std::string_view chirality_class, std::string_view chiral_permutation = {});
        void add_atom_charge(int atom_charge);
        void add_atom_map_number(size_t atom_map_number);


        void add_bond();
        void add_ring();
        MolInfo finalize();
   private:
        MolInfo d_mol;
};

void parse(std::string_view);
}
