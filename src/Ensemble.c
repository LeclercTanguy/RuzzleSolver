#include <stdlib.h>
#include <string.h>
#include "Ensemble.h"
#include "ListeChainee.h"

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

void* Ens_ensembleEnTableau (Ens_Ensemble ens, size_t tailleElement) {
  int nbElements = Ens_obtenirNbElements(ens);
  void* tableau = malloc(nbElements*tailleElement);
  LC_ListeChainee listeElements = Ens_obtenirLesElements(ens);
  void* pCaseTableau;
  for (int i = 0; i < nbElements; i++) {
    pCaseTableau = (char*)tableau+i*tailleElement;
    //char : 1 octet -> pour permettre l'arithmétique sur les pointeurs
    memcpy(pCaseTableau,LC_obtenirElement(listeElements),tailleElement);
    listeElements = LC_obtenirListeSuivante(listeElements);
  }
  return tableau;
}

//normalement un ensemble ne doit pas comporter de doublons
//cependant, au vu des algos utilisés par la suite et afin de gagner du temps
//lors de l'exécution, je laisse le code ainsi    YLG
//des fonctions avec vérification de la présence des éléments sont présentes plus bas si besoin
//TODO reprendre le code de Ensemble afin de respecter la définition
void Ens_ajouter(Ens_Ensemble* ens,Element element,size_t tailleElement){
  LC_ajouter(&(ens->lesElements),element,tailleElement);
  ens->nbElements=Ens_obtenirNbElements(*ens)+1;
}

bool Ens_estPresent(Ens_Ensemble ens, Element element,size_t tailleElement){
  return LC_estPresent(Ens_obtenirLesElements(ens),element,tailleElement);
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

void Ens_supprimer(Ens_Ensemble* ens) {
  LC_ListeChainee temp = Ens_obtenirLesElements(*ens);
  LC_supprimer(&temp);
  ens->lesElements = temp;
  ens->nbElements = 0;
}
