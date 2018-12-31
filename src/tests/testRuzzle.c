#include <CUnit/Basic.h>
#include "Ruzzle.h"

void test_RZ_chaineEnBonus() {
  Bonus leBonus;
  int err;
  err = (RZ_chaineEnBonus("  ",&leBonus));
  CU_ASSERT_TRUE(!err && (leBonus==AB));
  err = (RZ_chaineEnBonus("LD",&leBonus));
  CU_ASSERT_TRUE(!err && (leBonus==LD));
  err = (RZ_chaineEnBonus("LT",&leBonus));
  CU_ASSERT_TRUE(!err && (leBonus==LT));
  err = (RZ_chaineEnBonus("MD",&leBonus));
  CU_ASSERT_TRUE(!err && (leBonus==MD));
  err = (RZ_chaineEnBonus("MT",&leBonus));
  CU_ASSERT_TRUE(!err && (leBonus==MT));
  err = (RZ_chaineEnBonus("TEST",&leBonus));
  CU_ASSERT_TRUE(err);
  err = (RZ_chaineEnBonus("1",&leBonus));
  CU_ASSERT_TRUE(err);
  err = (RZ_chaineEnBonus("RZ",&leBonus));
  CU_ASSERT_TRUE(err);
}

void test_RZ_chaineEnGrille() {
}

int main(int argc, char* argv[]){

  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : Ruzzle", NULL, NULL);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests à la suite de tests boite noire */
  if (
    (NULL == CU_add_test(pSuite, "convertir une chaîne en Bonus",test_RZ_chaineEnBonus)) ||
    (NULL == CU_add_test(pSuite, "convertir une chaîne en Grille",test_RZ_chaineEnGrille))
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
