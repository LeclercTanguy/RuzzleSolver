#ifndef __DICTIONNAIRE__
#define __DICTIONNAIRE__

// typedef struct Dictionnaire Dictionnaire;
// struct Dictionnaire{
//   char lettre;
//   Dictionnaire *lettreSuivante; // pointeur vers la première lettre dans l'ordre alphabétique pouvant remplacer la dernière lettre du préfixe
//   Dictionnaire *suffixe; //pointeur vers la première lettre pouvant être ajoutée au mot
// };
#include "Ensemble.h"
#include "ArbreB.h"

typedef ArbreBinaire Dictionnaire;

#include "Mot.h"

Dictionnaire DC_creerDictionnaire(char *fichierDictionnaire);
void DC_ajouterMot(Dictionnaire* dico, char *leMot);
void DC_supprimerMot(Dictionnaire* dico, Mot motASupprimer);
int DC_estUnPrefixe(Dictionnaire dico, char *chaine);
int DC_estUnMot(Dictionnaire dico, Mot prefixe);
Ensemble DC_obtenirLettresSuivantes(Dictionnaire dico, Mot prefixe); //Ensemble de Caractères, à définir
void DC_sauvegarder(Dictionnaire dico, char *nomFichier);
int DC_charger(char *nomFichier, Dictionnaire *dico);
#endif
