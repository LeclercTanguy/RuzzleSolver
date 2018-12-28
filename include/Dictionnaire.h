/**
 * \file Dictionnaire.h
 * \brief Implantation du TAD Dictionnaire
 * \author Yves LE GUENNEC
 * \version alpha
 * \date décembre 2018
 */

#ifndef __DICTIONNAIRE__
#define __DICTIONNAIRE__

#include "Ensemble.h"
#include "ArbreBinaire.h"

/**
  * \brief Dictionnaire permet de stocker des mots, fournis sous forme de chaîne de caractères, et de savoir notamment si une chaîne de caractère donnée correspond à un mot, ou à un début de mot, contenu dans le dictionnaire.
  *
  * Le dictionnaire se base sur un ArbreBinaire, dont les éléments sont les lettres utilisées dans les mots contenus dans le dictionnaire.
  *
  * Un mot est donc formé d'un ensemble de caractères, obtenu en partant de la racine de l'arbre jusqu'au caractère de fin de chaîne (\0) au niveau d'une feuille
  *
  * Le fils gauche pointe vers la première lettre, dans l'ordre alphabétique, pouvant être ajoutée au préfixe pour former un nouveau préfixe. Le longueur du préfixe obtenu est donc augmentée de 1.
  *
  * Le fils droit pointe vers la première lettre, dans l'ordre alphabétique, pouvant remplacer la dernière lettre du préfixe pour former un nouveau préfixe. Le préfixe garde donc la même longueur.
*/
typedef ArbreBinaire Dictionnaire;

#include "Mot.h" //le type Mot nécessite que le type Dictionnaire soit déjà défini

/**
  * \brief Permet de créer un Dictionnaire vide
  * \return Un Dictionnaire vide, c'est-à-dire un pointeur à NULL
*/
Dictionnaire DC_creerDictionnaire(void);

/**
  * \brief Permet de savoir si le Dictionnaire est vide
  * \param dico Le Dictionnaire que l'on veut tester
  * \return VRAI (1) si le Dictionnaire est vide, FAUX (0) sinon
*/
int DC_estVide(Dictionnaire dico);

/**
  * \brief Permet d'ajouter un mot dans le Dictionnaire
  * \param dico un pointeur vers le Dictionnaire dans lequel on veut ajouter le mot
  * \param leMot la chaîne de caractères représentant le mot que l'on souhaite ajouter au Dictionnaire
*/
void DC_ajouterMot(Dictionnaire* dico, char* leMot);

/**
  * \brief Permet de supprimer un mot du Dictionnaire
  * \todo développer la procédure DC_supprimerMot
  * \param dico un pointeur vers le dictionnaire dans lequel on veut supprimer le mot
  * \param motASupprimer le Mot que l'on souhaite supprimer du Dictionnaire
*/
void DC_supprimerMot(Dictionnaire* dico, Mot motASupprimer);

/**
  * \brief Permet de supprimer un Dictionnaire
  * \param dico un pointeur vers le dictionnaire que l'on veut supprimer
*/
void DC_supprimer(Dictionnaire* dico);

/**
  * \brief Permet de savoir si une chaîne de caractères donnée est un préfixe d'un mot contenu dans le Dictionnaire
  * \param dico le Dictionnaire dans lequel on veut vérifier si la chaîne est un préfixe
  * \param chaine la chaîne pouvant être un préfixe d'un mot du Dictionnaire
  * \return VRAI (1) si la chaîne est un préfixe, FAUX (0) sinon
*/
int DC_estUnPrefixe(Dictionnaire dico, char* chaine);

/**
  * \brief Permet d'obtenir les références des lettres dans le Dictionnaire afin de convertir une chaîne en Mot
  * \param refPrecedente la référence du dernier caractère du préfixe contenu dans Mot.
  * Si le préfixe est vide, indiquer NULL
  * \param lettre le caractère à ajouter au Mot dont la référence de la dernière lettre est refPrecedente
  * \param dico le dictionnaire dans lequel sont stockés les mots
  * \return la référence (pointeur) correspondant à la lettre que l'on souhaite ajouter au Mot.
  * NULL si la lettre à ajouter ne figure pas dans le dictionnaire
*/
Dictionnaire DC_obtenirReferenceLettre(Dictionnaire refPrecedente, char lettre, Dictionnaire dico);

/**
  * \brief Permet de savoir si un préfixe est un mot complet du Dictionnaire
  * \param prefixe la suite de caractères (sous forme de Mot) que l'on veut tester.
  * Le dictionnaire est déjà accessible par l'intermédiaire du Mot
  * \return VRAI (1) si le préfixe est un mot du Dictionnaire, FAUX (0) sinon
*/
int DC_estUnMotComplet(Mot prefixe);

/**
  * \brief Permet de savoir quelles lettres peuvent être ajoutées au préfixe pour former un nouveau préfixe du Dictionnaire
  * \param prefixe la suite de caractères (sous forme de Mot) à laquelle on veut rajouter une lettre
  * Le dictionnaire est déjà accessible par l'intermédiaire du Mot
  * \return un ensemble de caractères pouvant être ajouté au préfixe pour former un nouveau préfixe
*/
Ens_Ensemble DC_obtenirLettresSuivantes(Mot prefixe);

/**
  * \brief Permet de sauvegarder le Dictionnaire dans un fichier
  * \param dico le Dictionnaire à sauvegarder
  * \param nomFichier le nom (ou chemin) du fichier dans lequel on veut sauvegarder le Dictionnaire
  * Si le fichier existe, son contenu sera écrasé
  * \return 0 en cas de succès, 1 si le fichier n'a pas pu être créé
*/
int DC_sauvegarder(Dictionnaire dico, char* nomFichier);

/**
  * \brief Permet de charger le Dictionnaire à partir d'un fichier
  * \param nomFichier le nom (ou chemin) du fichier contenant le Dictionnaire
  * \param dico le pointeur vers le dictionnaire à charger.
  * Si le Dictionnaire n'est pas vide, son contenu est écrasé
  * \return 0 en cas de succès, 1 si le fichier n'a pas pu être ouvert
*/
int DC_charger(char* nomFichier, Dictionnaire* dico);

#endif
