#ifndef _DICTIONNAIRE_
#define _DICTIONNAIRE_
#include "Mot.h"

typedef Dictionnaire *Arbre;


void ajouterMot(Dictionnaire , Mot);
int estUnPrefixe(Dictionnaire,*char);
int estUnMot(Dictionnaire,Mot);
Ensemble obtenirLettresSuivantes(Dictionnaire,Mot);
void sauvegarder(Dictionnaire);
void charger(*char);
#endif
