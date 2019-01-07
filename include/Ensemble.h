/**
 *\file Ensemble.h
 *\brief Implantation du TAD Ensemble
 *\author Simon LEBEAUD
 *\version 1.0
 *
 */

#ifndef _ENSEMBLE_
#define _ENSEMBLE_
#include "ListeChainee.h"

/**
* \brief le type Ensemble permet de regrouper un ensemble de valeurs uniques du même type
*/
typedef struct Ens_Ensemble {
  LC_ListeChainee lesElements; /**< la liste chaînée des éléments de l'ensemble */
  unsigned int nbElements; /**< le nombre d'éléments de l'ensemble */
}Ens_Ensemble;

/**
 * \brief création d'un ensemble vide
 * \author Simon LEBEAUD
 * \return un ensemble vide
*/
Ens_Ensemble Ens_ensemble(void);

/**
 * \brief permet d'obtenir la liste chainée d'éléments contenus dans un ensemble
 * \author Simon LEBEAUD
 * \param ens Ensemble dont on veux les éléments
 * \return  la liste chaînée des éléments contenus dans l'Ensemble
*/
LC_ListeChainee Ens_obtenirLesElements(Ens_Ensemble ens);

/**
  *\brief conversion d'un ensemble en tableau d'éléments
  *\author Yves LE GUENNEC
  *\param ens l'ensemble à convertir
  *\param tailleElement la taille (en octets) des éléments contenus dans l'Ensemble
  *\return un pointeur vers le premier élément du tableau
  *\warning transtypez le tableau en un pointeur vers le type des éléments de l'ensemble avant de l'utiliser (ex: char* tab = (char*)Ens_ensembleEnTableau(ens,sizeof(char))).
  *\warning utiliser Ens_obtenirNbElements pour connaître le nombre d'éléments du tableau
  *\warning pensez à libérer le tableau quand il n'est plus nécessaire (free(tab))
*/
void* Ens_ensembleEnTableau (Ens_Ensemble ens, size_t tailleElement);

/**
  * \brief Permet d'obtenir le nombre d'élements contenus dans un Ensemble
  * \author Simon LEBEAUD
  * \param ens Ensemble dont on veut connaître le nombre d'éléments
  * \return le nombre d'éléments de l'Ensemble
*/
int Ens_obtenirNbElements(Ens_Ensemble ens);

/**
  * \brief Permet d'ajouter un Element à un Ensemble
  * \author Simon LEBEAUD
  * \param ens un pointer vers l'Ensemble à modifier
  * \param element L'Elément à ajouter (pointeur vers le type de données de l'ensemble)
  * \param tailleElement taille du type de l'Element à ajouter
*/
void Ens_ajouter(Ens_Ensemble* ens,Element element,size_t tailleElement);

/**
  * \brief permet de savoir si un element est présent dans un Ensemble
  * \author Simon LEBEAUD
  * \param ens l'emsemble à tester
  * \param element l'élement à rechercher dans l'ensemble
  * \param tailleElement la taille de l'élément que l'on cherche
  * \return VRAI(1) si l'élément est présent, FAUX(0) sinon
*/
bool Ens_estPresent(Ens_Ensemble ens, Element element,size_t tailleElement);

/**
  * \brief Permet d'ajouter les élements d'une ListeChainee à un ensemble.
  * Cette fonction concatène la Liste Chaînee de l'Ensemble et celle donnée
  * \author Simon LEBEAUD
  * \param ens pointeur sur l'Ensemble à modifier
  * \param lc La liste Chainée à ajouter à l'ensemble
  * \param tailleElement la taille des éléments contenus dans la liste Chaînée
*/

void Ens_ajouterElementsDUneAutreListe(Ens_Ensemble* ens,LC_ListeChainee lc,size_t tailleElement);

/**
  * \brief permet de faire l'Union de deux ensemble
  * \author Simon LEBEAUD
  * \param ensemble1 le premier ensemble dont on veux faire l'union
  * \param ensemble2 le second ensemble dont on veux faire l'union
  * \return un nouvel ensemble qui contient les Elements des deux Ensembles précédent
*/

Ens_Ensemble Ens_union(Ens_Ensemble ensemble1, Ens_Ensemble ensemble2,size_t tailleElement);

/**
  * \brief Permet d'ajouter à un ensemble, les élements d'une liste chaînée, seulement si
  * ces élément ne sont pas présents dans l'ensemble.
  * \author Simon LEBEAUD
  * \param ens un pointeur sur l'ensemble à modifier
  * \param lc la liste des éléments à ajouter
  * \param ensRef l'ensemble de référence pour savoir si un élément doit être ajouté
  * \param tailleElement la taille des éléments dans la liste
*/
void Ens_ajouterElementsListeSiNonPresent(Ens_Ensemble* ens,LC_ListeChainee lc, Ens_Ensemble ensRef,size_t tailleElement);

/**
  * \brief permet de faire l'intersection de deux ensembles, c'est-à-dire avoir les élements
  * qui sont présents dans les deux ensembles.
  * \author Simon LEBEAUD
  * \param ensemble1 ensemble dont on veut faire l'intersection
  * \param ensemble2 ensemble qui fait intersection avec ensemble1
  * \return l'Ensemble intersection de ces deux ensemble
*/

Ens_Ensemble Ens_intersection(Ens_Ensemble,Ens_Ensemble,size_t tailleElement);

/**
  * \brief Permet d'ajouter à un ensemble, les élements d'une liste chaînée, seulement si
  * ses éléments sont présents dans l'ensemble.
  * \author Simon LEBEAUD
  * \param ens un pointeur sur l'ensemble à modifier
  * \param lc la liste des éléments à ajouter
  * \param ensRef l'ensemble de référence pour savoir si un élément doit être ajouté
  * \param tailleElement la taille des éléments de la liste
*/

void ajouterElementsListeSiPresent(Ens_Ensemble* ens,LC_ListeChainee lc,Ens_Ensemble ensRef,size_t tailleElement);

/**
  * \brief permet de faire la soustraction de deux ensembles, c'est-à-dire avoir les élements
  * qui sont présent dans un seul des deux Ensembles
  * \author Simon LEBEAUD
  * \param ensemble1 ensemble dont on veut faire la soustraction
  * \param ensemble2 ensemble qui fait la soustraction avec ensemble1
  * \return l'Ensemble soustraction de ces deux ensemble
*/

Ens_Ensemble Ens_soustraction(Ens_Ensemble,Ens_Ensemble,size_t tailleElement);

/**
  *\brief permet de supprimer un Ensemble
  *\author Yves LE GUENNEC
  \param ens un pointeur vers l'ensemble à supprimer
*/
void Ens_supprimer(Ens_Ensemble* ens);

#endif
