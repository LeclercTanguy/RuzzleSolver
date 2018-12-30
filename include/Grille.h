#ifndef __GRILLE__
#define __GRILLE__
#include "Case.h"

typedef struct {
<<<<<<< HEAD
    Case grille[4][4];
    int utilise[4][4];
}Grille;
=======
    Case tab[4][4];
} Grille;
>>>>>>> 4e60cfd484b07f35432c18f1b2de10c59fb500a4


Grille G_grille();
Case G_obtenirCase(Grille ,int,int);
void G_FixerCase(Grille*,Case,int,int);
int G_EstUtilise(Grille,int,int);
void G_debutUtilisation(Grille*,int,int);
void G_finUtilisation(Grille*,int,int);

#endif
