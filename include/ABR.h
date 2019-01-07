/**
 * \file ABR.h
 * \brief Implantation du TAD ABR
 * \author Tanguy LECLERC
 */

#ifndef __ABR__
#define __ABR__

#include "ArbreBinaire.h"

/**
 * \brief Un ABR est un arbre binaire, il aura des fonctions en plus pour qu'il soit ordonné. C'est à dire élément fils gauche < élément racine < élément fils droit.
 */
typedef ArbreBinaire ABR;


/**
 * \brief Création d'un ABR vide.
 * \author T.LECLERC
 * \return Un ABR vide.
 */
ABR ABR_creer(void);
/**
 * \brief Fonction pour vérifier si un ABR est vide.
 * \author T.LECLERC
 * \param a l'ABR dont on veut savoir si il est vide.
 * \return Vrai si l'ABR est vide et Faux sinon.
 */
bool ABR_estVide(ABR a);
/**
 * \brief Procédure permettant d'insérer un élément de façon ordonnée dans un ABR.
 * \author T.LECLERC
 * \param *a pointeur sur l'ABR que l'on veut modifier.
 * \param e l'élément que l'ont veut insérer.
 * \param comparerElement une fonction qui permet de comparer deux élément, utile pour ordonner l'insertion.
 * \param tailleElement taille de l'élément à insérer, ignoré si e==NULL.
 */
void ABR_inserer(ABR* a, Element e, int(*comparerElement)(Element,Element),size_t tailleElement);
/**
 * \brief Indique si un élément est présent dans l'ABR.
 * \author T.LECLERC
 * \param a l'ABR dans lequel on veut vérifier la présence.
 * \param e l'élément recherché (pointeur sur la valeur recherchée)
 * \param comparerElement fonction permettant de comparer les éléments utilisés
 * \return Vrai si l'élément est présent et Faux sinon.
 */
bool ABR_estPresent(ABR a, Element e, int(*comparerElement)(Element,Element));

/**
* \brief indique si l'Element est présent dans l'ABR, et auquel cas renvoi son adresse
* \author Yves LE GUENNEC, modification de ABR_estPresent de Tanguy LECLERC
* \param a l'ABR dans lequel on veut vérifier la présence
* \param e l'élément recherché (pointeur sur la valeur recherchée)
* \param comparerElement fonction permettant de comparer les éléments utilisés
* \return NULL si l'élément n'est pas présent
          l'Element (pointeur vers la zone contenant l'élément) si l'élément est présent
*/
Element ABR_estPresentAvecReference(ABR a, Element e, int(*comparerElement)(Element,Element));
/**
 * \brief Permet d'obtenir l'ABR avec le plus grand élément en partant d'un ABR.
 * \author T.LECLERC
 * \param a l'ABR dont on veut le plus grand sous ABR.
 * \return L'ABR avec le plus grand élément.
 */
ABR ABR_lePlusGrand(ABR a);
/**
 * \brief Procédure permettant de supprimer un élément dans un ABR.
 * \author T.LECLERC
 * \param *a pointeur sur l'ABR dont on veut supprimer un élément.
 * \param e l'élément que l'ont veut supprimer.
 * \param comparerElement une fonction qui permet de comparer deux élément.
 * \param tailleElement taille de l'élément à supprimer.
 */
void ABR_supprimerElement(ABR* a, Element e, int(*comparerElement)(Element,Element),size_t tailleElement);
/**
 * \brief Procédure permettant de supprimer un ABR.
 * \author T.LECLERC
 * \param *a pointeur sur l'arbre que l'on veut supprimer.
 */
void ABR_supprimer(ABR* a);

#endif
