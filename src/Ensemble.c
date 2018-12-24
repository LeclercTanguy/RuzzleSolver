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

<<<<<<< HEAD
int Ens_cardinalite(Ens_Ensemble ens){
=======
int Ens_obtenirNbElements(Ensemble ens){
>>>>>>> 61b6d2ed5792ced9dd390e5ac2828fff69cbe6a3
  return ens.nbElements;
}

void Ens_ajouter(Ens_Ensemble ens,char lettre){
  LC_ListeChainee lesElementsDeLEnsemble = Ens_obtenirLesElements(ens);
  LC_ajouter(&lesElementsDeLEnsemble,lettre);
  int nb = Ens_cardinalite(ens);
  nb = nb+1;
}

int Ens_estPresent(Ens_Ensemble ens,char lettre){
  LC_ListeChainee listemp;
  listemp = Ens_obtenirLesElements(ens);
  return LC_estPresent(listemp,lettre);
}

void Ens_ajouterElmentsDUneAutreListe(Ens_Ensemble ens,LC_ListeChainee lc){
  do{
    Ens_ajouter(ens,LC_obtenirElement(lc));
    lc = LC_obtenirListeSuivante(lc);
  }while(!LC_estVide(lc));
}

Ens_Ensemble Ens_union(Ens_Ensemble ens1,Ens_Ensemble ens2){
  Ens_Ensemble resultat = Ens_ensemble();
  Ens_ajouterElmentsDUneAutreListe(resultat,Ens_obtenirLesElements(ens1));
  Ens_ajouterElmentsDUneAutreListe(resultat,Ens_obtenirLesElements(ens2));
  return resultat;
}

void Ens_ajouterElementsListeSiNonPresent(Ens_Ensemble ens,LC_ListeChainee lc,Ens_Ensemble ensRef){
  do{
    if (!Ens_estPresent(ensRef,LC_obtenirElement(lc))){
      Ens_ajouter(ens,LC_obtenirElement(lc));
    }
    lc = LC_obtenirListeSuivante(lc);
  }while(!LC_estVide(lc));
}

Ens_Ensemble Ens_intersection(Ens_Ensemble ens1,Ens_Ensemble ens2){
  Ens_Ensemble resultat= Ens_ensemble();
  Ens_ajouterElementsListeSiNonPresent(resultat,Ens_obtenirLesElements(ens1),ens2);
  return resultat;
}

void Ens_ajouterElementsListeSiPresent(Ens_Ensemble ens,LC_ListeChainee lc,Ens_Ensemble ensRef){
  do{
    if (Ens_estPresent(ensRef,LC_obtenirElement(lc))){
      Ens_ajouter(ens,LC_obtenirElement(lc));
    }
    lc = LC_obtenirListeSuivante(lc);
  }while(!LC_estVide(lc));
}

Ens_Ensemble Ens_soustraction(Ens_Ensemble ens1,Ens_Ensemble ens2){
  Ens_Ensemble resultat= Ens_ensemble();
  Ens_ajouterElementsListeSiPresent(resultat,Ens_obtenirLesElements(ens1),ens2);
  return resultat;
}
