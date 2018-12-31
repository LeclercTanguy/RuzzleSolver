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
  unsigned int nbElements;
}Ens_Ensemble;

/**
 *\brief création d'un ensemble LC_estVide
 *\return un ensemble vide
*/
Ens_Ensemble Ens_ensemble(void);

/**
 *\brief nous permet d'obtenir la liste chainée d'éléments
 *\param ens l'ensemble dont on veux les éléments
 *\return la liste chainée des éléments
*/
LC_ListeChainee Ens_obtenirLesElements(Ens_Ensemble ens);

/**
  *\brief Permet d'obtenir le nombre d'élements contenus dans un Ensemble
  *\param ens l'ensemble dont on veut connaître le nombre d'éléments
  *\return le nombre d'éléments de l'ensemble
*/
int Ens_obtenirNbElements(Ens_Ensemble ens);

/**
  *\brief Permet d'ajouter un Element à un Ensemble
  *\param ens un pointer vers l'ensemble à modifier
  *\param element l'élément à ajouter
  *\param tailleElement la taille de l'élément
*/
void Ens_ajouter(Ens_Ensemble* ens,Element element,size_t tailleElement);

/**
  *\brief permet de savoir si un element est présent dans un Ensemble
  *\param ens l'ensemble à tester
  *\param element l'élement à rechercher dans l'ensemble
  *\param tailleElement la taille de l'élément
  *\return VRAI(1) si l'élément est présent, FAUX(0) sinon
*/
bool Ens_estPresent(Ens_Ensemble ens, Element element,size_t tailleElement);
void Ens_ajouterElementsDUneAutreListe(Ens_Ensemble*,LC_ListeChainee,size_t tailleElement);
Ens_Ensemble Ens_union(Ens_Ensemble,Ens_Ensemble,size_t tailleElement);
void Ens_ajouterElementsListeSiNonPresent(Ens_Ensemble*,LC_ListeChainee,Ens_Ensemble,size_t tailleElement);
Ens_Ensemble Ens_intersection(Ens_Ensemble,Ens_Ensemble,size_t tailleElement);
void ajouterElementsListeSiPresent(Ens_Ensemble*,LC_ListeChainee,Ens_Ensemble,size_t tailleElement);
Ens_Ensemble Ens_soustraction(Ens_Ensemble,Ens_Ensemble,size_t tailleElement);

#endif
