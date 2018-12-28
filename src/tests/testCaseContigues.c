#include <stdlib.h>
#include <CUnit/Basic.h>
#include "CaseContigue.h"
#include "Case.h"
#include "ListeChainee.h"

void test_CC_creer_casesContigues(){
  CaseContigue desCasesContigues = CC_creer_CasesContigues();
  CU_ASSERT_TRUE(((desCasesContigues.nbCases)==0)&&(LC_estVide(desCasesContigues.listeCases)))
}

void test_CC_ajouterCase(){
  CaseContigue desCasesContigues = CC_creer_CasesContigues();
  // Création d'une case à ajouter
  Case uneCase;
  CASE_fixerLettre(&uneCase, 'A');
  CASE_fixerNbPoints(&uneCase, 2);
  CASE_fixerPosition(&uneCase, 2, 3);
  CASE_fixerBonus(&uneCase, LD);
  // Test
  CC_ajouterCase(&desCasesContigues, uneCase);
  CU_ASSERT_TRUE(CC_nbCaseContigue(desCasesContigues)==1);
}

void test_CC_supprimerCase(){
  CaseContigue desCasesContigues = CC_creer_CasesContigues();
  // Création d'une case à ajouter
  Case uneCase;
  CASE_fixerLettre(&uneCase, 'A');
  CASE_fixerNbPoints(&uneCase, 2);
  CASE_fixerPosition(&uneCase, 2, 3);
  CASE_fixerBonus(&uneCase, LD);
  // Création d'une deuxième case
  Case case2;
  CASE_fixerLettre(&case2, 'B');
  CASE_fixerNbPoints(&case2, 3);
  CASE_fixerPosition(&case2, 1, 2);
  CASE_fixerBonus(&case2, LD);

  CC_ajouterCase(&desCasesContigues, uneCase);
  CC_ajouterCase(&desCasesContigues, case2);
  // Test
  CC_suprimmerCase(&desCasesContigues);
  CU_ASSERT_TRUE(CC_nbCaseContigue(desCasesContigues)==1);
}

void test_CC_nbCaseContigue(){
  CaseContigue desCasesContigues = CC_creer_CasesContigues();
  // Création d'une case à ajouter
  Case uneCase;
  CASE_fixerLettre(&uneCase, 'A');
  CASE_fixerNbPoints(&uneCase, 2);
  CASE_fixerPosition(&uneCase, 2, 3);
  CASE_fixerBonus(&uneCase, LD);
  // Création d'une deuxième case
  Case case2;
  CASE_fixerLettre(&case2, 'B');
  CASE_fixerNbPoints(&case2, 3);
  CASE_fixerPosition(&case2, 1, 2);
  CASE_fixerBonus(&case2, LD);

  CC_ajouterCase(&desCasesContigues, uneCase);
  CC_ajouterCase(&desCasesContigues, case2);

  CU_ASSERT_TRUE(CC_nbCaseContigue(desCasesContigues)==2);
}

//  CaseContigue desCasesContigues = CC_creer_CasesContigues();
  // Création d'une case à ajouter
  //Case uneCase;
  //CASE_fixerLettre(&uneCase, 'A');
  //CASE_fixerNbPoints(&uneCase, 2);
  //CASE_fixerPosition(&uneCase, 2, 3);
  //CASE_fixerBonus(&uneCase, LD);
//  CC_ajouterCase(&desCasesContigues, uneCase);
//}
