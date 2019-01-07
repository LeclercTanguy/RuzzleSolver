#include <stdio.h>
#include "Ruzzle.h"
#include "Mot.h"
#include "tools.h"

int main(int argc, char *argv[]) {
  if (argc==3) {
    char* grilleRuzzle = argv[1];
    char* nomFichierDico = argv[2];
    Grille g;
    int errGrille = RZ_chaineEnGrille(grilleRuzzle,&g);
    if (!errGrille) {
      Dictionnaire dico = DC_creerDictionnaire();
      int errDico = DC_charger(nomFichierDico,&dico);
      if (!errDico) {
        SolutionRuzzle resultat = RZ_creerSolutionRuzzle();
        Mot initMot;
        CasesContigues initChemin;
        for(int y = 1;y<=4;y++){
          for(int x = 1;x<=4;x++){
            char lettre = CASE_obtenirLettre(G_obtenirCase(g,x,y));
            initMot = Mot_chaineEnMot(dico,caractereEnChaine(lettre));
            initChemin = CC_creer_CasesContigues();
            CC_ajouterCase(&initChemin,G_obtenirCase(g,x,y));
            RZ_trouverMots(x,y,dico,&g,&initMot,&initChemin,&resultat);
          }
        }
        RZ_afficherResultat(resultat);
        return 0;
      } else {
        return errDico;
      }
    //gestion des erreurs
    } else if (errGrille==-1) {
      printf("Erreur : la chaîne décrivant la grille Ruzzle n'a pas la longueur attendue, vérifiez votre saisie\n");
      infosGrille();
      return errGrille;
    } else {
      printf("Erreur : la chaîne décrivant la grille Ruzzle n'a pas le format attendu, vérifiez votre saisie\n");
      infosGrille();
      return errGrille;
    }
  } else {
    printf("Erreur : il n'y a pas le bon nombre d'arguments pour utiliser ruzzleSolver\n");
    printf("ruzzleSolver nécessite dans l'ordre :\n");
    printf("  1) une chaîne décrivant la grille de Ruzzle\n");
    infosGrille();
    printf("  2) le nom du fichier contenant le dictionnaire sérialisé\n");
    return 1;
  }
}
