#include <CUnit/Basic.h>
#include "tools.h"
#include "Dictionnaire.h"
#include "Mot.h"

void test_DC_creerDictionnaire() {
  Dictionnaire dico = DC_creerDictionnaire();
  CU_ASSERT_TRUE(DC_estVide(dico));
}

void test_DC_supprimer(){
  Dictionnaire dico = DC_creerDictionnaire();
  DC_ajouterMot (&dico,"TEST");
  DC_supprimer(&dico);
  CU_ASSERT_TRUE(DC_estVide(dico));
}

void test_DC_ajoutMot() {
  Dictionnaire dico = DC_creerDictionnaire();
  DC_ajouterMot (&dico,"DICO");
  DC_ajouterMot (&dico,"TESTER");
  CU_ASSERT_TRUE(DC_estUnPrefixe(dico,"TEST"));
  CU_ASSERT_TRUE(DC_estUnPrefixe(dico,"DICO"));
  CU_ASSERT_FALSE(DC_estUnPrefixe(dico,"TESTEUR"));
  DC_supprimer(&dico);
}

void test_DC_estUnMotComplet(){
  Dictionnaire dico = DC_creerDictionnaire();
  DC_ajouterMot (&dico,"TEST");
  CU_ASSERT_TRUE(DC_estUnMotComplet(Mot_chaineEnMot(dico,"TEST")));
  CU_ASSERT_FALSE(DC_estUnMotComplet(Mot_chaineEnMot(dico,"TES")));
  DC_supprimer(&dico);
}

void test_DC_sauvegarder() {
  Dictionnaire dico = DC_creerDictionnaire();
  int err;
  DC_ajouterMot (&dico,"LA");
  DC_ajouterMot (&dico,"SAUVEGARDE");
  DC_ajouterMot (&dico,"FONCTIONNE");
  DC_ajouterMot (&dico,"ET");
  DC_ajouterMot (&dico,"FONCTIONNERA");
  err = DC_sauvegarder(dico,"tests/dico.dat");
  CU_ASSERT_FALSE(err);
  DC_supprimer(&dico);
}

void test_DC_charger() {
  Dictionnaire dico = DC_creerDictionnaire();
  int errCharger = DC_charger("tests/dico.dat",&dico); //généré au test précédent
  CU_ASSERT_FALSE(errCharger);
  int errSauvegarder = DC_sauvegarder(dico,"tests/dico2.dat");
  CU_ASSERT_FALSE(errSauvegarder);
  CU_ASSERT_TRUE(comparer2Fichiers("tests/dico.dat","tests/dico2.dat"));
  DC_supprimer(&dico);
}

void test_DC_obtenirLettresSuivantes() {
  Dictionnaire dico = DC_creerDictionnaire();
  DC_ajouterMot (&dico,"LA");
  DC_ajouterMot (&dico,"LE");
  DC_ajouterMot (&dico,"LIT");
  Ens_Ensemble lettresSuivantes = DC_obtenirLettresSuivantes(Mot_chaineEnMot(dico,"L"));
  char a='A', e='E', i='I';
  CU_ASSERT_TRUE(
    Ens_estPresent(lettresSuivantes,&a,sizeof(char)) &&
    Ens_estPresent(lettresSuivantes,&e,sizeof(char)) && Ens_estPresent(lettresSuivantes,&i,sizeof(char))
  );
  CU_ASSERT_TRUE(Ens_obtenirNbElements(lettresSuivantes)==3);
  DC_supprimer(&dico);
}

void test_DC_supprimerMot(){
  Dictionnaire dico = DC_creerDictionnaire();
  DC_ajouterMot (&dico,"TEST");
  DC_ajouterMot (&dico,"TESTER");
  Mot motTester = Mot_chaineEnMot(dico,"TESTER");
  DC_supprimerMot (&dico,&motTester);
  CU_ASSERT_TRUE(Mot_estVide(motTester));
  CU_ASSERT_TRUE(DC_estUnPrefixe(dico,"TEST"));
  CU_ASSERT_FALSE(DC_estUnPrefixe(dico,"TESTER"));
  DC_ajouterMot (&dico,"TESTER");
  Mot motTest = Mot_chaineEnMot(dico,"TEST");
  DC_supprimerMot (&dico,&motTest);
  CU_ASSERT_FALSE(DC_estUnMotComplet(Mot_chaineEnMot(dico,"TEST")));
  DC_supprimer(&dico);
}

int main(int argc, char** argv){

  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : Dictionnaire", NULL, NULL);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests à la suite de tests boite noire */
  if (
    (NULL == CU_add_test(pSuite, "dictionnaire vide", test_DC_creerDictionnaire)) ||
    (NULL == CU_add_test(pSuite, "suppression du dictionnaire",test_DC_supprimer)) ||
    (NULL == CU_add_test(pSuite, "ajout d'un mot", test_DC_ajoutMot)) ||
    (NULL == CU_add_test(pSuite, "suppression d'un mot",test_DC_supprimerMot)) ||
    (NULL == CU_add_test(pSuite, "obtenirLettresSuivantes",test_DC_obtenirLettresSuivantes)) ||
    (NULL == CU_add_test(pSuite, "estUnMotComplet",test_DC_estUnMotComplet)) ||
    (NULL == CU_add_test(pSuite, "sauvegarde sans erreur", test_DC_sauvegarder)) ||
    (NULL == CU_add_test(pSuite, "chargement",test_DC_charger))
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
