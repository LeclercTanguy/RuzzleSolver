#include <CUnit/Basic.h>
#include "Ruzzle.h"

void test_RZ_chaineEnBonus() {
  Bonus leBonus;
  int err;
  err = (RZ_chaineEnBonus("  ",&leBonus));
  CU_ASSERT_TRUE(!err && (leBonus==AB));
  err = (RZ_chaineEnBonus("LD",&leBonus));
  CU_ASSERT_TRUE(!err && (leBonus==LD));
  err = (RZ_chaineEnBonus("LT",&leBonus));
  CU_ASSERT_TRUE(!err && (leBonus==LT));
  err = (RZ_chaineEnBonus("MD",&leBonus));
  CU_ASSERT_TRUE(!err && (leBonus==MD));
  err = (RZ_chaineEnBonus("MT",&leBonus));
  CU_ASSERT_TRUE(!err && (leBonus==MT));
  err = (RZ_chaineEnBonus("TW",&leBonus));
  CU_ASSERT_TRUE(!err && (leBonus==MT));
  err = (RZ_chaineEnBonus("TEST",&leBonus));
  CU_ASSERT_TRUE(err);
  err = (RZ_chaineEnBonus("L",&leBonus));
  CU_ASSERT_TRUE(err);
  err = (RZ_chaineEnBonus("RZ",&leBonus));
  CU_ASSERT_TRUE(err);
}

void test_RZ_chaineEnGrille() {
  int err;
  Grille grilleRuzzle;
  err = RZ_chaineEnGrille("TEST",&grilleRuzzle);
  CU_ASSERT_TRUE(err);
  err = RZ_chaineEnGrille("XXLDR1  A1  S1MTE1LTN1  C3LTE1  U1  R1  I1  L2MDS1  O1MDP3  S1  ",&grilleRuzzle);
  CU_ASSERT_TRUE(err);
  err = RZ_chaineEnGrille("T1DLR1  A1  S1TWE1TLN1  C3TLE1  U1  R1  I1  L2DWS1  O1DWP3  S1  ",&grilleRuzzle);
  CU_ASSERT_FALSE(err); //compatibilité notation appli Ruzzle
  err = RZ_chaineEnGrille("T1LDR1  A1  S1MTE1LTN1  C3LTE1  U1  R1  I1  L2MDS1  O1MDP3  S1  ",&grilleRuzzle);
  CU_ASSERT_FALSE(err);
  Case caseTest = G_obtenirCase(grilleRuzzle,3,2);
  CU_ASSERT_TRUE(CASE_obtenirLettre(caseTest)=='C');
  CU_ASSERT_TRUE(CASE_obtenirNbPoints(caseTest)==3);
  CU_ASSERT_TRUE(CASE_obtenirBonus(caseTest)==LT);
}

void test_RZ_casesAdjacentesNonUtilisees(void){
    Grille g=G_grille();
    G_debutUtilisation(&g,2,2);
    G_debutUtilisation(&g,2,3);
    G_debutUtilisation(&g,3,2);
    G_debutUtilisation(&g,3,3);
    Ens_Ensemble ensemble1=RZ_casesAdjacentesNonUtilisees(2,2,g);
    Ens_Ensemble ensemble2=RZ_casesAdjacentesNonUtilisees(2,3,g);
    Ens_Ensemble ensemble3=RZ_casesAdjacentesNonUtilisees(3,2,g);
    Ens_Ensemble ensemble4=RZ_casesAdjacentesNonUtilisees(3,3,g);
    Case CoinHautGauche= G_obtenirCase(g,1,1);
    Case CoinHautDroit= G_obtenirCase(g,1,4);
    Case CoinBasGauche= G_obtenirCase(g,4,1);
    Case CoinBasDroite= G_obtenirCase(g,4,4);
    Case Caseutilisee1= G_obtenirCase(g,2,2);
    Case Caseutilisee2= G_obtenirCase(g,2,3);
    Case Caseutilisee3= G_obtenirCase(g,3,2);
    Case Caseutilisee4= G_obtenirCase(g,3,3);
    CU_ASSERT_TRUE(Ens_estPresent(ensemble1,&CoinHautGauche,sizeof(Case)));
    CU_ASSERT_TRUE(Ens_estPresent(ensemble2,&CoinHautDroit,sizeof(Case)));
    CU_ASSERT_TRUE(Ens_estPresent(ensemble3,&CoinBasGauche,sizeof(Case)));
    CU_ASSERT_TRUE(Ens_estPresent(ensemble4,&CoinBasDroite,sizeof(Case)));
    CU_ASSERT_FALSE(Ens_estPresent(ensemble1,&Caseutilisee1,sizeof(Case)));
    CU_ASSERT_FALSE(Ens_estPresent(ensemble2,&Caseutilisee2,sizeof(Case)));
    CU_ASSERT_FALSE(Ens_estPresent(ensemble3,&Caseutilisee3,sizeof(Case)));
    CU_ASSERT_FALSE(Ens_estPresent(ensemble4,&Caseutilisee4,sizeof(Case)));

}
// Test de tout les coins et que les cases utilisees ne sont pas dans l'ensemble non utilisees

int main(int argc, char* argv[]){

  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : Ruzzle", NULL, NULL);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests à la suite de tests boite noire */
  if (
    (NULL == CU_add_test(pSuite, "convertir une chaîne en Bonus",test_RZ_chaineEnBonus)) ||
    (NULL == CU_add_test(pSuite, "convertir une chaîne en Grille",test_RZ_chaineEnGrille)) ||
    (NULL == CU_add_test(pSuite, "cases adjactentes non utilisees ",test_RZ_casesAdjacentesNonUtilisees))
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
