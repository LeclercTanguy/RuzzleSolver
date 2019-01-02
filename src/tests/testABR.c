#include <stdlib.h>
#include <CUnit/Basic.h>
#include "ABR.h"


int comparerint (Element a,Element b){
    int *c = (void*) a;
    int *d = (void*) b;
    if (*c== *d){
        return 0;
    }
    else if (*c<*d){
        return -1;
    }
    else {
        return 1;
    }
}

void test_comparerint(void){
    int a = 1;
    int b = 2;
    CU_ASSERT_TRUE(comparerint(&a,&b)==-1);
}


void test_ABR_creer(void){
    ABR a=ABR_creer();
    CU_ASSERT_TRUE(ABR_estVide(a));
}

void test_ABR_inserer_present(void){
    ABR a = ABR_creer();
    int element = 4,racine = 3;
    a = ABR_allouer();
    ABR_fixerElement(a,&racine);
    ABR_inserer(&a,&element,comparerint);
    CU_ASSERT_TRUE(ABR_estPresent(a,&element,comparerint)==true);
}




int main(int argc, char** argv){

  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : Arbre binaire", NULL, NULL);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests à la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "créer un ABR vide", test_ABR_creer))
      || (NULL == CU_add_test(pSuite, "inserer est present", test_comparerint))

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
