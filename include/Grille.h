#ifndef _Grille_
#define _Grille_
#include "Case.h"

typedef struct Grille {
    Case tab[4][4];
}


G_grille G_grille();
Case G_obtenirCase(Grille,int,int);
void G_FixerCase(Grille,int,int);
int G_EstUtilise(Grille,int,int);
void G_debutUtilisation(Grille,int,int);
void G_finUtilisation(Grille,int,int);
