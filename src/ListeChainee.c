#include <stdio.h>
#include <stdlib.h>
#include "ListeChainee.h"

LC_ListeChainee listeVide(void){
  return(NULL);
}

int estVide(LC_ListeChainee lc){
    return(lc==NULL);
}

void ajouter(LC_ListeChainee *lc,char lettre){
  LC_ListeChainee temp=(LC_ListeChainee)malloc(sizeof(LC_Noeud));
  if (temp!=NULL){
    temp->lettreLC=lettre;
    temp->listeSuivante = *lc;
    *lc=temp;
  }
}

char obtenirElement(LC_ListeChainee *lc){
  if(!estVide(*lc)){
    return((*lc)->lettreLC);
  }
}

LC_ListeChainee obtenirListeSuivante(LC_ListeChainee *lc){
  if(!estVide(*lc)){
    return((*lc)->listeSuivante);
  }
}
