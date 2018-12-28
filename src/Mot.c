#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "Mot.h"
#include "Dictionnaire.h"


Mot Mot_creerMot(void){
  Mot leMot;
  leMot.lettres = LC_listeVide();
  leMot.longueur = 0;
  return leMot;
}

int Mot_estVide(Mot leMot){
  return 0;
}

char Mot_obtenirLettre(Mot leMot){
  return (*(Mot_Lettre*)LC_obtenirElement(leMot.lettres)).lettre;
}

Dictionnaire Mot_obtenirReferenceDictionnaire(Mot leMot){
  return (*(Mot_Lettre*)LC_obtenirElement(leMot.lettres)).refDico;
}

void Mot_ajouterLettre(Mot *leMot, char lettre, Dictionnaire dico){

}

void Mot_retirerLettre(Mot *leMot){

}

Mot Mot_chaineEnMot (Dictionnaire *dico, char *chaine){
  return Mot_creerMot();
}

char* Mot_motEnChaine (Mot leMot){
  return "\0";
}

unsigned int Mot_longueur (Mot leMot){
  return 0;
}
