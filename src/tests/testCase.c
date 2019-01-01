#include <stdlib.h>
#include <CUnit/Basic.h>
#include "Case.h"

void test_CASE_creerCase(){
  Case uneCase = CASE_creerCase();
  CU_ASSERT_TRUE(((CASE_obtenirLettre(uneCase))=='A')&&(CASE_obtenirNbPoints(uneCase)==1)&& (CASE_obtenirBonus(uneCase)==AB))
}

void test_CASE_Lettre(void){
  Case uneCase;
  char lettre = 'T';
  CASE_fixerLettre(&uneCase, lettre);
  CU_ASSERT_TRUE(CASE_obtenirLettre(uneCase)==lettre);
}

void test_CASE_NbPoints(void){
  Case uneCase;
  unsigned short points = 2;
  CASE_fixerNbPoints(&uneCase, points);
  CU_ASSERT_TRUE(CASE_obtenirNbPoints(uneCase)==points);
}

void test_CASE_Bonus(void){
  Case uneCase;
  Bonus unBonus = LD;
  CASE_fixerBonus(&uneCase, unBonus);
  CU_ASSERT_TRUE(CASE_obtenirBonus(uneCase)==unBonus);
}

void test_CASE_Position(void){
  Case uneCase;
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
  if (
      (NULL == CU_add_test(pSuite, "créer case", test_CASE_creerCase))
      || (NULL == CU_add_test(pSuite, "fixer / obtenir lettre", test_CASE_Lettre))
      || (NULL == CU_add_test(pSuite, "fixer / obtenir nb de points", test_CASE_NbPoints))
      || (NULL == CU_add_test(pSuite,"fixer / obtenir bonus", test_CASE_Bonus))
      || (NULL == CU_add_test(pSuite,"fixer / obtenir position", test_CASE_Position))
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
