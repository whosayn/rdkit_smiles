#pragma once

#include <optional>
#include <string>
#include <vector>

struct AtomChiralityInfo {
    std::string_view chirality_tag;
    std::string_view chirality_class;
    size_t chiral_permutation;
};

struct AtomInfo {
    std::string_view name;
    std::optional<AtomChiralityInfo> chirality;
    size_t isotope;
    size_t explicit_h_count;
    size_t map_number;
    int formal_charge;
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
};

std::vector<MolInfo> parse(std::string_view);

