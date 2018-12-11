#include <stdlib.h>
#include <assert.h>
#include "ListeChainee.h"

LC_ListeChainee LC_listeVide(void){
  return NULL;
}

int LC_estVide(LC_ListeChainee lc){
    return lc==NULL;
}

void LC_ajouter(LC_ListeChainee* lc,char lettre){
  LC_ListeChainee temp = (LC_ListeChainee)malloc(sizeof(LC_Noeud));
  LC_fixerElement(temp,lettre);
  LC_fixerListeSuivante(temp,*lc);
  *lc = temp;
}

char LC_obtenirElement(LC_ListeChainee lc){
  assert (!LC_estVide(lc));
  return lc->lettreLC;
}

LC_ListeChainee LC_obtenirListeSuivante(LC_ListeChainee lc){
  assert (!LC_estVide(lc));
  return lc->listeSuivante;
}

void LC_fixerElement(LC_ListeChainee lc,char lettre){
  assert (!LC_estVide(lc));
  (lc)->lettreLC=lettre;
}

void LC_fixerListeSuivante(LC_ListeChainee lc,LC_ListeChainee lcSuivante){
  assert (!LC_estVide(lc));
  (lc)->listeSuivante=lcSuivante;
}

void LC_supprimerTete(LC_ListeChainee* lc){
  assert (!LC_estVide(*lc));
  LC_ListeChainee temp = *lc;
  *lc = LC_obtenirListeSuivante(*lc);
  free(temp);
}

void LC_supprimer(LC_ListeChainee* lc){
  while (!LC_estVide(*lc)){
    LC_supprimerTete(lc);
  }
}
