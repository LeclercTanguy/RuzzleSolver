#include <stdlib.h>
#include <assert.h>
#include "ListeChainee.h"
#define TRUE 1
#define FALSE 0

LC_ListeChainee LC_listeVide(void){
  return NULL;
}

LC_ListeChainee LC_allouer(void) {
  return (LC_ListeChainee)malloc(sizeof(LC_Noeud));
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

int LC_estPresent(LC_ListeChainee lc,char lettre){
  if (LC_estVide(lc)){
    return FALSE;
  }else{
    if (LC_obtenirElement(lc)==lettre){
      return TRUE;
    }else{
      return LC_estPresent(LC_obtenirListeSuivante(lc),lettre);
    }
  }
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
