#include "smiles_parser.h"

#include <sstream>
#include "smiles_grammar.hh"
#include "smiles_scanner.h"

namespace smiles_parser {

void SmilesASTBuilder::add_atom(std::string_view atom_name){
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

void SmilesASTBuilder::add_chirality_class(std::string_view chirality_class, std::string_view chiral_permutation) {
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

void SmilesASTBuilder::add_bond(){}
void SmilesASTBuilder::add_ring(){}

MolInfo SmilesASTBuilder::finalize() {
    auto mol = std::exchange(d_mol, {});
    return mol;
}

void parse(std::string_view val) {
    std::istringstream iss(val.data());
    SmilesTokenScanner sc(&iss, val);
    SmilesASTBuilder ast_builder;

    if (auto exit_code = SmilesTokenParser(sc, ast_builder).parse(); exit_code) {
        // pass
    }

    auto mol = ast_builder.finalize();
    int count = 0;
    for (auto& atom : mol.atoms) {
        ++count;
        count += atom.explicit_h_count;
    }

    std::cout << val << ": " << count << std::endl;
}
}
