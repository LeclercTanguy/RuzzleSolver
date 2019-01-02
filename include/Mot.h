#ifndef __MOT__
#define __MOT__
#include "ListeChainee.h"

typedef struct Mot{
  LC_ListeChainee lettres; //Liste chaînée de Mot_Lettre, commençant par la dernière lettre du mot
  unsigned int taille;
} Mot;

#include "Dictionnaire.h"

typedef struct Mot_Lettre{
  char lettre;
  Dictionnaire refDico; //pointeur vers le nœud correspondant dans le dictionnaire
                        //à générer avec DC_obtenirReferenceLettre(refPrécédente,lettreÀAjouter)
}Mot_Lettre;

/*
  * \brief Fonction qui renvoie un Mot vide
  * \author Simon LEBEAUD
  * \version 1.0
*/

Mot Mot_creerMot (void);

/*
  * \brief fonction permettant de savoir si le Mot est vide ou non
  * \author Simon LEABEAUD
  * \version 1.0
  * \param leMot de type Mot
  * \return TRUE si le Mot est Vide
  *         FALSE si il ne l'est pas
*/

bool Mot_estVide(Mot leMot);

/*
  * \brief Procedure d'encapsulation permettant d'obtenir la variable taille d'un type Mot
  * \author Simon LEABEAUD
  * \version 1.0
  * \param leMot de type Mot
  * \return unsigned int qui est la valeur de la variable taille de leMot
*/

unsigned int Mot_obtenirTaille(Mot leMot);

/*
  * \brief permet d'obtenir la dernière lettre ajouté dans un Mot
  * \param leMot de type Mot
  * \return dernier caractère contenue dans la liste chainée contenue dans un Mot
*/


char Mot_obtenirDerniereLettre(Mot leMot);

/*
  * \brief Permet d'obtenir le noeud de l'arbre Dictionnaire de la dernière lettre d'un Mot
  * \author Simon LEABEAUD
  * \param  leMot de type Mot
  * \return Dictionnaire qui est l'arbre binaire situer au noeud où ce trouve la dernière lettre du mot
*/

Dictionnaire Mot_obtenirDerniereReferenceDictionnaire(Mot leMot);

/*
  * \brief Permet d'ajouter une lettre à un Mot
  * \author Simon LEABEAUD
  * \param un pointeur sur le mot à qui on veut ajouter une lettre
  * \param la caractère que l'on veut Ajouter
  * \param le dictionnaire contant ce Mot
  * \return 1 si il y a une erreur
  *         0 sinon
*/

int Mot_ajouterLettre(Mot *leMot, char lettre, Dictionnaire dico);

/*
  * \brief retirer la dernière lettre ajouter dans un mot
  * \author Simon LEABEAUD
  * \param pointeur sur le mot auquel on veut retirer la dernière lettre
*/

void Mot_retirerLettre(Mot *leMot);

/*
  * \brief supprimer un mot
  * \author Simon LEABEAUD
  * \param pointeur sur le mot à supprimer
*/

void Mot_supprimerMot(Mot* leMot);

/*
  * \brief permet mettre une chaine sous la forme d'une variable de type Mot
  * \author Simon LEABEAUD
  * \version 1.2
  * \param Dictionnaire contenant le mot
  * \param la chaine de caractère à ajouter
*/

Mot Mot_chaineEnMot (Dictionnaire dico, char *chaine);

/*
  * \brief transforme un Mot en chaine de caractère
  * \author Simon LEABEAUD
  * \param leMot de type Mot
  * \return chaine de caractère contenue dans la liste chainee de la variable de type Mot
*/

char* Mot_motEnChaine (Mot leMot);

#endif
