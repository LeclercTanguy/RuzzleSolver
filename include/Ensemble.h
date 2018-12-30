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
 *\param  aucun paramètre d'entrée
 *\return Ens_Ensemble
*/

Ens_Ensemble Ens_ensemble(void);

/**
 *\brief nous permet d'obtenir la liste chainée d'éléments
 *\param  Ens_Ensemble , l'ensemble dont on veux les éléments
 *\return LC_ListeChainee
*/

LC_ListeChainee Ens_obtenirLesElements(Ens_Ensemble);

/**
  *\brief Permet d'obtenir le nombre délement contenue dans un Ensemble
  *\param il prend l'ensemble dont on veut connaitre le nombre déléments en entrer
  *\return il nous rend un interger, le nombre d'élément
*/

int Ens_obtenirNbElements(Ens_Ensemble);

/**
  *\brief Permet d'ajouter un élément à un Ensemble
  *\param il prend  un pointer vers la case mémoire d'un ensemble l'élément à ajouter et la taille de l'élément
  *\return ici l'ensemble est en Entrer-Sortie.
*/

void Ens_ajouter(Ens_Ensemble*,Element,size_t tailleElement);

/**
  *\brief permet de savoir si un element est present dans un Ensemble
  *\param Pour cela on a besoin de l'Esemble, de l'element à rechercher et de ça taille
  *\return VRAI(1) si l'élément est présent, FAUX(0) sinon
*/

int Ens_estPresent(Ens_Ensemble,Element,size_t tailleElement);
void Ens_ajouterElementsDUneAutreListe(Ens_Ensemble*,LC_ListeChainee,size_t tailleElement);
Ens_Ensemble Ens_union(Ens_Ensemble,Ens_Ensemble,size_t tailleElement);
void Ens_ajouterElementsListeSiNonPresent(Ens_Ensemble*,LC_ListeChainee,Ens_Ensemble,size_t tailleElement);
Ens_Ensemble Ens_intersection(Ens_Ensemble,Ens_Ensemble,size_t tailleElement);
void ajouterElementsListeSiPresent(Ens_Ensemble*,LC_ListeChainee,Ens_Ensemble,size_t tailleElement);
Ens_Ensemble Ens_soustraction(Ens_Ensemble,Ens_Ensemble,size_t tailleElement);

#endif
