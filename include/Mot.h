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
  * \param 
  * \param
*/

unsigned int Mot_obtenirTaille(Mot leMot);
char Mot_obtenirDerniereLettre(Mot leMot);
Dictionnaire Mot_obtenirDerniereReferenceDictionnaire(Mot leMot);
int Mot_ajouterLettre(Mot *leMot, char lettre, Dictionnaire dico);
void Mot_retirerLettre(Mot *leMot);
void Mot_supprimerMot(Mot* leMot);
Mot Mot_chaineEnMot (Dictionnaire dico, char *chaine);
char* Mot_motEnChaine (Mot leMot);

#endif
