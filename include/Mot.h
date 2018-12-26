#ifndef __MOT__
#define __MOT__
#include "ListeChainee.h"

typedef struct {
  LC_ListeChainee *lettres; //Liste chaînée de Mot_Lettre, commençant par la dernière lettre du mot
  unsigned int longueur;
} Mot;

#include "Dictionnaire.h"

struct Mot_Lettre{
  char lettre;
  Dictionnaire refDico; //pointeur vers le nœud correspondant dans le dictionnaire
                        //à générer avec DC_obtenirReferenceLettre(refPrécédente,lettreÀAjouter)
};

Mot creerMot (void);
char Mot_obtenirLettre(Mot leMot);
void Mot_ajouterLettre(Mot *leMot, char lettre, Dictionnaire *dico);
void Mot_retirerLettre(Mot *leMot);
Mot chaineEnMot (Dictionnaire *dico, char *chaine);
char motEnChaine (Mot leMot);
unsigned int Mot_longueur (Mot leMot);

#endif
