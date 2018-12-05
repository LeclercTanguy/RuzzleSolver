#ifndef __MOT__
#define __MOT__
#include "Dictionnaire.h"

typedef struct Mot_Lettre Mot_Lettre;
struct Mot_Lettre{
  char lettre;
  Dictionnaire *refDico; //pointeur vers le nœud correspondant dans le dictionnaire
  Mot_Lettre *lettrePrecedente; //pointeur vers la lettre prédédente dans la mot
};

typedef struct {
  Mot_Lettre *lettres; //dernière lettre du mot
  unsigned int longueur;
} Mot;

Mot chaineEnMot (Dictionnaire *dico, char *chaine);
char motEnChaine (Mot leMot);
unsigned int Mot_longueur (Mot leMot);
void Mot_ajouterLettre(Mot *leMot, char lettre, Dictionnaire *dico);
void Mot_retirerLettre(Mot *leMot);

#endif
