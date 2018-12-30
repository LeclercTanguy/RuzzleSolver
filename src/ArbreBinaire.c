#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "ArbreBinaire.h"

ArbreBinaire AB_arbreBinaire(){
    return NULL;
}

int AB_estVide(ArbreBinaire a){
    return a==NULL;
}

ArbreBinaire AB_allouer(void) {
  return (ArbreBinaire)malloc(sizeof(AB_Noeud));
}

ArbreBinaire AB_ajouterRacine(ArbreBinaire fg, ArbreBinaire fd,Element element,size_t tailleElement){
    ArbreBinaire a = AB_allouer();
    Element elementRacine = malloc(tailleElement);
    memcpy(elementRacine,element,tailleElement);
    a->lElement = elementRacine;
    a->filsGauche = fg;
    a->filsDroit = fd;
    return a;
}

Element AB_obtenirElement(ArbreBinaire a){
    assert (!AB_estVide(a));
    return a->lElement;
}

void AB_fixerElement(ArbreBinaire a,Element element){
    assert (!AB_estVide(a));
    a->lElement=element;
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

void AB_supprimerRacine(ArbreBinaire* a, ArbreBinaire* fg, ArbreBinaire* fd){
    assert (!AB_estVide(*a));
    *fg = AB_obtenirFilsGauche(*a);
    *fd = AB_obtenirFilsDroit(*a);
    free(AB_obtenirElement(*a));
    free(*a);
    *a = NULL;
}

void AB_supprimer(ArbreBinaire* a){
  ArbreBinaire fg, fd;
  if (!AB_estVide(*a)) {
    AB_supprimerRacine(a,&fg,&fd);
    AB_supprimer(&fg);
    AB_supprimer(&fd);
  }
}
