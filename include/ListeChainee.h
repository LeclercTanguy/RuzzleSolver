/**
 *\file ListeChainee.h
 *\brief Implantation du TAD ListeChainee
 *\author Simon LEBEAUD
 */

#ifndef __LISTE_CHAINEE__
#define __LISTE_CHAINEE__
#include <stdbool.h>
#include <stddef.h>

/**
  * \brief On declare un type Element qui est un espace mémoire
  * dédié à un Element que l'on pourra ensuite changer, comme cela
  * on un TAD Liste Chainee générique
*/
typedef void* Element;

typedef struct LC_Noeud* LC_ListeChainee;
typedef struct LC_Noeud {
  Element element;
  LC_ListeChainee listeSuivante;
} LC_Noeud;

/**
  * \brief création d'une Liste Chainee vide
  * \author S.LEBEAUD
  * \return une liste chainée vide (NULL)
*/

LC_ListeChainee LC_listeVide(void);

/**
  * \brief Permet d'allouer de l'espace mémoire celon les Elements qui serons
  * contenu dans la liste chainée
  * \author S.LEBEAUD
  * \return une liste Chainee vide
*/

LC_ListeChainee LC_allouer(void);

/**
  * \brief Permet de déterminer si une liste chainée est vide ou non
  * \author S.LEBEAUD
  * \param lc la liste chainée dont on veux savoir si elle est vide ou non
  * \return un booléen Vrai si la liste est Vide, Faux sinon
*/

bool LC_estVide(LC_ListeChainee lc);

/**
  * \brief Permet de savoir si un Element est présent dans une liste chainée
  * \author S.LEBEAUD
  * \param lc la liste Chainee
  * \param unElement l'Element dont on veut vérifier la présence dans la liste Chainee lc
  * \param tailleElement la taille de L'espace mémoire que prend l'élément
  * \return un booléen, VRAI si l'élément est présent, FAUX sinon
*/

bool LC_estPresent(LC_ListeChainee lc,Element unElement,size_t tailleElement);

/**
  * \brief permet d'ajouter un élément à une liste chainee
  * \author S.LEBEAUD
  * \param lc un pointeur sur la liste chainée à laquelle on veut ajouter un élement
  * \param elementAAjouter l'élément que l'on veux ajouter
  * \param tailleElement la taille de l'espace mémoire que l'élément occupe.
*/

void LC_ajouter(LC_ListeChainee* lc,Element elementAAjouter,size_t tailleElement);

/**
  * \brief Permet d'obtenir le dernière élement ajouter à une liste chainée
  * \author S.LEBEAUD
  * \param  lc , une listechainne non vide
  * \return le dernière élément ajouté à la liste
*/

Element LC_obtenirElement(LC_ListeChainee lc);

/**
  * \brief Permet d'obtenir la liste suivante d'une liste chainée
  * \author S.LEBEAUD
  * \param lc la liste chainée
  * \return la liste chainée suivante de lc
*/

LC_ListeChainee LC_obtenirListeSuivante(LC_ListeChainee lc);

/**
  * \brief Permet de fixer un élement à la liste chainée, càd
  * affecter un élément dans la structure de la liste chainée
  * \author S.LEBEAUD
  * \param lc la liste chainée
  * \param Element l'élément que l'on veut fixer à lc
  * \param tailleElement la taille de l'espace mémoire occupé par l'élément
*/

void LC_fixerElement(LC_ListeChainee lc,Element,size_t tailleElement);

/**
  * \brief procedure qui permet d'affecter une Liste Chainée à la liste suivante d'une liste chainée
  * \author S.LEBEAUD
  * \param lc la liste chainée
  * \param lcSuivante la liste que l'on veux fixer comme liste suivante de lc
*/

void LC_fixerListeSuivante(LC_ListeChainee lc,LC_ListeChainee lcSuivante);

/**
  * \brief Procedure qui permet de suipprimer le dernière Element ajouter à une liste chainée
  * Le dernière élément est supprimer et la liste chainée devient sa liste suivante.
  * \author S.LEBEAUD
  * \param lc un pointeur sur la liste
*/

void LC_supprimerTete(LC_ListeChainee* lc);

/**
  * \brief Procedure qui permet de supprimer entièrement une liste chainée
  * \author S.LEBEAUD
  * \param lc un pointeur sur la liste chainée à supprimer
*/

void LC_supprimer(LC_ListeChainee*);

#endif
