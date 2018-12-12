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
    assert (!AB_estVide(a));
    return a->element;

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
    a->filsGauche=ad;
}

void AB_supprimerRacine(ArbreBinaire a, ArbreBinaire *fg, ArbreBinaire *fd){
    assert (!AB_estVide(a));
    

}
