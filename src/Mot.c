#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "Mot.h"
#include "Dictionnaire.h"
#include "ListeChainee.h"


Mot Mot_creerMot(void){
  Mot leMot;
  leMot.lettres = LC_listeVide();
  leMot.taille = 0;
  return leMot;
}

LC_ListeChainee Mot_obtenirLesElements(Mot leMot){
  return leMot.lettres;
}

char Mot_obtenirLettre(Mot_Lettre motLettre){
  return motLettre.lettre;
}


bool Mot_estVide(Mot leMot){
  return LC_estVide(Mot_obtenirLesElements(leMot));
}

Dictionnaire Mot_obtenirDerniereReferenceDictionnaire(Mot leMot){
  if (!Mot_estVide(leMot)) {
    return (*(Mot_Lettre*)LC_obtenirElement(Mot_obtenirLesElements(leMot))).refDico;
  } else {
    return NULL;
  }
}

unsigned int Mot_obtenirTaille(Mot leMot){
  return leMot.taille;
}

int Mot_ajouterLettre(Mot *leMot, char lettre, Dictionnaire dico){
  int err = 0;
  Mot_Lettre motLettre;
  LC_ListeChainee laListeDeLettre = Mot_obtenirLesElements(*leMot);
  Dictionnaire refPrecedente = Mot_obtenirDerniereReferenceDictionnaire(*leMot);
  motLettre.lettre = lettre;
  Dictionnaire  refDico = DC_obtenirReferenceLettre(refPrecedente,lettre,dico);
  if (refDico!=NULL) {
    motLettre.refDico = refDico;
  } else {
    err = 1;
  }
  LC_ajouter(&laListeDeLettre,&motLettre,sizeof(Mot_Lettre));
  leMot->lettres=laListeDeLettre;
  leMot->taille=Mot_obtenirTaille(*leMot)+1;
  return err;
}

void Mot_retirerLettre(Mot* leMot){
  assert(!Mot_estVide(*leMot));
  leMot->taille = Mot_obtenirTaille(*leMot)-1;
  LC_ListeChainee laListeDeLettre = Mot_obtenirLesElements(*leMot);
  LC_supprimerTete(&laListeDeLettre);
  leMot->lettres=laListeDeLettre;
}

void Mot_supprimerMot(Mot* leMot){
  while(!Mot_estVide(*leMot)){
    Mot_retirerLettre(leMot);
  }
}

char* Mot_motEnChaine(Mot leMot){
  int longueur = Mot_obtenirTaille(leMot);
  char* chaine = (char*)malloc((longueur+1)*sizeof(char));
  int i=longueur;
  LC_ListeChainee laListeDeLettre = Mot_obtenirLesElements(leMot);
  Mot_Lettre motLettre;
  while (i>=0) {
    motLettre = *(Mot_Lettre*)LC_obtenirElement(laListeDeLettre);
    chaine[i] = Mot_obtenirLettre(motLettre);
    i--;
    laListeDeLettre = LC_obtenirListeSuivante(laListeDeLettre);
  }
  chaine[longueur+1]='\0';
  return chaine;
}

Mot Mot_chaineEnMot(Dictionnaire dico, char *chaine){
  assert(DC_estUnPrefixe(dico,chaine));
  Mot leMot = Mot_creerMot();
  int i = 0;
  while (chaine[i]!='\0'){
    Mot_ajouterLettre(&leMot,chaine[i],dico);
    i++;
  }
  return leMot;
}
