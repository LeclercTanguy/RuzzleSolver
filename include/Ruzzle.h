#ifndef __RUZZLE__
#define __RUZZLE__

#include "ABR.h"
#include "Grille.h"
#include "Dictionnaire.h"
#include "Mot.h"
#include "CasesContigues.h"
#include "Ensemble.h"

typedef struct {
  ABR motsTrouves; //ABR de MotRuzzle
  int nbMots;
} SolutionRuzzle;

typedef struct {
  char* mot;
  unsigned short nbPoints;
} MotRuzzle;

void ruzzleSolver(void);
Grille chaineEnGrille(char* chaine);
void trouverMots(unsigned short posX, unsigned short posY, Dictionnaire dico, Grille* g, Mot* prefixe, CasesContigues* cheminRuzzle, SolutionRuzzle resultat);
void afficherResultat(SolutionRuzzle resultat);
Ens_Ensemble casesAdjacentesNonUtilisees(unsigned short posX, unsigned short posY, Grille g);
void insererMotResultat(CasesContigues cheminRuzzle, SolutionRuzzle* resultat);
int comparerMotRuzzle(MotRuzzle* mot1, MotRuzzle* mot2);

#endif
