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
  Mot_ajouterLettre(&leMot,'M',dico);
  Mot_ajouterLettre(&leMot,'O',dico);
  Mot_ajouterLettre(&leMot,'T',dico);
  Mot_Lettre motLettre = (*(Mot_Lettre*)LC_obtenirElement(leMot.lettres));
  char lettre1 = 'T';
  char lettre2 = 'O';
  char lettre3 = 'M';
  CU_ASSERT_TRUE(( motLettre.lettre == lettre1 ) && (Mot_obtenirTaille(leMot)==3));
  motLettre = (*(Mot_Lettre*)LC_obtenirElement(LC_obtenirListeSuivante(leMot.lettres)));
  CU_ASSERT_TRUE( motLettre.lettre == lettre2 );
  motLettre = (*(Mot_Lettre*)LC_obtenirElement(LC_obtenirListeSuivante(LC_obtenirListeSuivante(leMot.lettres))));
  CU_ASSERT_TRUE( motLettre.lettre == lettre3 );
}

void test_Mot_retirerLettre(void){
  Dictionnaire dico = DC_creerDictionnaire();
  Mot leMot = Mot_creerMot();
  DC_ajouterMot(&dico,"MOT");
  Mot_ajouterLettre(&leMot,'M',dico);
  Mot_Lettre motLettre = (*(Mot_Lettre*)LC_obtenirElement(leMot.lettres));
  CU_ASSERT_TRUE(motLettre.lettre ='M');
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
  printf("%s",motEnChaine);
  CU_ASSERT_TRUE(strcmp(motEnChaine,"MOT"));
}

void test_Mot_chaineEnMot(void){
  char* laChaine = "MOT";
  Dictionnaire dico = DC_creerDictionnaire();
  DC_ajouterMot(&dico,"MOT");
  Mot leMot = Mot_chaineEnMot(dico,laChaine);
  Mot_Lettre motLettre = (*(Mot_Lettre*)LC_obtenirElement(leMot.lettres));
  char lettre1 = 'T';
  char lettre2 = 'O';
  char lettre3 = 'M';
  CU_ASSERT_TRUE(( motLettre.lettre == lettre1 ) && (Mot_obtenirTaille(leMot)==3));
  motLettre = (*(Mot_Lettre*)LC_obtenirElement(LC_obtenirListeSuivante(leMot.lettres)));
  CU_ASSERT_TRUE( motLettre.lettre == lettre2 );
  motLettre = (*(Mot_Lettre*)LC_obtenirElement(LC_obtenirListeSuivante(LC_obtenirListeSuivante(leMot.lettres))));
  CU_ASSERT_TRUE( motLettre.lettre == lettre3 );
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
  if ((NULL == CU_add_test(pSuite, "créer un Mot Vide", test_Mot_creerMot))
      || (NULL == CU_add_test(pSuite, "ajouter une lettre au Mot", test_Mot_ajouterLettre))
      || (NULL == CU_add_test(pSuite, "retirer la dernière lettre ajouté", test_Mot_retirerLettre))
      || (NULL == CU_add_test(pSuite,"supprimer le Mot", test_Mot_supprimerMot))
      || (NULL == CU_add_test(pSuite,"transformer une chaine en un Mot", test_Mot_chaineEnMot))
      || (NULL == CU_add_test(pSuite,"transformer un Mot en Chaine de caractère", test_Mot_motEnChaine))
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
