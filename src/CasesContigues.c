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

void CC_supprimerCase(CasesContigues* desCasesContigues){
  LC_supprimerTete(&(*desCasesContigues).listeCases);
  (*desCasesContigues).nbCases=(*desCasesContigues).nbCases-1;
}

void CC_supprimer(CasesContigues* desCasesContigues){
  while (CC_nbCasesContigues(*desCasesContigues)>0) {
    CC_supprimerCase(desCasesContigues);
  }
}

int CC_nbCasesContigues(CasesContigues desCasesContigues){
  int nombreCases=desCasesContigues.nbCases;
  return nombreCases;
}

char* CC_CasesContiguesEnChaine(CasesContigues desCasesContigues){
  LC_ListeChainee listeDeCases=desCasesContigues.listeCases;
  int longueurCC=CC_nbCasesContigues(desCasesContigues);
  char* chaine = (char*)malloc((longueurCC+1)*sizeof(char));
  int i=longueurCC;
    while (i>0){
      Case  maCase=*(Case*)LC_obtenirElement(listeDeCases);
      char maLettre=CASE_obtenirLettre(maCase);
      chaine[i-1]=maLettre;
      listeDeCases = LC_obtenirListeSuivante(listeDeCases);
      i--;
    }
    chaine[longueurCC+1]='\0';
    return chaine;
}

unsigned int CC_totalPointsCasesContigues(CasesContigues desCasesContigues) {
  LC_ListeChainee listeDeCases=desCasesContigues.listeCases;
  int longueurCC=CC_nbCasesContigues(desCasesContigues);

  unsigned int nombrePoints = 0;
  int i=longueurCC;
    while (i>0){
      Case  maCase=*(Case*)LC_obtenirElement(listeDeCases);
      char mesPoints=CASE_obtenirNbPoints(maCase);
      nombrePoints = nombrePoints + mesPoints;
      listeDeCases = LC_obtenirListeSuivante(listeDeCases);
      i--;
    }
    return nombrePoints;
}
