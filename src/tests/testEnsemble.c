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
  Ens_ajouter(&ens,&lettre,sizeof(char));
  CU_ASSERT_TRUE((Ens_obtenirNbElements(ens)==1)&&(Ens_estPresent(ens,&lettre,sizeof(char))));
}

void test_Ens_ajouterDUneAutreListe(void){
  Ens_Ensemble ens = Ens_ensemble();
  char lettre = 'b';
  Ens_ajouter(&ens,&lettre,sizeof(char));
  LC_ListeChainee lc = LC_listeVide();
  lettre = 'c';
  LC_ajouter(&lc,&lettre,sizeof(char));
  lettre = 'd';
  LC_ajouter(&lc,&lettre,sizeof(char));
  Ens_ajouterElementsDUneAutreListe(&ens,lc,sizeof(char));
  char b = 'b', c = 'c', d = 'd';
  CU_ASSERT_TRUE((Ens_estPresent(ens,&b,sizeof(char)))&&(Ens_estPresent(ens,&c,sizeof(char)))&&(Ens_estPresent(ens,&d,sizeof(char))));
  LC_supprimer(&lc);
}

void test_Ens_union(void){
  Ens_Ensemble ens1 = Ens_ensemble();
  Ens_Ensemble ens2 = Ens_ensemble();
  Ens_Ensemble ens3 = Ens_ensemble();
  char lettre = 'a';
  Ens_ajouter(&ens1,&lettre,sizeof(char));
  lettre = 'b';
  Ens_ajouter(&ens2,&lettre,sizeof(char));
  ens3 = Ens_union(ens1,ens2,sizeof(char));
  char a = 'a', b = 'b';
  CU_ASSERT_TRUE((Ens_estPresent(ens3,&a,sizeof(char)))&&(Ens_estPresent(ens3,&b,sizeof(char))));

}

void test_Ens_soustraction(void){
  Ens_Ensemble ens1 = Ens_ensemble();
  Ens_Ensemble ens2 = Ens_ensemble();
  Ens_Ensemble ens3 = Ens_ensemble();
  char lettre = 'a';
  Ens_ajouter(&ens1,&lettre,sizeof(char));
  Ens_ajouter(&ens2,&lettre,sizeof(char));
  lettre = 'b';
  Ens_ajouter(&ens1,&lettre,sizeof(char));
  ens3 = Ens_soustraction(ens1,ens2,sizeof(char));
  char a = 'a', b = 'b';
  CU_ASSERT_TRUE((Ens_estPresent(ens3,&b,sizeof(char)))&&(!Ens_estPresent(ens3,&a,sizeof(char))));
}

void test_Ens_intersection(void){
  Ens_Ensemble ens1 = Ens_ensemble();
  Ens_Ensemble ens2 = Ens_ensemble();
  Ens_Ensemble ens3 = Ens_ensemble();
  char lettre = 'a';
  Ens_ajouter(&ens1,&lettre,sizeof(char));
  Ens_ajouter(&ens2,&lettre,sizeof(char));
  lettre = 'b';
  Ens_ajouter(&ens1,&lettre,sizeof(char));
  ens3 = Ens_intersection(ens1,ens2,sizeof(char));
  char a = 'a', b = 'b';
  CU_ASSERT_TRUE((Ens_estPresent(ens3,&a,sizeof(char)))&&(!Ens_estPresent(ens3,&b,sizeof(char))));
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
      || (NULL == CU_add_test(pSuite,"ajouter un autre liste à l'ensemble", test_Ens_ajouterDUneAutreListe))
      || (NULL == CU_add_test(pSuite,"union de deux ensemble", test_Ens_union))
      || (NULL == CU_add_test(pSuite,"intersection de deux ensemble", test_Ens_intersection))
      || (NULL == CU_add_test(pSuite,"soustraction de deux ensemble", test_Ens_soustraction))
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
