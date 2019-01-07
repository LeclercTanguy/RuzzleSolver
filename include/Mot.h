/**
 *\file Mot.h
 *\brief Implantation du TAD Mot
 *\author Simon LEBEAUD
 */

#ifndef __MOT__
#define __MOT__
#include "ListeChainee.h"

/**
* \brief permet de représenter un mot du Dictionnaire
*/
typedef struct Mot{
  LC_ListeChainee lettres; /**< Liste chaînée de Mot_Lettre, commençant par la dernière lettre du mot */
  unsigned int taille; /**< la longueur du mot*/
} Mot;

#include "Dictionnaire.h"

/**
* \brief permet de représenter une lettre d'un Mot
*/
typedef struct Mot_Lettre{
  char lettre; /**< la lettre du Mot */
  Dictionnaire refDico; /**< un pointeur vers le nœud correspondant dans le dictionnaire
                        à générer avec DC_obtenirReferenceLettre(refPrécédente,lettreÀAjouter)*/
}Mot_Lettre;

/*
  * \brief Fonction qui renvoie un Mot vide (ne contenant aucune lettre)
  * \author Simon LEBEAUD
  * \version 1.0
*/
Mot Mot_creerMot (void);

/*
  * \brief fonction permettant de savoir si le Mot est vide ou non
  * \author Simon LEBEAUD
  * \version 1.0
  * \param leMot le mot à tester
  * \return TRUE si le Mot est Vide,
  *         FALSE si il ne l'est pas
*/

bool Mot_estVide(Mot leMot);

/*
  * \brief Procedure d'encapsulation permettant d'obtenir la variable taille d'un type Mot
  * \author Simon LEABEAUD
  * \version 1.0
  * \param leMot le mot dont on veut connaître la taille
  * \return la longueur du mot
*/

unsigned int Mot_obtenirTaille(Mot leMot);

/*
  * \brief permet d'obtenir la dernière lettre ajoutée dans un Mot
  * \param leMot le mot dont on veut obtenir la dernière lettre
  * \return le dernier caractère du mot
*/
char Mot_obtenirDerniereLettre(Mot leMot);

/*
  * \brief Permet d'obtenir le nœud de l'arbre Dictionnaire correspondant à la dernière lettre d'un Mot
  * \author Simon LEBEAUD
  * \param  leMot le mot dont on veux obtenir la dernière référence
  * \return un Dictionnaire positionné à la dernière lettre du mot
*/
Dictionnaire Mot_obtenirDerniereReferenceDictionnaire(Mot leMot);

/*
  * \brief Permet d'ajouter une lettre à un Mot
  * \author Simon LEBEAUD
  * \param leMot un pointeur sur le mot à qui on veut ajouter une lettre
  * \param lettre le caractère que l'on veut Ajouter
  * \param dico le dictionnaire contenant ce Mot
  * \return 1 si il y a une erreur
  *         0 sinon
*/
int Mot_ajouterLettre(Mot *leMot, char lettre, Dictionnaire dico);

/*
  * \brief permet de retirer la dernière lettre ajoutée dans un mot
  * \author Simon LEBEAUD
  * \param leMot pointeur sur le mot auquel on veut retirer la dernière lettre
*/
void Mot_retirerLettre(Mot *leMot);

/*
  * \brief permet de supprimer entièrement un mot
  * \author Simon LEBEAUD
  * \param leMot pointeur sur le mot à supprimer
*/
void Mot_supprimerMot(Mot* leMot);

/*
  * \brief permet de mettre une chaîne de caractère sous la forme d'une variable de type Mot
  * \author Simon LEBEAUD
  * \version 1.2
  * \param dico Dictionnaire contenant le mot
  * \param chaine la chaîne de caractère à ajouter
  * \warning le mot à transformer doit être présent dans le Dictionnaire fourni
  * \return le Mot associé à la chaîne
*/

Mot Mot_chaineEnMot (Dictionnaire dico, char* chaine);

/*
  * \brief transforme un Mot en chaîne de caractère
  * \author Simon LEBEAUD
  * \param leMot le mot que l'on veut mettre en chaîne
  * \return la chaîne de caractère correspondant au mot
*/
char* Mot_motEnChaine (Mot leMot);

#endif
