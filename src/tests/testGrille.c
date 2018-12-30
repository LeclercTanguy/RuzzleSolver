#include <stdlib.h>
#include <CUnit/Basic.h>
#include "Grille.h"
#include "Case.h"

void test_G_modifierCase(void){
    Case uneCase;
    char lettre = 'T';
    Grille uneGrille=G_grille();
    uneCase=G_obtenirCase(uneGrille,2,3);
    CASE_fixerLettre(&uneCase, lettre);
    G_fixerCase(&uneGrille,uneCase,2,3);
    CU_ASSERT_TRUE(
    (CASE_obtenirLettre(G_obtenirCase(uneGrille,2,3))==lettre) &&
    (CASE_obtenirPositionX(G_obtenirCase(uneGrille,2,3))==2) &&
    (CASE_obtenirPositionY(G_obtenirCase(uneGrille,2,3))==3)
    );
}

void test_G_debutUtilisation(void){
    Grille uneGrille=G_grille();
    CU_ASSERT_FALSE(G_estUtilisee(uneGrille,1,1));
    G_debutUtilisation(&uneGrille,1,1);
    CU_ASSERT_TRUE(G_estUtilisee(uneGrille,1,1));
}

void test_G_finUtilisation(void){
    Grille uneGrille=G_grille();
    G_debutUtilisation(&uneGrille,1,1);
    CU_ASSERT_TRUE(G_estUtilisee(uneGrille,1,1));
    G_finUtilisation(&uneGrille,1,1);
    CU_ASSERT_FALSE(G_estUtilisee(uneGrille,1,1));
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
  if ((NULL == CU_add_test(pSuite, "modifier une case de la grille", test_G_modifierCase))
      || (NULL == CU_add_test(pSuite, "Début utilisation / Est Utilisée", test_G_debutUtilisation))
      || (NULL == CU_add_test(pSuite,"fin utilisation", test_G_finUtilisation))

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
