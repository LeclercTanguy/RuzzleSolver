#include <stdio.h>
#include <stdlib.h>
#include "Case.h"

Case CASE_creerCase() {
  Case uneCase;
  return uneCase;
}

void CASE_fixerLettre(Case* uneCase, char uneLettre){
  (*uneCase).lettre=uneLettre;
}

void CASE_fixerNBPoints(Case* uneCase, int points){
  (*uneCase).nbPoints=points;
}

void CASE_fixerBonus(Case* uneCase, Bonus unBonus){
  (*uneCase).bonus=unBonus;
}

void CASE_fixerPosition(Case* uneCase, int positionX, int positionY){
  (*uneCase).posX=positionX;
  (*uneCase).posY=positionY;
}

char CASE_obtenirLettre(Case uneCase){
  char laLettre = uneCase.lettre;
  return laLettre;
}

int CASE_obtenirNBPoints(Case uneCase){
  int leNBPoints = uneCase.nbPoints;
  return leNBPoints;
}

Bonus CASE_obtenirBonus(Case uneCase){
  Bonus leBonus = uneCase.bonus;
  return leBonus;
}

//Reste obtenir position 
