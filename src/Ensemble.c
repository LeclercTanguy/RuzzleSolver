#include <stdio.h>
#include <stdlib.h>
#include "Ensemble.h"
#include "ListeChainee.h"
#define TRUE 1
#define FALSE 0

Ens_Ensemble Ens_ensemble(void){
  Ens_Ensemble resultat;
  resultat.lesElements = LC_listeVide();
  resultat.nbElements = 0;
  return resultat;
}

LC_ListeChainee Ens_obtenirLesElements(Ens_Ensemble ens){
  return ens.lesElements;
}

int Ens_obtenirNbElements(Ens_Ensemble ens){
  return ens.nbElements;
}

void Ens_ajouter(Ens_Ensemble* ens,Element element,size_t tailleElement){
  LC_ajouter(&(ens->lesElements),element,tailleElement);
  ens->nbElements=Ens_obtenirNbElements(*ens)+1;
}

bool Ens_estPresent(Ens_Ensemble ens, Element element,size_t tailleElement){
  LC_ListeChainee listemp;
  listemp = Ens_obtenirLesElements(ens);
  return LC_estPresent(listemp,element,tailleElement);
}

void Ens_ajouterElementsDUneAutreListe(Ens_Ensemble* ens,LC_ListeChainee lc,size_t tailleElement){
  do{
    Ens_ajouter(ens,LC_obtenirElement(lc),tailleElement);
    lc = LC_obtenirListeSuivante(lc);
  }while(!LC_estVide(lc));
}

Ens_Ensemble Ens_union(Ens_Ensemble ens1,Ens_Ensemble ens2,size_t tailleElement){
  Ens_Ensemble resultat = Ens_ensemble();
  Ens_ajouterElementsDUneAutreListe(&resultat,Ens_obtenirLesElements(ens1),tailleElement);
  Ens_ajouterElementsDUneAutreListe(&resultat,Ens_obtenirLesElements(ens2),tailleElement);
  return resultat;
}

void Ens_ajouterElementsListeSiNonPresent(Ens_Ensemble* ens,LC_ListeChainee lc,Ens_Ensemble ensRef,size_t tailleElement){
  do{
    if (!Ens_estPresent(ensRef,LC_obtenirElement(lc),tailleElement)){
      Ens_ajouter(ens,LC_obtenirElement(lc),tailleElement);
    }
    lc = LC_obtenirListeSuivante(lc);
  }while(!LC_estVide(lc));
}

Ens_Ensemble Ens_soustraction(Ens_Ensemble ens1,Ens_Ensemble ens2,size_t tailleElement){
  Ens_Ensemble resultat= Ens_ensemble();
  Ens_ajouterElementsListeSiNonPresent(&resultat,Ens_obtenirLesElements(ens1),ens2,tailleElement);
  return resultat;
}

void Ens_ajouterElementsListeSiPresent(Ens_Ensemble* ens,LC_ListeChainee lc,Ens_Ensemble ensRef,size_t tailleElement){
  do{
    if (Ens_estPresent(ensRef,LC_obtenirElement(lc),tailleElement)){
      Ens_ajouter(ens,LC_obtenirElement(lc),tailleElement);
    }
    lc = LC_obtenirListeSuivante(lc);
  }while(!LC_estVide(lc));
}

Ens_Ensemble Ens_intersection(Ens_Ensemble ens1,Ens_Ensemble ens2,size_t tailleElement){
  Ens_Ensemble resultat= Ens_ensemble();
  Ens_ajouterElementsListeSiPresent(&resultat,Ens_obtenirLesElements(ens1),ens2,tailleElement);
  return resultat;
}
