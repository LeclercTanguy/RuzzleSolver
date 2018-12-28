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

Mot creerMot (void);
unsigned int Mot_obtenirTaille(Mot leMot);
LC_ListeChainee Mot_obtenirLesElements(Mot leMot);
char Mot_obtenirLettre(Mot_Lettre motLettre);
Mot* Mot_allouer(size_t taille);
void Mot_ajouterLettre(Mot *leMot, char lettre, Dictionnaire *dico);
void Mot_retirerLettre(Mot *leMot);
Mot chaineEnMot (Dictionnaire *dico, char *chaine);
char* motEnChaine (Mot leMot);

#endif
