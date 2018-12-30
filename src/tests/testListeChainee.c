#include <stdlib.h>
#include <CUnit/Basic.h>
#include "ListeChainee.h"


void test_ListeChainee(void){
  LC_ListeChainee lc = LC_listeVide();
  CU_ASSERT_TRUE(LC_estVide(lc));
}

void test_LC_ajouter(void){
  LC_ListeChainee lc = LC_allouer();
  char lettre ='a';
  LC_ajouter(&lc,&lettre,sizeof(char));
  CU_ASSERT_TRUE((*(char*)LC_obtenirElement(lc)==lettre) && (!LC_estVide(LC_obtenirListeSuivante(lc))));
  LC_supprimer(&lc);
}

void test_LC_obtenir(void){
  LC_ListeChainee lc = LC_allouer();
  LC_ListeChainee temp;
  char lettre ='a';
  temp = lc;
  LC_ajouter(&lc,&lettre,sizeof(char));
  CU_ASSERT_TRUE((*(char*)LC_obtenirElement(lc)==lettre) && (LC_obtenirListeSuivante(lc)==temp));
  LC_supprimer(&lc);
}

void test_LC_fixer(void){
  LC_ListeChainee lc = LC_allouer();
  LC_ListeChainee temp = LC_listeVide();
  char lettre ='a';
  LC_fixerElement(lc,&lettre,sizeof(char));
  LC_fixerListeSuivante(lc,temp);
  CU_ASSERT_TRUE((*(char*)LC_obtenirElement(lc)==lettre) && (LC_obtenirListeSuivante(lc)==temp));
  LC_supprimer(&lc);
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
  if ((NULL == CU_add_test(pSuite, "créer une liste vide", test_ListeChainee))
      || (NULL == CU_add_test(pSuite, "ajouter un élément à la Liste Chaînée", test_LC_ajouter))
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
