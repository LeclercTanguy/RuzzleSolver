#include <stdlib.h>
#include <CUnit/Basic.h>
#include "Mot.h"
#include "ListeChainee.h"
#include "Dictionnaire.h"

void test_Mot_creerMot(void){
  Mot leMot = Mot_creerMot();
  CU_ASSERT_TRUE((Mot_estVide(leMot))&& (Mot_obtenirTaille(leMot) ==0));
}

void test_Mot_ajouterLettre(void){
  Dictionnaire dico = DC_creerDictionnaire();
  Mot leMot;
  DC_ajouterMot(&dico,"MOT");
  Mot_ajouterLettre(&leMot,'T',dico);
  Mot_ajouterLettre(&leMot,'O',dico);
  Mot_ajouterLettre(&leMot,'M',dico);
  Mot_Lettre motLettre = (*(Mot_Lettre*)LC_obtenirElement(leMot.lettres));
  //char lettre1 = 't';
  //char lettre2 = 'o';
  char lettre3 = 'M';
  CU_ASSERT_TRUE(( motLettre.lettre == lettre3) && (Mot_obtenirTaille(leMot)==1));

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
      //|| (NULL == CU_add_test(pSuite, "obtenir élément et liste suivante", test_LC_obtenir))
      //|| (NULL == CU_add_test(pSuite,"fixer élément et liste suivante", test_LC_fixer))
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
