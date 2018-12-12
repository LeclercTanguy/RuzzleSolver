#include "ArbreB.h"

ArbreBinaire AB_arbreBinaire(){
    return *Noeud;
}

int AB_estVide(ArbreBinaire a){
    return a==Null;
}


ArbreBinaire AB_ajouterRacine(ArbreBinaire fg, ArbreBinaire fd, char element){
    ArbreBinaire a;
    a = (ArbreBinaire)malloc(sizeof(ArbreBinaire));
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
