#include <stdlib.h>
#include <assert.h>
#include "ArbreB.h"

ArbreBinaire AB_arbreBinaire(){
    return NULL;
}

int AB_estVide(ArbreBinaire a){
    return a==NULL;
}

ArbreBinaire AB_allouer(void) {
  return (ArbreBinaire)malloc(sizeof(AB_Noeud));
}

ArbreBinaire AB_ajouterRacine(ArbreBinaire fg, ArbreBinaire fd, char element){
    ArbreBinaire a;
    a = (ArbreBinaire)malloc(sizeof(AB_Noeud));
    a->lElement = element;
    a->filsGauche = fg;
    a->filsDroit = fd;
    return a;
}

char AB_obtenirElement(ArbreBinaire a){
    assert (!AB_estVide(a));
<<<<<<< HEAD
    return a->lELement;
=======
    return a->lElement;
>>>>>>> 61b6d2ed5792ced9dd390e5ac2828fff69cbe6a3

}

ArbreBinaire AB_obtenirFilsGauche(ArbreBinaire a){
    assert (!AB_estVide(a));
    return a->filsGauche;
}

ArbreBinaire AB_obtenirFilsDroit(ArbreBinaire a){
    assert (!AB_estVide(a));
    return a->filsDroit;
}

void AB_fixerFilsGauche(ArbreBinaire a, ArbreBinaire ag){
    assert (!AB_estVide(a));
    a->filsGauche=ag;
}

void AB_fixerFilsDroit(ArbreBinaire a, ArbreBinaire ad){
    assert (!AB_estVide(a));
    a->filsDroit=ad;
}

void AB_supprimerRacine(ArbreBinaire a, ArbreBinaire *fg, ArbreBinaire *fd){
    assert (!AB_estVide(a));


}
