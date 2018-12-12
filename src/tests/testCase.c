#include <stdlib.h>
#include <CUnit/Basic.h>
#include "Case.h"

void test_CASE_creerCase(void){

  //CU_ASSERT_TRUE();
}

void test_CASE_fixerLettre(void){
  Case uneCase = CASE_creerCase();
  char lettre = 'A';
  CASE_fixerLettre(&uneCase, lettre);
  CU_ASSERT_TRUE(CASE_obtenirLettre(uneCase)==lettre);
}

void test_CASE_fixerNBPoints(void){
  Case uneCase = CASE_creerCase();
  unsigned short points = 2;
  CASE_fixerNBPoints(&uneCase, points);
  CU_ASSERT_TRUE(CASE_obtenirNBPoints(uneCase)==points);
}

void test_CASE_fixerBonus(void){
  Case uneCase = CASE_creerCase();
  Bonus unBonus = LD;
  CASE_fixerBonus(&uneCase, unBonus);
  CU_ASSERT_TRUE(CASE_obtenirBonus(uneCase)==unBonus);
}

void test_CASE_fixerPosition(void){
  Case uneCase = CASE_creerCase();
  unsigned short positionX = 2;
  unsigned short positionY = 3;
  CASE_fixerPosition(&uneCase, positionX, positionY);
  CU_ASSERT_TRUE((CASE_obtenirPositionX(uneCase)==positionX)&&(CASE_obtenirPositionY(uneCase)==positionY));
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
  if ((NULL == CU_add_test(pSuite, "creer case", test_CASE_creerCase))
      || (NULL == CU_add_test(pSuite, "fixer lettre", test_CASE_fixerLettre))
      || (NULL == CU_add_test(pSuite, "fixer nb de points", test_CASE_fixerNBPoints))
      || (NULL == CU_add_test(pSuite,"fixer bonus", test_CASE_fixerBonus))
      || (NULL == CU_add_test(pSuite,"fixer position", test_CASE_fixerPosition))
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
