#ifndef __GRILLE__
#define __GRILLE__
#include "Case.h"

typedef struct {
    Case grille[4][4];
    int caseUtilisee[4][4];
}Grille;

Grille G_grille();
Case G_obtenirCase(Grille ,int,int);
void G_fixerCase(Grille*,Case,int,int);
int G_estUtilisee(Grille,int,int);
void G_debutUtilisation(Grille*,int,int);
void G_finUtilisation(Grille*,int,int);

#endif
