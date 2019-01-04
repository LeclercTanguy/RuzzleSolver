#include <CUnit/Basic.h>
#include "tools.h"
#include "ABR.h"

void test_ABR_creer(void){
    ABR a=ABR_creer();
    CU_ASSERT_TRUE(ABR_estVide(a));
}

void test_ABR_inserer_present(void){
    ABR a = ABR_creer();
    int element = 4;
    ABR_inserer(&a,&element,comparerInt);
    CU_ASSERT_TRUE(ABR_estPresent(a,&element,comparerInt));
    ABR_supprimer(&a);
}

void test_ABR_insertion_ordonnee(void){
    ABR a = ABR_creer();
    int un = 1, deux =2 , trois=3;
    ABR_inserer(&a,&deux,comparerInt);
    ABR_inserer(&a,&trois,comparerInt);
    ABR_inserer(&a,&un,comparerInt);
    CU_ASSERT_TRUE(*(int*)AB_obtenirElement(a)==deux && *(int*)AB_obtenirElement(AB_obtenirFilsDroit(a))==un && *(int*)AB_obtenirElement(AB_obtenirFilsGauche(a))==trois)
    ABR_supprimer(&a);
}

//tester l'insertion de trois éléments distincts (ex: 2, 1, 3) et vérifier que le fils gauche est bien plus petit que la racine et que le fils droit est bien plus grand

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
      || (NULL == CU_add_test(pSuite, "insérer / est present", test_ABR_inserer_present))
      || (NULL == CU_add_test(pSuite, "insertion dans le bonne ordre", test_ABR_insertion_ordonnee))
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
