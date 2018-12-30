#include <stdio.h>
#include <stdlib.h>
#include "Grille.h"
#include "Case.h"

Grille G_grille(void){
    Case Casevide;
    CASE_fixerLettre(&Casevide,'Z');
    CASE_fixerBonus(&Casevide,LD);
    CASE_fixerPosition(&Casevide,0,0);
    CASE_fixerNbPoints(&Casevide,0);
    Grille grille_vide;
    int i,j;
    for (i = 1; i < 4; i++) {
        for ( j = 1; j < 4; j++) {
            grille_vide.grille[i][j] = Casevide;
            grille_vide.utilise[i][j]= 0;
        }

    }
    return grille_vide;
}

Case G_obtenirCase(Grille laGrille,int posx,int posy){
    return laGrille.grille[posx][posy];
}

void G_FixerCase(Grille* laGrille,Case uneCase,int posx,int posy){
    (*laGrille).grille[posx][posy] = uneCase;
}

void G_debutUtilisation(Grille* laGrille,int posx,int posy){
    (*laGrille).utilise[posx][posy] = 1;

}

void G_finUtilisation(Grille* laGrille,int posx,int posy){
    (*laGrille).utilise[posx][posy] = 0;

}

int G_EstUtilise(Grille laGrille,int posx,int posy){
    return laGrille.utilise[posx][posy];
}
