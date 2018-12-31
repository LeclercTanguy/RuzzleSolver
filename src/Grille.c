#include <assert.h>
#include "Grille.h"
#include "Case.h"

Grille G_grille(void){
  Grille grilleVide;
  Case caseVide = CASE_creerCase();
  for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
          G_fixerCase(&grilleVide,caseVide,i+1,j+1);
          G_finUtilisation(&grilleVide,i+1,j+1);
      }
  }
  return grilleVide;
}

Case G_obtenirCase(Grille laGrille,int posX,int posY){
  assert((posX>=1) && (posX<=4));
  assert((posY>=1) && (posY<=4));
  return laGrille.grille[posX-1][posY-1];
}

void G_fixerCase(Grille* laGrille,Case uneCase,int posX,int posY){
  assert((posX>=1) && (posX<=4));
  assert((posY>=1) && (posY<=4));
  CASE_fixerPosition(&uneCase,posX,posY);
  (*laGrille).grille[posX-1][posY-1] = uneCase;
}

void G_debutUtilisation(Grille* laGrille,int posX,int posY){
  assert((posX>=1) && (posX<=4));
  assert((posY>=1) && (posY<=4));
  (*laGrille).caseUtilisee[posX-1][posY-1] = true;
}

void G_finUtilisation(Grille* laGrille,int posX,int posY){
  assert((posX>=1) && (posX<=4));
  assert((posY>=1) && (posY<=4));
  (*laGrille).caseUtilisee[posX-1][posY-1] = false;
}

bool G_estUtilisee(Grille laGrille,int posX,int posY){
  assert((posX>=1) && (posX<=4));
  assert((posY>=1) && (posY<=4));
  return laGrille.caseUtilisee[posX-1][posY-1];
}
