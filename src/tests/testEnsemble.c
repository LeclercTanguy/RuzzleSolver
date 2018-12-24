#include <stdlib.h>
#include <CUnit/Basic.h>
#include "Ensemble.h"
#include "ListeChainee.h"
#define TRUE 1
#define FALSE 0

void test_Ens_ensemble(void){
  Ens_Ensemble ens= Ens_ensemble();
  CU_ASSERT_TRUE((LC_estVide(ens.lesElements))&&(ens.nbElements==0));
}

void test_Ens_obtenir(void){
  Ens_Ensemble ens = Ens_ensemble();
  CU_ASSERT_TRUE((Ens_obtenirLesElements(ens)==NULL)&&(Ens_obtenirNbElements(ens)==0));
}

void test_Ens_ajouterEtestPresent(void){
  Ens_Ensemble ens = Ens_ensemble();
  char lettre = 'a';
  Ens_ajouter(&ens,lettre);
  CU_ASSERT_TRUE(Ens_obtenirNbElements(ens)==1);
}

int main(int argc, char** argv){

  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : Ensemble", NULL, NULL);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests à la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "créer un Ensemble", test_Ens_ensemble))
      || (NULL == CU_add_test(pSuite, "obtenir les éléments et le nombre d'éléments", test_Ens_obtenir))
      || (NULL == CU_add_test(pSuite, "ajouter une lettre à un ensemble", test_Ens_ajouterEtestPresent))
    //  || (NULL == CU_add_test(pSuite,"fixer élément et liste suivante", test_LC_fixer))
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
