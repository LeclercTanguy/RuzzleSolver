#include <stdlib.h>
#include "ArbreB.h"

ArbreBinaire AB_arbreBinaire(){
    return NULL;
}

int AB_estVide(ArbreBinaire a){
    return a==NULL;
}


ArbreBinaire AB_ajouterRacine(ArbreBinaire fg, ArbreBinaire fd, char element){
    ArbreBinaire a;
    a = (ArbreBinaire)malloc(sizeof(AB_Noeud));
    a->lELement = element;
    a->filsGauche = fg;
    a->filsDroit = fd;
    return a;
}

char AB_obtenirElement(ArbreBinaire a){
    char element ;
    element = a->lELement;
    return element;

}

ArbreBinaire AB_obtenirFilsGauche(ArbreBinaire a){
    return a->filsGauche;
}

ArbreBinaire AB_obtenirFilsDroit(ArbreBinaire a){
    return a->filsDroit;
}
