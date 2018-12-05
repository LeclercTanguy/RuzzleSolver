#ifndef __Mot__
#define __Mot__
#include "Dictionnaire.h"


typedef Lettre* ListeChaineeDeLettres;
typedef struct Lettre {
  char caractere;
  ListeChaineeDeLettres lettreSuivante;
} Lettre;

typedef struct Mot {
  ListeChaineeDeLettres lettres;
  int longueur;
} Mot;


Mot chaineEnMot (Dictionnaire dico, *char chaine);
char motEnChaine (Mot lemot);
unsigned int longueur (Mot lemot);
void ajouterLettre(Mot lemot, char lettre, Dictionnaire dico);
void retirerLettre(Mot lemot)
#endif
