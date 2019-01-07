/**
 * \file ArbreBinaire.h
 * \brief Implantation du TAD ArbreBinaire
 * \author Tanguy LECLERC
 */

#ifndef __ARBRE_BINAIRE__
#define __ARBRE_BINAIRE__
#include "ListeChainee.h" //définition de Element

/**
 * \brief Un arbre binaire est un pointeur sur un noeud et
 * un noeud est composé d'un élement et de deux fils (droit et gauche).
 * Ici on défini un arbre binaire générique.
 */
typedef struct AB_Noeud* ArbreBinaire;
typedef struct AB_Noeud{
  Element lElement;
  ArbreBinaire filsGauche;
  ArbreBinaire filsDroit;
} AB_Noeud;

/**
 * \brief Création d'un arbre binaire vide.
 * \author T.LECLERC
 * \return Un arbre binaire vide.
 */
ArbreBinaire AB_arbreBinaire();
/**
 * \brief Allocation d'éspace mémoire pour un arbre binaire.
 * \author T.LECLERC
 * \return Un arbre binaire utilisable avec un espace mémoire modifiable.
 */
ArbreBinaire AB_allouer(void);
/**
 * \brief Fonction pour vérifier si un arbre est vide.
 * \author T.LECLERC
 * \param  a L'arbre dont on veut savoir si il est vide.
 * \return Vrai si l'arbre est vide et Faux sinon.
 */
bool AB_estVide(ArbreBinaire a);
/**
 * \brief Permet de lier deux arbres binaires à une racine .
 * \author T.LECLERC
 * \param fg l'arbre binaire qui sera le fils gauche.
 * \param fd l'arbre binaire qui sera le fils droit.
 * \param element l'élément que contiendra la racine.
 * \param tailleElement taille de l'élément que contiendra la racine, ignoré si element==NULL
 * \return Un nouvel arbre binaire
 */
ArbreBinaire AB_ajouterRacine(ArbreBinaire fg, ArbreBinaire fd, Element element,size_t tailleElement);
/**
 * \brief Permet d'obtenir l'élément de la racine .
 * \author T.LECLERC
 * \param a l'arbre dont on veux l'élément.
 * \return L'élément de l'arbre.
 */
Element AB_obtenirElement(ArbreBinaire a);
/**
 * \brief Fixe l'élément d'un arbre.
 * \author T.LECLERC
 * \param a l'arbre dont on veut fixer l'élément.
 * \param element l'élément que l'on veut fixer.
 * \param tailleElement taille de l'élément que l'on veut fixer, ignoré si element==NULL
 */
void AB_fixerElement(ArbreBinaire a,Element element,size_t tailleElement);
/**
 * \brief Permet d'obtenir le fils gauche d'un arbre binaire.
 * \author T.LECLERC
 * \param a l'arbre dont on veut le fils gauche
 * \return Le fils gauche
 */
ArbreBinaire AB_obtenirFilsGauche(ArbreBinaire a);
/**
 * \brief Permet d'obtenir le fils droit d'un arbre binaire.
 * \author T.LECLERC
 * \param a l'arbre dont on veut le fils droit
 * \return Le fils droit
 */
ArbreBinaire AB_obtenirFilsDroit(ArbreBinaire a);
/**
 * \brief Permet de fixer le fils droit d'un arbre binaire.
 * \author T.LECLERC
 * \param a l'arbre dont on veut fixer le fils droit.
 */
void AB_fixerFilsGauche(ArbreBinaire a, ArbreBinaire ag);
/**
 * \brief Permet de fixer le fils gauche d'un arbre binaire.
 * \author T.LECLERC
 * \param a l'arbre dont on veut fixer le fils gauche.
 */
void AB_fixerFilsDroit(ArbreBinaire a, ArbreBinaire ad);
/**
 * \brief Permet de supprimer la racine d'un arbre et de rediriger deux arbres binaires vers ses fils pour les utiliser.
 * \author T.LECLERC
 * \param *a pointeur sur l'arbre dont on veut supprimer la racine.
 * \param *fg pointeur sur un arbre binaire qui deviendra le pointeur vers le fils gauche de l'arbre.
 * \param *fd pointeur sur un arbre binaire qui deviendra le pointeur vers le fils droit de l'arbre.
 */
void AB_supprimerRacine(ArbreBinaire* a, ArbreBinaire* fg, ArbreBinaire* fd);
/**
 * \brief Permet de supprimer un arbre binaire.
 * \author T.LECLERC
 * \param *a pointeur sur l'arbre que l'on veut supprimer.
 */
void AB_supprimer(ArbreBinaire* a);


#endif
