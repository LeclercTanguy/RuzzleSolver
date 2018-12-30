#include <stdio.h>
#include <stdlib.h>
#include "Case.h"

Case CASE_creerCase(void) {
  Case uneCase;
  CASE_fixerLettre(&uneCase,'A');
  CASE_fixerNbPoints(&uneCase,1);
  CASE_fixerBonus(&uneCase,AB);
  //La position est déterminée au moment de l'insertion dans la grille est n'est
  //donc pas initialisée ici
  return uneCase;
}

void CASE_fixerLettre(Case* uneCase, char uneLettre){
  (*uneCase).lettre=uneLettre;
}

void CASE_fixerNbPoints(Case* uneCase, unsigned short points){
  (*uneCase).nbPoints=points;
}

void CASE_fixerBonus(Case* uneCase, Bonus unBonus){
  (*uneCase).bonus=unBonus;
}

void CASE_fixerPosition(Case* uneCase, unsigned short positionX, unsigned short positionY){
  (*uneCase).posX=positionX;
  (*uneCase).posY=positionY;
}

char CASE_obtenirLettre(Case uneCase){
  char laLettre = uneCase.lettre;
  return laLettre;
}

unsigned short CASE_obtenirNbPoints(Case uneCase){
  unsigned short leNBPoints = uneCase.nbPoints;
  return leNBPoints;
}

Bonus CASE_obtenirBonus(Case uneCase){
  Bonus leBonus = uneCase.bonus;
  return leBonus;
}

unsigned short CASE_obtenirPositionX(Case uneCase){
  unsigned short positionX = uneCase.posX;
  return positionX;
}

unsigned short CASE_obtenirPositionY(Case uneCase){
  unsigned short positionY = uneCase.posY;
  return positionY;
}
