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
 * \return Ens_Ensemble un ensemble vide
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
  * \return integer qui est nombre d'éléments de l'Ensemble
*/
int Ens_obtenirNbElements(Ens_Ensemble ens);

/**
  * \brief Permet d'ajouter un Element à un Ensemble
  * \author Simon LEBEAUD
  * \param ens un pointer vers l'Ensemble à modifier
  * \param element L'Elément à ajouter
  * \param tailleElement taille de l'Element ajouter
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
  * \brief Permet d'ajouter les élements d'une ListeChainee à un ensemble
  * cette fonction concatène la Liste Chainee de l'Ensemble et celle donner
  * \author Simon LEBEAUD
  * \param Ens_Ensemble* pointeur sur l'Ensemble à modifier
  * \param  LC_ListeChaine La liste Chainée à ajouter à l'ensemble
  * \param tailleElement la taille des élements contenu dans la liste Chainée
*/

void Ens_ajouterElementsDUneAutreListe(Ens_Ensemble*,LC_ListeChainee,size_t tailleElement);

/**
  * \brief permet de faire l'Union de deux ensemble
  * \author Simon LEBEAUD
  * \param ensemble1 dont on veux faire l'union et leurs taille
  * \param ensemble2 avec lequel on fait l'union de ensemble1
  * \return ensemble3 le nouvel ensemble qui contient les Elements des deux Ensemble précédent
*/

Ens_Ensemble Ens_union(Ens_Ensemble,Ens_Ensemble,size_t tailleElement);

/**
  * \brief Permet d'ajouter à un ensemble, les élements d'une liste chainee, seulement si
  * ces element ne sont pas présent dans l'ensemble.
  * \author Simon LEBEAUD
  * \param Ens_Ensemble* un pointeur sur l'ensemble à modifier
  * \param LC_ListeChainee la liste à ajouter
  * \param tailleElement la taille des element dans la liste
*/

void Ens_ajouterElementsListeSiNonPresent(Ens_Ensemble*,LC_ListeChainee,Ens_Ensemble,size_t tailleElement);

/**
  * \brief permet de faire l'intersection de deux ensemble, c'est a dire avoir les élements
  * qui sont présent dans les deux ensemble.
  * \author Simon LEBEAUD
  * \param ensemble1 dont on veut faire l'intersection
  * \param ensemble2 qui fait intersection avec ensemble1
  * \return l'Ensemble intersection de ces deux ensemble
*/

Ens_Ensemble Ens_intersection(Ens_Ensemble,Ens_Ensemble,size_t tailleElement);

/**
  * \brief Permet d'ajouter à un ensemble, les élements d'une liste chainee, seulement si
  * ces elements sont présent dans l'ensemble.
  * \author Simon LEBEAUD
  * \param Ens_Ensemble* un pointeur sur l'ensemble à modifier
  * \param LC_ListeChaineec la Liste chainée
  * \param tailleElement la taille des element de la liste
*/

void ajouterElementsListeSiPresent(Ens_Ensemble*,LC_ListeChainee,Ens_Ensemble,size_t tailleElement);

/**
  * \brief permet de faire la soustraction de deux ensemble, c'est a dire avoir les élements
  * qui sont présent dans un seul des deux Ensemble
  * \author Simon LEBEAUD
  * \param ensemble1 dont on veut faire la soustraction
  * \param ensemble2 qui fait la soustraction avec ensemble1
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
