#include <stdlib.h>
#include <string.h>
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

  CU_ASSERT_TRUE(CC_nbCaseContigue(desCasesContigues)==desCasesContigues.nbCases);
}

void test_CC_CaseContigueEnChaine(){
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

  CU_ASSERT_TRUE(strcmp(CC_CaseContigueEnChaine(desCasesContigues),"AB")==0);
}


int main(int argc, char** argv){

  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : Case", NULL, NULL);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests à la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "Créer cases contigues", test_CC_creer_casesContigues))
      || (NULL == CU_add_test(pSuite, "Ajouter case contigue", test_CC_ajouterCase))
      || (NULL == CU_add_test(pSuite,"Supprimer case contigue", test_CC_supprimerCase))
      || (NULL == CU_add_test(pSuite,"Nombre de cases contigues", test_CC_nbCaseContigue))
      || (NULL == CU_add_test(pSuite,"Cases contigues en chaine", test_CC_CaseContigueEnChaine))
      )
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

  /* Lancement des tests */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  printf("\n");
  CU_basic_show_failures(CU_get_failure_list());
  printf("\n\n");

  /* Nettoyage du registre */
  CU_cleanup_registry();
  return CU_get_error();
}
