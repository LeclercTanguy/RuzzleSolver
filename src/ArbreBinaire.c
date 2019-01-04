#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "ArbreBinaire.h"

ArbreBinaire AB_arbreBinaire(){
    return NULL;
}

bool AB_estVide(ArbreBinaire a){
    return a==NULL;
}

ArbreBinaire AB_allouer(void) {
  ArbreBinaire a = (ArbreBinaire)malloc(sizeof(AB_Noeud));
  AB_fixerElement(a,NULL,0);
  AB_fixerFilsGauche(a,NULL);
  AB_fixerFilsDroit(a,NULL);
  return a;
}

ArbreBinaire AB_ajouterRacine(ArbreBinaire fg, ArbreBinaire fd,Element element,size_t tailleElement){
    ArbreBinaire a = AB_allouer();
    AB_fixerElement(a,element,tailleElement);
    AB_fixerFilsGauche(a,fg);
    AB_fixerFilsDroit(a,fd);
    return a;
}

Element AB_obtenirElement(ArbreBinaire a){
    assert (!AB_estVide(a));
    return a->lElement;
}

void AB_fixerElement(ArbreBinaire a,Element element,size_t tailleElement){
    assert (!AB_estVide(a));
    Element elementRacine;
    if (element!=NULL) {
      elementRacine = AB_obtenirElement(a);
      if (elementRacine==NULL) {
        elementRacine = malloc(tailleElement);
      }
      memcpy(elementRacine,element,tailleElement);
    } else {
      elementRacine = element;
    }
    a->lElement = elementRacine;
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
    if (AB_obtenirElement(*a)!=NULL) {
      free(AB_obtenirElement(*a));
    }
    free(*a);
    *a = NULL;
}

void AB_supprimer(ArbreBinaire* a){
  if (!AB_estVide(*a)) {
    ArbreBinaire fg, fd;
    AB_supprimerRacine(a,&fg,&fd);
    AB_supprimer(&fg);
    AB_supprimer(&fd);
  }
}
