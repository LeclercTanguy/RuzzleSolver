#ifndef _Case_
#define _Case_

enum Bonus{LD,LT,MD,MT};

typedef struct Case {char lettre; int nbPoints; Bonus bonus; int posX; int posY};

Case creerCase(void);
void fixerLettre(Case,char);
void fixerNbPoints(Case,int);
void fixerBonus(Case,Bonus);
char obtenirLettre(Case);
int obtenirNbPoints(Case);
Bonus obtenirBonus(Case);
void fixerPosition(Case,int,int);
void obtenirPosition(Case);

#endif
