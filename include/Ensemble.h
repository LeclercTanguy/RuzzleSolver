/**
 *\file Ensemble.h
 *\brief Implantation du TAD Ensemble
 *\author S.Lebeaud
 *\version 1.0
 *
 */

#ifndef _ENSEMBLE_
#define _ENSEMBLE_
#include "ListeChainee.h"

typedef struct Ens_Ensemble {
  LC_ListeChainee lesElements;
  int nbElements;
}Ens_Ensemble;

/**
 *\fn Ens_Ensemble Ens_ensemble(void)
 *\brief création d'un ensemble LC_estVide
 *\param  aucun paramètre d'entrée
 *\return Ens_Ensemble
*/

Ens_Ensemble Ens_ensemble(void);

/**
 *\fn LC_ListeChainee Ens_obtenirLesElements(Ens_Ensemble);
 *\brief nous permet d'obtenir la liste chainée d'éléments
 *\param  Ens_Ensemble , l'ensemble dont on veux les éléments
 *\return LC_ListeChainee
*/

LC_ListeChainee Ens_obtenirLesElements(Ens_Ensemble);
int Ens_obtenirNbElements(Ens_Ensemble);
void Ens_ajouter(Ens_Ensemble,char);
int Ens_estPresent(Ens_Ensemble,char);
void Ens_ajouterElmentsDUneAutreListe(Ens_Ensemble,LC_ListeChainee);
Ens_Ensemble Ens_union(Ens_Ensemble,Ens_Ensemble);
void Ens_ajouterElementsListeSiNonPresent(Ens_Ensemble,LC_ListeChainee,Ens_Ensemble);
Ens_Ensemble Ens_intersection(Ens_Ensemble,Ens_Ensemble);
void ajouterElementsListeSiPresent(Ens_Ensemble,LC_ListeChainee,Ens_Ensemble);
Ens_Ensemble Ens_soustraction(Ens_Ensemble,Ens_Ensemble);

#endif
