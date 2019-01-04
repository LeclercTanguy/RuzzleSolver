#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "ListeChainee.h"

LC_ListeChainee LC_listeVide(void){
  return NULL;
}

LC_ListeChainee LC_allouer(void) {
  LC_ListeChainee lc = (LC_ListeChainee)malloc(sizeof(LC_Noeud));
  lc->element = NULL;
  lc->listeSuivante = NULL;
  return lc;
}

bool LC_estVide(LC_ListeChainee lc){
    return lc==NULL;
}

void LC_ajouter(LC_ListeChainee* lc,Element elementAAjouter,size_t tailleElement){
  LC_ListeChainee temp = LC_allouer();
  LC_fixerElement(temp,elementAAjouter,tailleElement);
  LC_fixerListeSuivante(temp,*lc);
  *lc = temp;
}

bool LC_estPresent(LC_ListeChainee lc,Element unElement,size_t tailleElement){
  if (LC_estVide(lc)){
    return false;
  }else{
    if (!memcmp(LC_obtenirElement(lc),unElement,tailleElement)){
      return true;
    }else{
      return LC_estPresent(LC_obtenirListeSuivante(lc),unElement,tailleElement);
    }
  }
}

Element LC_obtenirElement(LC_ListeChainee lc){
  assert (!LC_estVide(lc));
  return lc->element;
}

LC_ListeChainee LC_obtenirListeSuivante(LC_ListeChainee lc){
  assert (!LC_estVide(lc));
  return lc->listeSuivante;
}

void LC_fixerElement(LC_ListeChainee lc,Element lElement,size_t tailleElement){
  assert (!LC_estVide(lc));
  if (LC_obtenirElement(lc)==NULL) {
    Element elementAjoute = malloc(tailleElement);
    memcpy(elementAjoute,lElement,tailleElement);
    (lc)->element=elementAjoute;
  } else {
    memcpy(LC_obtenirElement(lc),lElement,tailleElement);
  }
}

void LC_fixerListeSuivante(LC_ListeChainee lc,LC_ListeChainee lcSuivante){
  assert (!LC_estVide(lc));
  (lc)->listeSuivante=lcSuivante;
}

void LC_supprimerTete(LC_ListeChainee* lc){
  assert (!LC_estVide(*lc));
  LC_ListeChainee temp = *lc;
  *lc = LC_obtenirListeSuivante(temp);
  if (LC_obtenirElement(temp)!=NULL) {
    free(LC_obtenirElement(temp));
  }
  free(temp);
}

void LC_supprimer(LC_ListeChainee* lc){
  while (!LC_estVide(*lc)){
    LC_supprimerTete(lc);
  }
}
