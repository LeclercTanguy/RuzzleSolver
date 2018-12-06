#ifndef _ENSEMBLE_
#define _ENSEMBLE_
#include "ListeChainee.h"

typedef struct Ensemble {
  ListeChainee lesElements;
  int nbElements;
};

Ensemble ensemble(void);
void ajouter(Ensemble,char);
void ajouter(Ensemble,char);
int estPresent(Ensemble,char);
int cardinalite(Ensemble);
void union(Ensemble,Ensemble)
void intersection(Ensemble,Ensemble);
void soustraction(Ensemble,Ensemble);

#endif
