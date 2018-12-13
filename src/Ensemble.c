#include <stdio.h>
#include <stdlib.h>
#include "Ensemble.h"
#include "ListeChainee.h"
#define TRUE 1
#define FALSE 0

Ensemble Ens_ensemble(void){
  Ensemble resultat;
  resultat.lesElements = LC_listeVide();
  resultat.nbElements = 0;
  return resultat;
}

LC_ListeChainee Ens_obtenirLesElements(Ensemble ens){
  return ens.lesElements;
}

int Ens_obtenirNbElements(Ensemble ens){
  return ens.nbElements;
}


int Ens_estPresent(Ensemble ens,char lettre){
  LC_ListeChainee listemp;
  listemp = Ens_obtenirLesElements(ens);
  return LC_estPresent(listemp,lettre);
}
