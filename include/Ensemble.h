#ifndef _ENSEMBLE_
#define _ENSEMBLE_
#include "ListeChainee.h"

typedef struct Ensemble {
  LC_ListeChainee lesElements;
  int nbElements;
}Ensemble;

Ensemble Ens_ensemble(void);
void Ens_ajouter(Ensemble,char);
int Ens_estPresent(Ensemble,char);
int Ens_cardinalite(Ensemble);
void Ens_union(Ensemble,Ensemble);
void Ens_intersection(Ensemble,Ensemble);
void Ens_soustraction(Ensemble,Ensemble);

#endif
