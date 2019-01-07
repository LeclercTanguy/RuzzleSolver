/**
 * \file Grille.h
 * \brief Implantation du TAD Grille
 * \author Tanguy LECLERC
 */

#ifndef __GRILLE__
#define __GRILLE__
#include <stdbool.h>
#include "Case.h"

typedef struct {
    Case grille[4][4];
    bool caseUtilisee[4][4];
}Grille;

Grille G_grille();
Case G_obtenirCase(Grille ,int,int);
void G_fixerCase(Grille*,Case,int,int);
bool G_estUtilisee(Grille,int,int);
void G_debutUtilisation(Grille*,int,int);
void G_finUtilisation(Grille*,int,int);

#endif
