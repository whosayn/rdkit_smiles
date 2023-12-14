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
   "kkkkk[Something]",


"[Fe@OH1-3]1(OC(=O)C(=O)O1)1(OC(=O)C(=O)O1)1OC(=O)C(=O)O1",
"[Fe@OH2-3]1(OC(=O)C(=O)O1)1(OC(=O)C(=O)O1)1OC(=O)C(=O)O1",
"[Co@OH1+](Cl)(Cl)1([NH2]CC[NH2]1)1[NH2]CC[NH2]1",
"[Co@OH2+](Cl)(Cl)1([NH2]CC[NH2]1)1[NH2]CC[NH2]1",
"[Ni@TB1-3](C#N)(C#N)(C#N)(C#N)C#N",
"[Pt@SP1]1(OC(=O)C2(CCC2)C(=O)O1)([NH3])[NH3]",
"[I@TB1-3](=O)(=O)(=O)(=O)=O",
"[W@TB1-4](=O)(=O)(=O)(=O)=O",
"Cl[Pt@OH1](Cl)(Cl)(Cl)1[NH2][C@@H]2CCCC[C@H]2[NH2]1",
"Cl[Pt@OH1](Cl)(Cl)(Cl)1[NH2][C@H]2CCCC[C@@H]2[NH2]1",
"[Pt@SP1]([As](CC)(CC)CC)([As](CC)(CC)CC)(Cl)Cl",
"[Pd@SP2](O[N+](=O)[O-])(O[N+](=O)[O-])([OH2])[OH2]",
"[Cu@SP2](Cl)(Cl)([OH2])[OH2]",
"[Ni@OH25](Br)(Br)([N]1=CC=CC=C1)([N]1=CC=CC=C1)([N]1=CC=CC=C1)[N]1=CC=CC=C1",
"[Ni@SP1](Cl)(Cl)(=C1N(CCN1C)C)=C1N(CCN1C)C",
"[Pd@SP1](Cl)(Cl)(=C1N(CCN1C)C)=C1N(CCN1C)C",
"[Co@TB17]([P](c1ccccc1)(c2ccccc2)c3ccccc3)([P](c1ccccc1)(c2ccccc2)c3ccccc3)([P](c1ccccc1)(c2ccccc2)c3ccccc3)([N]#N)[H]",
"[Mn@OH12]([OH2])([OH2])([OH2])([OH2])(N=C=S)N=C=S",
"[Cu@SP2]([NH3])([NH3])(N=C=S)N=C=S",
"[Ga@OH2]1(O=C(C)C=C(C)O1)1(O=C(C)C=C(C)O1)1O=C(C)C=C(C)O1",
"[Re@OH12](Cl)([P](C)(C)c1ccccc1)([P](C)(C)c1ccccc1)([P](C)(C)c1ccccc1)(OS(=O)(=O)C(F)(F)F)#N",
"[Zr@OH1](Cl)(Cl)(Cl)(Cl)(O1CCCC1)O1CCCC1",
"[Tc@OH25](Cl)(Cl)([P](C)(C)c1ccccc1)([P](C)(C)c1ccccc1)([P](C)(C)c1ccccc1)N=C=S",
"[Sb@TB7](O)(O)(c1ccccc1)(c1ccccc1)c1ccccc1",
"[Re@OH8](Cl)(Cl)(Cl)([P](c1ccccc1)(c2ccccc2)c3ccccc3)([P](c1ccccc1)(c2ccccc2)c3ccccc3)[N]#CC",
"[Sb@TB7](Br)(Br)(c1ccccc1)(c1ccccc1)c1ccccc1",
"[Mn@OH1](N=[N+]=[N-])(N=[N+]=[N-])1([N]2=c3c(=CC=C2)ccc4c3[N]1=CC=C4)1[N]2=c3c(=CC=C2)ccc4c3[N]1=CC=C4",
"[Pt@SP1]([P](c1ccccc1)(c2ccccc2)c3ccccc3)([P](c1ccccc1)(c2ccccc2)c3ccccc3)1Oc2ccccc2O1",
"[In@OH1](Cl)(Cl)(Cl)([OH2])([OH2])[OH2]",
"[In@TB17](Br)(Br)(Br)([P](C)(C)c1ccccc1)[P](C)(C)c1ccccc1",
"[In@TB17](I)(I)(I)([P](c1ccccc1)(c2ccccc2)C)[P](c1ccccc1)(c2ccccc2)C",
"[Mo@OH1]([P](C1CCCCC1)(C2CCCCC2)C3CCCCC3)([P](C1CCCCC1)(C2CCCCC2)C3CCCCC3)(C#O)(C#O)(C#O)C#O",
"[Mg@OH25](Br)(Br)([O]1CCCC1)([O]1CCCC1)([O]1CCCC1)[O]1CCCC1",
"[Pd@SP2](Cl)(Cl)([P](c1ccccc1)(c2ccccc2)c3ccccc3)=C1N(CCN1c2c(cc(cc2C)C)C)c3c(cc(cc3C)C)C",
"[Pt@OH12](I)(I)(I)(I)([S](C)C)[S](C)C",
"[Pt@SP1]([S](C)C)([S](C)C)(OC(=O)C)OC(=O)C",
"[Sb@TB7](Cl)(Cl)(c1ccccc1)(c1ccccc1)c1ccccc1",
"[Lu@TB7](O1CCCC1)(O1CCCC1)(Cc1ccccc1)(Cc1ccccc1)Cc1ccccc1",
"[Ni@OH1](N=[N+]=[N-])(N=[N+]=[N-])1([N]2=c3c(=CC=C2)ccc4c3[N]1=CC=C4)1[N]2=c3c(=CC=C2)ccc4c3[N]1=CC=C4",
"[Ir@OH4](Cl)(Cl)([P](C)(C)C)([P](C)(C)C)(C#O)[H]",
"[Pd@SP1]1(Oc2ccccc2O1)1[N]2=CC=CC=C2C3=CC=CC=[N]13",
"[Sn@OH27](Cl)(Cl)([N]1=CC=CC=C1)([N]1=CC=CC=C1)(c1ccccc1)c1ccccc1",
"[Fe@TB1]([P](C1CCCCC1)(C2CCCCC2)C3CCCCC3)(C#O)(C#O)(C#O)C#O",
"[Ni@TB15](Cl)(Cl)([P](C)(C)C)([P](C)(C)C)[P](C)(C)C",
"[Pt@SP1]([S](=O)(C)C)([S](=O)(C)C)(c1ccccc1C)c1ccccc1C",
"[Ta@TB1](Cl)(N(C)C)(N(C)C)(N(C)C)N(C)C",
"[Ru@OH26]([P](c1ccccc1)(c2ccccc2)c3ccccc3)([P](c1ccccc1)(c2ccccc2)c3ccccc3)1(O=C(C)O1)(OC(=O)C)C#O",
"[Er@OH1](I)(O1CCCC1)(O1CCCC1)(O1CCCC1)(Cc1ccccc1)Cc1ccccc1",
"[Ir@SP1](Cl)(=C1N(CCN1c2c(cc(cc2C)C)C)c3c(cc(cc3C)C)C)(C#O)C#O",
"[Cr@OH25](Cl)(Cl)(O1CCCC1)(O1CCCC1)(O1CCCC1)C",
"[Pt@SP1](Cl)(Cl)([S](=O)(C)C)=C1N(CCN1c2c(cc(cc2C)C)C)c3c(cc(cc3C)C)C",
"[La@OH1](O1CCCC1)(O1CCCC1)(O1CCCC1)(Cc1ccccc1)(Cc1ccccc1)Cc1ccccc1",
"c1(C[P@OH1](F)(F)(F)(F)F)n(cc[n+]1C)C",
"[Ir@OH1](Cl)([P](C)(C)C)([P](C)(C)C)([P](C)(C)C)([H])[H]",
"[Er@TB7](O1CCCC1)(O1CCCC1)(Cc1ccccc1)(Cc1ccccc1)Cc1ccccc1",
"[Pt@SP1]([S](=O)(C)C)([S](=O)(C)C)(c1ccccc1C)c1ccccc1C",
"[Ru@TB17]([P](c1ccccc1)(c2ccccc2)c3ccccc3)([P](c1ccccc1)(c2ccccc2)c3ccccc3)([P](c1ccccc1)(c2ccccc2)c3ccccc3)(C#O)C#O",
"[In@TB17](Br)(Br)(Br)([P](c1ccccc1)(c2ccccc2)c3ccccc3)[P](c1ccccc1)(c2ccccc2)c3ccccc3",
"[In@TB17](Cl)(Cl)(Cl)([P](c1ccccc1)(c2ccccc2)c3ccccc3)[P](c1ccccc1)(c2ccccc2)c3ccccc3",
"[Pd@SP2]([P](c1ccccc1)(c2ccccc2)c3ccccc3)([P](c1ccccc1)(c2ccccc2)c3ccccc3)(C#N)C#N",
"[Re@OH4](Cl)(Cl)([P](c1ccccc1)(c2ccccc2)c3ccccc3)([P](c1ccccc1)(c2ccccc2)c3ccccc3)(=O)[H]",
"[Rh@OH1](Cl)([P](C)(C)C)([P](C)(C)C)([P](C)(C)C)(c1ccccc1)[H]",
"[Bi@TB1](F)(c1ccccc1)(c1ccccc1)(c1ccccc1)c1ccccc1",
"[Au@SP3](I)([P](C1CCCCC1)(C2CCCCC2)C3CCCCC3)(C(F)(F)F)c1ccccc1",
"[Sb@TB1](Cl)(c1c(c(c(c(c1F)F)F)F)F)(c1c(c(c(c(c1F)F)F)F)F)(c1c(c(c(c(c1F)F)F)F)F)c1c(c(c(c(c1F)F)F)F)F",
"[Fe@TB17](Cl)(Cl)(Cl)([P](C)(C)c1ccccc1)[P](C)(C)c1ccccc1",
"[Cu@SP1]([N]1=CC=CC=C1)(C(F)(F)F)(C(F)(F)F)C(F)(F)F",
"[Pt@OH4](I)(I)([P](C)(C)C)([P](C)(C)C)(C)C",
"[Ni@SP1](Br)1([N]2=CC=CC=C2C3=CC=CC=[N]13)c1ccccc1C",
"[Cr@OH8](I)(Cl)(Cl)(O1CCCC1)(O1CCCC1)O1CCCC1",
"[Fe@OH1](I)(I)([N]1=CC=CC=C1)(C#O)(C#O)C#O",
"[Ti@OH8](N=[N+]=[N-])1([N]2=CC=CC=C2C3=CC=CC=[N]13)(N(C)C)(N(C)C)N(C)C",
"[Ru@TB1]([P](c1ccccc1)(c2ccccc2)c3ccccc3)(C#O)(C#O)(C#O)C#O",
"[Sb@TB7](F)(OS(=O)(=O)C(F)(F)F)(c1ccccc1)(c1ccccc1)c1ccccc1",
"[Mg@OH27](Cl)(Cl)([OH]CC)([OH]CC)(O1CCCC1)O1CCCC1",
"[Co@OH8](N=[N+]=[N-])(N=[N+]=[N-])(N=[N+]=[N-])([N]1=CC=CC=C1)1[NH2]CC[NH2]1",
"[Rh@TB17]([P](c1ccccc1)(c2ccccc2)C)([P](c1ccccc1)(c2ccccc2)C)([P](c1ccccc1)(c2ccccc2)C)(C(F)(F)F)C#O",
"[Ru@OH1](Cl)(Cl)([OH2])(C#O)(C#O)C#O",
"[Pd@SP1](I)(Cl)([P](C1CCCCC1)(C2CCCCC2)C3CCCCC3)C#O",
"[Tl@OH8](OS(=O)(=O)C(F)(F)F)(OS(=O)(=O)C(F)(F)F)(OS(=O)(=O)C(F)(F)F)([OH2])([OH2])[OH2]",
"[Ni@SP2]([P](C)(C)C)([P](C)(C)C)(N=C=S)N=C=S",
"[Re@OH3](Br)(C#O)(C#O)(C#O)(C#O)=C1N(CCN1c2c(cc(cc2C)C)C)c3c(cc(cc3C)C)C",
"[W@OH12]([P](c1ccccc1)(c2ccccc2)C)([P](c1ccccc1)(c2ccccc2)C)([P](c1ccccc1)(c2ccccc2)C)([P](c1ccccc1)(c2ccccc2)C)([N]#N)[N]#N",
"[Co@TB10](Cl)([P](C)(C)C)([P](C)(C)C)([P](C)(C)C)c1c(c(c(c(c1F)F)F)F)F",
"[Cu@OH25](OS(=O)(=O)C(F)(F)F)(OS(=O)(=O)C(F)(F)F)1([NH2]CC[NH2]1)1[NH2]CC[NH2]1",
"[W@OH8](Cl)(Cl)(Cl)([P](c1ccccc1)(c2ccccc2)C)([P](c1ccccc1)(c2ccccc2)C)N(C)C",
"[Ir@TB13](Cl)(=C1N(CCN1c2c(cc(cc2C)C)C)c3c(cc(cc3C)C)C)(=C1N(CCN1c2c(cc(cc2C)C)C)c3c(cc(cc3C)C)C)([H])[H]",
"[Sb@TB7](Br)(Br)(CC)(CC)CC",
"[Co@OH8]([P](C)(C)C)([P](C)(C)C)([P](C)(C)C)(N=C=S)(C)C",
"[Pt@SP1](Cl)(Cl)(=C1N(CCN1C)C)=C1N(CCN1C)C",
"[Ni@OH25](F)(F)([N]1=CC=CC=C1)([N]1=CC=CC=C1)([N]1=CC=CC=C1)[N]1=CC=CC=C1",
"[Mg@OH25](OC(=O)C(F)(F)F)(OC(=O)C(F)(F)F)([OH2])([OH2])([OH2])[OH2]",
"[Ta@OH9](F)(F)(F)(N(C)C)(N(C)C)=C1N(CCN1c2c(cc(cc2C)C)C)c3c(cc(cc3C)C)C",
"[Re@OH1](Cl)(Cl)(Cl)(Cl)1[N]2=c3c(=CC=C2)ccc4c3[N]1=CC=C4",
"[U@TB17](N([Si](C)(C)C)[Si](C)(C)C)(N([Si](C)(C)C)[Si](C)(C)C)(N([Si](C)(C)C)[Si](C)(C)C)(N=C=S)N=C=S",
"[Sn@OH12](OS(=O)(=O)C(F)(F)F)(OS(=O)(=O)C(F)(F)F)1([N]2=CC=CC=C2C3=CC=CC=[N]13)(C)C",
"[Ta@OH1]1(O=C(C)C=C(C)O1)(OCC)(OCC)(OCC)OCC",
"[Re@OH1](Br)([P](c1ccccc1)(c2ccccc2)c3ccccc3)([P](c1ccccc1)(c2ccccc2)c3ccccc3)(C#O)(C#O)C#O",
"[Sn@OH27](Cl)(Cl)([N]1=CN(N)C=N1)([N]1=CN(N)C=N1)(C)C",
"[Pt@OH25]([OH2])([OH2])(C#N)(C#N)(C#N)C#N",
"[Mn@OH1](Cl)(Cl)([OH2])([OH2])([OH2])[OH2]",
"[W@OH1](C#[O])(C#[O])(C#[O])(C#[O])(C#[O])C#[O]",
"[Mo@OH1](C#[O])(C#[O])(C#[O])(C#[O])(C#[O])C#[O]",
"[Hf@OH1](Cl)(Cl)(Cl)(Cl)([O]1CCCC1)[O]1CCCC1",
"[Cu@SP2](Cl)(Cl)([NH3])[NH3]",
    }) {
        parse(smiles);
    }
    return 0;
}
