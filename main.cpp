#include <iostream>
#include <string>
#include "smiles_parser.h"


int main() {
    for (auto smiles : {
    "[Fe@OH1-3]1(OC(=O)C(=O)O1)1(OC(=O)C(=O)O1)1OC(=O)C(=O)O1",
    "c1ccccc1",
    "[Pt@OH25]([OH2])([OH2])(C#N)(C#N)(C#N)C#N",
    "[Ta@OH9](F)(F)(F)(N(C)C)(N(C)C)=C1N(CCN1c2c(cc(cc2C)C)C)c3c(cc(cc3C)C)C",
    "[se@OH9](F)(F)(F)(N(C)C)(N(C)C)=C1N(CCN1c2c(cc(cc2C)C)C)c3c(cc(cc3C)C)C",
    //"[se@OH9](F)(F)(F)(N(C)C)(N(C)C)=

    "[Re@OH8](Cl)(Cl)(Cl)([P](c1ccccc1)(c2ccccc2)c3ccccc3)([P](c1ccccc1)(c2ccccc2)c3ccccc3)[N]#CC",
    "]aa[",
    "[aa",
    "[a]",
    "Br",
    "[Br]",
    "Po",
    "[Fe+2]",
    "[Fe+++++++++++++++++++++++++++++++++++++++++++]",
    "ClBrI",
    "C(Cl)BrI",
    "C=CC(CCC)C(C(C)C)CCC",
    "C=CC(CCC)C(C(C([Jk]([e]([Hi]))))C)CCC",
   "kkkkk[Something]" }) {
        parse(smiles);
        std::cout << "###################################\n\n" << std::endl;
    }
    return 0;
}
