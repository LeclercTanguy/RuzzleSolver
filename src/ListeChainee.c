#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ListeChainee.h"

LC_ListeChainee LC_listeVide(void){
  return(NULL);
}

int LC_estVide(LC_ListeChainee lc){
    return(lc==NULL);
}

void LC_ajouter(LC_ListeChainee lc,char lettre){
  LC_ListeChainee temp;
  temp = (LC_ListeChainee)malloc(sizeof(LC_ListeChainee));
  lc=(LC_ListeChainee)malloc(sizeof(LC_ListeChainee));
  temp = lc;
  LC_fixerElement(lc,lettre);
  LC_fixerListeSuivante(lc,temp);
  free(temp);
}

char LC_obtenirElement(LC_ListeChainee lc){
  return(lc->lettreLC);
}

LC_ListeChainee LC_obtenirListeSuivante(LC_ListeChainee lc){
  return(lc->listeSuivante);
}

void LC_fixerElement(LC_ListeChainee lc,char lettre){
  (lc)->lettreLC=lettre;
}

void LC_fixerListeSuivante(LC_ListeChainee lc,LC_ListeChainee lcSuivante){
  (lc)->listeSuivante=lcSuivante;
}
