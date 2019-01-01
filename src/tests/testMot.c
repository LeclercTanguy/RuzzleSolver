#include <stdlib.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "Mot.h"
#include "ListeChainee.h"
#include "Dictionnaire.h"

void test_Mot_creerMot(void){
  Mot leMot = Mot_creerMot();
  CU_ASSERT_TRUE((Mot_estVide(leMot))&& (Mot_obtenirTaille(leMot)==0));
}

void test_Mot_ajouterLettre(void){
  Dictionnaire dico = DC_creerDictionnaire();
  Mot leMot = Mot_creerMot();
  DC_ajouterMot(&dico,"MOT");
  char lettre1 = 'M';
  char lettre2 = 'O';
  char lettre3 = 'T';
  Mot_ajouterLettre(&leMot,lettre1,dico);
  Mot_ajouterLettre(&leMot,lettre2,dico);
  Mot_ajouterLettre(&leMot,lettre3,dico);
  CU_ASSERT_TRUE((Mot_obtenirDerniereLettre(leMot)==lettre3) && (Mot_obtenirTaille(leMot)==3));
  Mot_retirerLettre(&leMot);
  CU_ASSERT_TRUE(Mot_obtenirDerniereLettre(leMot)==lettre2);
  Mot_retirerLettre(&leMot);
  CU_ASSERT_TRUE(Mot_obtenirDerniereLettre(leMot)==lettre1);
}

void test_Mot_retirerLettre(void){
  Dictionnaire dico = DC_creerDictionnaire();
  Mot leMot = Mot_creerMot();
  DC_ajouterMot(&dico,"MOT");
  Mot_ajouterLettre(&leMot,'M',dico);
  CU_ASSERT_TRUE(Mot_obtenirDerniereLettre(leMot)=='M');
  Mot_retirerLettre(&leMot);
  CU_ASSERT_TRUE(Mot_estVide(leMot));
}

void test_Mot_supprimerMot(void){
  Dictionnaire dico = DC_creerDictionnaire();
  Mot leMot = Mot_creerMot();
  DC_ajouterMot(&dico,"MOT");
  Mot_ajouterLettre(&leMot,'M',dico);
  Mot_ajouterLettre(&leMot,'O',dico);
  Mot_ajouterLettre(&leMot,'T',dico);
  CU_ASSERT_FALSE(Mot_estVide(leMot));
  Mot_supprimerMot(&leMot);
  CU_ASSERT_TRUE(Mot_estVide(leMot));
}

  void test_Mot_motEnChaine(void){
  Dictionnaire dico = DC_creerDictionnaire();
  Mot leMot = Mot_creerMot();
  DC_ajouterMot(&dico,"MOT");
  Mot_ajouterLettre(&leMot,'M',dico);
  Mot_ajouterLettre(&leMot,'O',dico);
  Mot_ajouterLettre(&leMot,'T',dico);
  char* motEnChaine = Mot_motEnChaine(leMot);
  CU_ASSERT_TRUE(strcmp(motEnChaine,"MOT"));
}

void test_Mot_chaineEnMot(void){
  char* laChaine = "MOT";
  Dictionnaire dico = DC_creerDictionnaire();
  DC_ajouterMot(&dico,laChaine);
  Mot leMot = Mot_chaineEnMot(dico,laChaine);
  char lettre1 = 'M';
  char lettre2 = 'O';
  char lettre3 = 'T';
  CU_ASSERT_TRUE((Mot_obtenirDerniereLettre(leMot)==lettre3) && (Mot_obtenirTaille(leMot)==3));
  Mot_retirerLettre(&leMot);
  CU_ASSERT_TRUE(Mot_obtenirDerniereLettre(leMot)==lettre2);
  Mot_retirerLettre(&leMot);
  CU_ASSERT_TRUE(Mot_obtenirDerniereLettre(leMot)==lettre1);
}


int main(int argc, char** argv){

  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : Mot", NULL, NULL);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests à la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "créer un Mot Vide", test_Mot_creerMot))
      || (NULL == CU_add_test(pSuite, "ajouter une lettre au Mot", test_Mot_ajouterLettre))
      || (NULL == CU_add_test(pSuite, "retirer la dernière lettre ajoutée", test_Mot_retirerLettre))
      || (NULL == CU_add_test(pSuite,"supprimer le Mot", test_Mot_supprimerMot))
      || (NULL == CU_add_test(pSuite,"transformer une chaîne en un Mot", test_Mot_chaineEnMot))
      || (NULL == CU_add_test(pSuite,"transformer un Mot en chaîne de caractère", test_Mot_motEnChaine))
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
