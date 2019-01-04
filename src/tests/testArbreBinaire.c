#include <stdlib.h>
#include <CUnit/Basic.h>
#include "ArbreBinaire.h"

void test_ArbreVide(void){
    ArbreBinaire a=AB_arbreBinaire();
    CU_ASSERT_TRUE(AB_estVide(a));
}

void test_AB_ajouterRacine(void){
    ArbreBinaire a ,fd=AB_arbreBinaire(),fg=AB_arbreBinaire();
    char element = 'A';
    a = AB_ajouterRacine(fg,fd,&element,sizeof(char));
    CU_ASSERT_TRUE((*(char*)AB_obtenirElement(a)==element) && (AB_obtenirFilsDroit(a)==fd) && (AB_obtenirFilsGauche(a)==fg));
    AB_supprimer(&a);
}

void test_AB_obtenirElement(void) {
  char element = 'A';
  ArbreBinaire a = AB_ajouterRacine(AB_arbreBinaire(),AB_arbreBinaire(),&element,sizeof(element));
  CU_ASSERT_TRUE(*(char*)AB_obtenirElement(a)=element);
  element = 'B';
  AB_fixerElement(a,&element,sizeof(char));
  CU_ASSERT_TRUE(*(char*)AB_obtenirElement(a)=element);
  AB_supprimer(&a);
}

void test_AB_obtenirFilsGauche(void) {
  char element = 'A';
  ArbreBinaire ag = AB_ajouterRacine(AB_arbreBinaire(),AB_arbreBinaire(),&element,sizeof(element));
  element = 'B';
  ArbreBinaire a = AB_ajouterRacine(AB_arbreBinaire(),AB_arbreBinaire(),&element,sizeof(element));
  AB_fixerFilsGauche(a,ag);
  CU_ASSERT_TRUE(AB_obtenirFilsGauche(a)==ag);
  AB_supprimer(&a);
}

void test_AB_obtenirFilsDroit(void) {
  char element = 'A';
  ArbreBinaire ad = AB_ajouterRacine(AB_arbreBinaire(),AB_arbreBinaire(),&element,sizeof(element));
  element = 'B';
  ArbreBinaire a = AB_ajouterRacine(AB_arbreBinaire(),AB_arbreBinaire(),&element,sizeof(element));
  AB_fixerFilsDroit(a,ad);
  CU_ASSERT_TRUE(AB_obtenirFilsDroit(a)==ad);
  AB_supprimer(&a);
}

void test_AB_supprimer(void) {
  char element = 'A';
  ArbreBinaire a = AB_ajouterRacine(AB_arbreBinaire(),AB_arbreBinaire(),&element,sizeof(element));
  CU_ASSERT_FALSE(AB_estVide(a));
  AB_supprimer(&a);
  CU_ASSERT_TRUE(AB_estVide(a));
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
  if ((NULL == CU_add_test(pSuite, "créer un arbre vide", test_ArbreVide))
      || (NULL == CU_add_test(pSuite, "ajouter racine", test_AB_ajouterRacine))
      || (NULL == CU_add_test(pSuite, "obtenir / fixer Element", test_AB_obtenirElement))
      || (NULL == CU_add_test(pSuite, "obtenir / fixer Fils Gauche", test_AB_obtenirFilsGauche))
      || (NULL == CU_add_test(pSuite, "obtenir / fixer Fils Droit", test_AB_obtenirFilsDroit))
      || (NULL == CU_add_test(pSuite, "suppression", test_AB_supprimer))
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
