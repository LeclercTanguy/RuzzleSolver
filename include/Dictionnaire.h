#ifndef __DICTIONNAIRE__
#define __DICTIONNAIRE__

typedef struct Dictionnaire Dictionnaire;
struct Dictionnaire{
  char lettre;
  Dictionnaire *lettreSuivante; // pointeur vers la première lettre dans l'ordre alphabétique pouvant remplacer la dernière lettre du préfixe
  Dictionnaire *suffixe; //pointeur vers la première lettre pouvant être ajoutée au mot
};

#include "Mot.h"

Dictionnaire* creerDictionnaire(char *fichierDictionnaire);
void ajouterMot(Dictionnaire* dico, char *leMot);
void supprimerMot(Dictionnaire* dico, Mot motASupprimer);
int estUnPrefixe(Dictionnaire dico, char *chaine);
int estUnMot(Dictionnaire dico, Mot prefixe);
Ensemble obtenirLettresSuivantes(Dictionnaire dico, Mot prefixe); //Ensemble de Caractères, à définir
void sauvegarder(Dictionnaire dico, char *nomFichier);
int charger(char *nomFichier, Dictionnaire *dico);
#endif
