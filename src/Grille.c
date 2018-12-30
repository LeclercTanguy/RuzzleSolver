#include <stdio.h>
#include <stdlib.h>
#include "Grille.h"
#include "Case.h"

Grille G_grille(void){
    Grille grilleVide;
    int i,j;
    for (i = 0; i < 4; i++) {
        for ( j = 0; j < 4; j++) {
            Case caseVide;
            CASE_fixerPosition(&caseVide,i+1,j+1);
            grilleVide.grille[i][j] = caseVide;
            grilleVide.utilisee[i][j]= 0;
        }

    }
    return grilleVide;
}

Case G_obtenirCase(Grille laGrille,int posx,int posy){
    return laGrille.grille[posx-1][posy-1];
}

void G_fixerCase(Grille* laGrille,Case uneCase,int posx,int posy){
    (*laGrille).grille[posx-1][posy-1] = uneCase;
}

void G_debutUtilisation(Grille* laGrille,int posx,int posy){
    (*laGrille).utilisee[posx-1][posy-1] = 1;

}

void G_finUtilisation(Grille* laGrille,int posx,int posy){
    (*laGrille).utilisee[posx-1][posy-1] = 0;

}

int G_estUtilisee(Grille laGrille,int posx,int posy){
    return laGrille.utilisee[posx-1][posy-1];
}
