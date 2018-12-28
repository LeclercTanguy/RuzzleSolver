#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "Mot.h"
#include "Dictionnaire.h"


Mot Mot_creerMot(void){
  Mot leMot;
  leMot.lettres = NULL;
  leMot.taille = 0;
  return leMot;
}

Mot* Mot_allouer(size_t taille) {
  return (Mot*)LC_allouer(taille);
}

unsigned int Mot_obtenirTaille(Mot leMot){
  return leMot.taille;
}

LC_ListeChainee Mot_obtenirLesElements(Mot leMot){
  return leMot.lettres;
}

char Mot_obtenirLettre(Mot_Lettre motLettre){
  return motLettre.lettre;
}

void Mot_ajouterLettre(Mot *leMot, char lettre, Dictionnaire *dico){
  Mot_Lettre motLettre;
  LC_ListeChainee laListeDeLettre = Mot_obtenirLesElements(*leMot);
  motLettre.lettre = lettre;
  motLettre.refDico = DC_obtenirReferenceLettre(*dico,lettre);
  LC_ajouter(&laListeDeLettre,&motLettre,Mot_obtenirTaille(*leMot));
  leMot->taille=Mot_obtenirTaille(*leMot)+1;
}

void Mot_retirerLettre(Mot* leMot){
  assert(!LC_estVide(Mot_obtenirLesElements(*leMot)));
  leMot->taille = Mot_obtenirTaille(*leMot)-1;
  LC_ListeChainee laListeDeLettre = Mot_obtenirLesElements(*leMot);
  LC_supprimerTete(&laListeDeLettre);
}

char* motEnChaine(Mot leMot){
  char* chaine[Mot_obtenirTaille(leMot)+1];
  int i=0;
  LC_ListeChainee laListeDeLettre = Mot_obtenirLesElements(leMot);
  Mot_Lettre motLettre;
  do{
    motLettre = *(Mot_Lettre*)LC_obtenirElement(laListeDeLettre);
    *chaine[i] = Mot_obtenirLettre(motLettre);
    i++;
    laListeDeLettre = LC_obtenirListeSuivante(laListeDeLettre);
  }while(!LC_estVide(laListeDeLettre));
  return *chaine;
}

Mot chaineEnMot(Dictionnaire *dico, char *chaine){
  Mot *leMot = Mot_allouer(sizeof(chaine));
  int i = 0;
  do{
    Mot_ajouterLettre(leMot,chaine[i],dico);
    i++;
  }while(chaine[i]!='\0');
  return *leMot;
}
