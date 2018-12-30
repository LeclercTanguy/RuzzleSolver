#include "Ruzzle.h"
#include "ABR.h"
#include "Grille.h"
#include "Dictionnaire.h"
#include "Mot.h"
#include "CasesContigues.h"
#include "Ensemble.h"
#include "tools.h"

Grille chaineEnGrille(char* chaine) {
  return G_grille();
}

void trouverMots(unsigned short posX, unsigned short posY, Dictionnaire dico, Grille* g, Mot* prefixe, CasesContigues* cheminRuzzle, SolutionRuzzle resultat) {

}

void afficherResultat(SolutionRuzzle resultat) {

}

Ens_Ensemble casesAdjacentesNonUtilisees(unsigned short posX, unsigned short posY, Grille g) {
  return Ens_ensemble();
}

void insererMotResultat(CasesContigues cheminRuzzle, SolutionRuzzle* resultat) {

}

//VRAI si mot1<mot2, FAUX sinon
int comparerMotRuzzle(MotRuzzle* mot1, MotRuzzle* mot2) {
  return 0;
}

//ruzzleSolver
int main(int argc, char *argv[]) {
  return 0;
}
