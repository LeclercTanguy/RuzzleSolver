#include <stdlib.h>
#include <string.h>
#include <CUnit/Basic.h>
#include "CasesContigues.h"
#include "Case.h"
#include "ListeChainee.h"

void test_CC_creer_casesContigues(){
  CasesContigues desCasesContigues = CC_creer_CasesContigues();
  CU_ASSERT_TRUE((CC_nbCasesContigues(desCasesContigues)==0)&&(LC_estVide(desCasesContigues.listeCases)))
}

void test_CC_ajouterCase(){
  CasesContigues desCasesContigues = CC_creer_CasesContigues();
  // Création d'une case à ajouter
  Case uneCase;
  CASE_fixerLettre(&uneCase, 'A');
  CASE_fixerNbPoints(&uneCase, 2);
  CASE_fixerPosition(&uneCase, 2, 3);
  CASE_fixerBonus(&uneCase, LD);
  // Test
  CC_ajouterCase(&desCasesContigues, uneCase);
  CU_ASSERT_TRUE(CC_nbCasesContigues(desCasesContigues)==1);
}

void test_CC_supprimerCase(){
  CasesContigues desCasesContigues = CC_creer_CasesContigues();
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
  CC_suprimerCase(&desCasesContigues);
  CU_ASSERT_TRUE(CC_nbCasesContigues(desCasesContigues)==1);
}

void test_CC_nbCasesContigues(){
  CasesContigues desCasesContigues = CC_creer_CasesContigues();
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

  CU_ASSERT_TRUE(CC_nbCasesContigues(desCasesContigues)==2);
}

void test_CC_CasesContiguesEnChaine(){
  CasesContigues desCasesContigues = CC_creer_CasesContigues();
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

  char* maChaine=CC_CasesContiguesEnChaine(desCasesContigues);
  CU_ASSERT_TRUE(strcmp(maChaine,"AB")==0);
}

void test_CC_totalPointsCasesContigues(){
  CasesContigues desCasesContigues = CC_creer_CasesContigues();
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

  unsigned int totalPoints = CC_totalPointsCasesContigues(desCasesContigues);
  CU_ASSERT_TRUE(totalPoints==5);
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
  if ((NULL == CU_add_test(pSuite, "Créer cases contiguës", test_CC_creer_casesContigues))
      || (NULL == CU_add_test(pSuite, "Ajouter cases contiguës", test_CC_ajouterCase))
      || (NULL == CU_add_test(pSuite,"Supprimer cases contiguës", test_CC_supprimerCase))
      || (NULL == CU_add_test(pSuite,"Nombre de cases contiguës", test_CC_nbCasesContigues))
      || (NULL == CU_add_test(pSuite,"Cases contiguës en chaîne", test_CC_CasesContiguesEnChaine))
      || (NULL == CU_add_test(pSuite,"Nombre total de points des cases contiguës",test_CC_totalPointsCasesContigues))
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
