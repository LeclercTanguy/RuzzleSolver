#ifndef __GRILLE__
#define __GRILLE__
#include "Case.h"

typedef struct {
    Case tab[4][4];
} Grille;


Grille G_grille();
Case G_obtenirCase(Grille ,int,int);
void G_FixerCase(Grille,int,int);
int G_EstUtilise(Grille,int,int);
void G_debutUtilisation(Grille,int,int);
void G_finUtilisation(Grille,int,int);

#endif
