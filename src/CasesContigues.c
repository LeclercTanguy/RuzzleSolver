#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CasesContigues.h"
#include "ListeChainee.h"

CasesContigues CC_creer_CasesContigues(void){
  int nombreCases=0;
  LC_ListeChainee listeDeCases= LC_listeVide();

  CasesContigues desCasesContigues;
  desCasesContigues.nbCases=nombreCases;
  desCasesContigues.listeCases=listeDeCases;

  return desCasesContigues;
}

void CC_ajouterCase(CasesContigues* desCasesContigues,Case uneCase){
  LC_ajouter(&(*desCasesContigues).listeCases, &uneCase, sizeof(Case));
  (*desCasesContigues).nbCases=(*desCasesContigues).nbCases+1;
}

void CC_suprimerCase(CasesContigues* desCasesContigues){
  LC_supprimerTete(&(*desCasesContigues).listeCases);
  (*desCasesContigues).nbCases=(*desCasesContigues).nbCases-1;
}

int CC_nbCasesContigues(CasesContigues desCasesContigues){
  int nombreCases=desCasesContigues.nbCases;
  return nombreCases;
}

char* CC_CasesContiguesEnChaine(CasesContigues desCasesContigues){
  LC_ListeChainee listeDeCases=desCasesContigues.listeCases;
  char* chaine = "";
    while (!LC_estVide(listeDeCases)){
      Case*  maCase=LC_obtenirElement(listeDeCases);
      char maLettre=CASE_obtenirLettre(*maCase);
      strcat(chaine,&maLettre);
    }
    return chaine;
}

unsigned int CC_totalPointsCasesContigues(CasesContigues suiteCase) {
  return 0;
}
