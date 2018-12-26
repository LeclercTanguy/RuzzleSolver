#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "ListeChainee.h"
#define TRUE 1
#define FALSE 0

LC_ListeChainee LC_listeVide(void){
  return NULL;
}

LC_ListeChainee LC_allouer(size_t tailleElement) {
  return (LC_ListeChainee)malloc(tailleElement+sizeof(LC_ListeChainee));
}

int LC_estVide(LC_ListeChainee lc){
    return lc==NULL;
}

void LC_ajouter(LC_ListeChainee* lc,Element elementAAjouter,size_t tailleElement){
  LC_ListeChainee temp = LC_allouer(tailleElement);
  Element elementAjoute = malloc(tailleElement);
  memcpy(elementAjoute,elementAAjouter,tailleElement);
  LC_fixerElement(temp,elementAjoute);
  LC_fixerListeSuivante(temp,*lc);
  *lc = temp;
}

int LC_estPresent(LC_ListeChainee lc,Element unElement,size_t tailleElement){
  if (LC_estVide(lc)){
    return FALSE;
  }else{
    if (!memcmp(LC_obtenirElement(lc),unElement,tailleElement)){
      return TRUE;
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

void LC_fixerElement(LC_ListeChainee lc,Element lElement){
  assert (!LC_estVide(lc));
  (lc)->element=lElement;
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
