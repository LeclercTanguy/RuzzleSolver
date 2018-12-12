#ifndef _CASE_
#define _CASE_

typedef enum {LD,LT,MD,MT,AB} Bonus;

typedef struct Case {
  char lettre;
  unsigned short nbPoints;
  Bonus bonus;
  unsigned short posX;
  unsigned short posY;
}Case;

Case CASE_creerCase(void);
void CASE_fixerLettre(Case*,char uneLettre);
void CASE_fixerNBPoints(Case*,unsigned short points);
void CASE_fixerBonus(Case*,Bonus);
char CASE_obtenirLettre(Case);
unsigned short CASE_obtenirNBPoints(Case);
Bonus CASE_obtenirBonus(Case);
void CASE_fixerPosition(Case*,unsigned short positionX,unsigned short positionY);
unsigned short CASE_obtenirPositionX(Case);
unsigned short CASE_obtenirPositionY(Case);

#endif
