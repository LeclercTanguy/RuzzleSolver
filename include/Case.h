#ifndef _CASE_
#define _CASE_

typedef enum {AB,LD,LT,MD,MT} Bonus;

typedef struct {
  char lettre;
  unsigned short nbPoints;
  Bonus bonus;
  unsigned short posX;
  unsigned short posY;
} Case;

void CASE_fixerLettre(Case*,char uneLettre);
void CASE_fixerNbPoints(Case*,unsigned short points);
void CASE_fixerBonus(Case*,Bonus);
char CASE_obtenirLettre(Case);
unsigned short CASE_obtenirNbPoints(Case);
Bonus CASE_obtenirBonus(Case);
void CASE_fixerPosition(Case*,unsigned short positionX,unsigned short positionY);
unsigned short CASE_obtenirPositionX(Case);
unsigned short CASE_obtenirPositionY(Case);

#endif
