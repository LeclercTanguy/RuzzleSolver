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
  * \brief On déclare un type Element qui est un pointeur vers un espace mémoire
  * contenant un élément de type et donc de taille inconnue, afin d'avoir
  * un TAD Liste Chainee générique.
*/
typedef void* Element;

/**
  * \brief LC_ListeChainee est un pointeur vers une structure LC_Noeud
*/
typedef struct LC_Noeud* LC_ListeChainee;

/**
  * \brief nœud d'une liste chaînée
*/
typedef struct LC_Noeud {
  Element element; /**< un pointeur générique vers l'élément du nœud */
  LC_ListeChainee listeSuivante; /**<  un pointeur vers le nœud suivant */
} LC_Noeud;

/**
  * \brief création d'une Liste Chainee vide
  * \author S.LEBEAUD
  * \return une liste chainée vide (NULL)
*/
LC_ListeChainee LC_listeVide(void);

/**
  * \brief Permet d'allouer de l'espace mémoire pour stocker un nœud de la liste chaînée
  * L'espace mémoire pointé par Element est alloué lors de l'appel à LC_fixerElement
  * Le pointeur Element et la liste suivante sont initialisés à NULL.
  * \author S.LEBEAUD
  * \return une liste Chainee initialisée sans élément ni liste suivante
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
  * Il s'agit donc d'un pointeur vers le type des données contenues dans la liste chaînée
  * \param tailleElement la taille occupée en mémoire par le type d'élément stocké
  * dans la liste chaînée et pointé par unElement.
  * \return un booléen, VRAI si l'élément est présent, FAUX sinon
*/
bool LC_estPresent(LC_ListeChainee lc,Element unElement,size_t tailleElement);

/**
  * \brief permet d'ajouter un élément à une liste chainee
  * \author S.LEBEAUD
  * \param lc un pointeur sur la liste chainée à laquelle on veut ajouter un élement
  * \param elementAAjouter un pointeur vers l'élément que l'on veux ajouter
  * L'espace mémoire pointé par elementAAjouter sera copié lors de l'insertion.
  * \param tailleElement la taille de l'espace mémoire occupé par le type de l'élément
  à insérer.
*/
void LC_ajouter(LC_ListeChainee* lc,Element elementAAjouter,size_t tailleElement);

/**
  * \brief Permet d'obtenir le dernier élement ajouté à une liste chainée
  * \author S.LEBEAUD
  * \param  lc, une listechainne non vide
  * \return un pointeur vers le dernier élément ajouté à la liste
  * \warning vous devez donc transtyper cet Element vers un pointeur du type utilisé avant
  * de vous en servir. Par exemple, pour une liste chaînée d'entier, vous auriez
  * int a = *(int*)LC_obtenirElement(lc);
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
  * affecter un élément dans la structure de la liste chainée.
  * Si l'espace mémoire occupé par l'élément à insérer n'est pas alloué,
  * malloc est appelé et l'élément copié dans ce nouvel espace mémoire.
  * Si cet espace était déjà alloué, l'élément est juste copié.
  * \author S.LEBEAUD
  * \param lc la liste chainée
  * \param Element l'élément que l'on veut fixer à lc
  * C'est un pointeur vers le type de donnée à insérer, de taille tailleElement
  * \param tailleElement la taille de l'espace mémoire occupé par le type pointé par Element
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
  * \brief Procedure qui permet de supprimer le dernier Element ajouté à une liste chainée
  * Le dernier élément est supprimé et la liste chainée devient sa liste suivante.
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
