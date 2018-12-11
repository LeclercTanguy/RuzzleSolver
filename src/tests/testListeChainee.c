#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <CUnit/Basic.h>
#include "ListeChainee.h"
#define TRUE 1
#define FALSE 0

void test_ListeChainee(void){
  LC_ListeChainee lc = LC_listeVide();
  CU_ASSERT_TRUE(LC_estVide(lc));
}

void test_LC_ajouter(void){
  LC_ListeChainee lc = LC_listeVide();
  char lettre ='a';
  LC_ajouter(lc,lettre);
  lc=(LC_ListeChainee)malloc(sizeof(LC_ListeChainee));
  printf("%c",LC_obtenirElement(lc));
  CU_ASSERT_TRUE(!LC_estVide(lc));
  free(lc);
}

void test_LC_obtenir(void){
  LC_ListeChainee lc = LC_listeVide();
  LC_ListeChainee temp;
  char lettre ='a';
  temp=(LC_ListeChainee)malloc(sizeof(LC_ListeChainee));
  temp = lc;
  lc=(LC_ListeChainee)malloc(sizeof(LC_ListeChainee));
  LC_ajouter(lc,lettre);
  CU_ASSERT_TRUE((LC_obtenirElement(lc)==lettre) && (LC_obtenirListeSuivante(lc)==temp));
  free(lc);
}

void test_LC_fixer(void){
  LC_ListeChainee lc = LC_listeVide();
  LC_ListeChainee temp;
  temp=(LC_ListeChainee)malloc(sizeof(LC_ListeChainee));
  lc = (LC_ListeChainee)malloc(sizeof(LC_ListeChainee));
  char lettre ='a';
  LC_fixerElement(lc,lettre);
  LC_fixerListeSuivante(lc,temp);
  CU_ASSERT_TRUE((LC_obtenirElement(lc)==lettre) && (LC_obtenirListeSuivante(lc)==temp));
}

int main(int argc, char** argv){

  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : Liste Chainee", NULL, NULL);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests à la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "créer une liste Vide", test_ListeChainee))
      || (NULL == CU_add_test(pSuite, "ajouter un élément à la Liste Chainée", test_LC_ajouter))
      || (NULL == CU_add_test(pSuite, "obtenir élément et liste suivante", test_LC_obtenir))
      || (NULL == CU_add_test(pSuite,"fixer élément et liste suivante", test_LC_fixer))
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
