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
 * \brief création d'un ensemble LC_estVide
 * \author Simon LEBEAUD
 * \return un ensemble vide
*/
Ens_Ensemble Ens_ensemble(void);

/**
 * \brief permet d'obtenir la liste chainée d'éléments contenue dans un ensemble
 * \author Simon LEBEAUD
 * \param Ensemble dont on veux les éléments
 * \return  Liste chainée des éléments contenus dans l'Ensemble
*/
LC_ListeChainee Ens_obtenirLesElements(Ens_Ensemble ens);

/**
  * \brief Permet d'obtenir le nombre d'élements contenus dans un Ensemble
  * \author Simon LEBEAUD
  * \param Ensemble dont on veut connaître le nombre d'éléments
  * \return integer qui est nombre d'éléments de l'Ensemble
*/
int Ens_obtenirNbElements(Ens_Ensemble ens);

/**
  * \brief Permet d'ajouter un Element à un Ensemble
  * \author Simon LEBEAUD
  * \param un pointer vers l'Ensemble à modifier
  * \param L'Elément à ajouter
  * \param la taille de l'élément
*/
void Ens_ajouter(Ens_Ensemble* ens,Element element,size_t tailleElement);

/**
  * \brief permet de savoir si un element est présent dans un Ensemble
  * \author Simon LEBEAUD
  * \param Ensemble à tester
  * \param element l'élement à rechercher dans l'ensemble
  * \param tailleElement la taille de l'élément
  * \return VRAI(1) si l'élément est présent, FAUX(0) sinon
*/
bool Ens_estPresent(Ens_Ensemble ens, Element element,size_t tailleElement);

/**
  * \brief Permet d'ajouter les élements d'une ListeChainee à un ensemble
  * cette fonction concatène la Liste Chainee de l'Ensemble et celle donner
  * \author Simon LEBEAUD
  * \param pointeur sur l'Ensemble à modifier
  * \param La liste Chainée à ajouter à l'ensemble
*/

void Ens_ajouterElementsDUneAutreListe(Ens_Ensemble*,LC_ListeChainee,size_t tailleElement);

/**
  * \brief permet de faire l'Union de deux ensemble
  * \author Simon LEBEAUD
  * \param les Deux ensemble dont on veux faire l'union et leurs taille
  * \return Nouvel Ensemble qui contient les Elements des deux Ensemble précédent
*/

Ens_Ensemble Ens_union(Ens_Ensemble,Ens_Ensemble,size_t tailleElement);

/**
  * \brief Permet d'ajouter à un ensemble, les élements d'une liste chainee, seulement si
  * ces element ne sont pas présent dans l'ensemble.
  * \author Simon LEBEAUD
  * \param pointeur sur l'ensemble à modifier
  * \param la Liste chainée et la taille de ces element
*/

void Ens_ajouterElementsListeSiNonPresent(Ens_Ensemble*,LC_ListeChainee,Ens_Ensemble,size_t tailleElement);

/**
  * \brief permet de faire l'intersection de deux ensemble, c'est a dire avoir les élements
  * qui sont présent dans les deux ensemble.
  * \author Simon LEBEAUD
  * \param Deux ensemble dont on veut faire l'intersectiob
  * \return l'Ensemble intersection de ces deux ensemble
*/

Ens_Ensemble Ens_intersection(Ens_Ensemble,Ens_Ensemble,size_t tailleElement);

/**
  * \brief Permet d'ajouter à un ensemble, les élements d'une liste chainee, seulement si
  * ces elements sont présent dans l'ensemble.
  * \author Simon LEBEAUD
  * \param pointeur sur l'ensemble à modifier
  * \param la Liste chainée et la taille de ces element
*/

void ajouterElementsListeSiPresent(Ens_Ensemble*,LC_ListeChainee,Ens_Ensemble,size_t tailleElement);

/**
  * \brief permet de faire la soustraction de deux ensemble, c'est a dire avoir les élements
  * qui sont présent dans un seul des deux Ensemble
  * \author Simon LEBEAUD
  * \param Deux ensemble dont on veut faire la soustraction et la taille de leur elements
  * \return l'Ensemble soustraction de ces deux ensemble
*/

Ens_Ensemble Ens_soustraction(Ens_Ensemble,Ens_Ensemble,size_t tailleElement);

#endif
