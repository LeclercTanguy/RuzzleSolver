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

LC_ListeChainee Mot_obtenirLesLettres(Mot leMot){
  return leMot.lettres;
}

bool Mot_estVide(Mot leMot){
  return LC_estVide(Mot_obtenirLesLettres(leMot));
}

unsigned int Mot_obtenirTaille(Mot leMot){
  return leMot.taille;
}

char Mot_obtenirLettre(Mot_Lettre motLettre){
  return motLettre.lettre;
}

Dictionnaire Mot_obtenirReferenceDictionnaire(Mot_Lettre motLettre){
  return motLettre.refDico;
}

char Mot_obtenirDerniereLettre(Mot leMot){
  assert(!Mot_estVide(leMot));
  Mot_Lettre laLettre = *(Mot_Lettre*)LC_obtenirElement(Mot_obtenirLesLettres(leMot));
  return Mot_obtenirLettre(laLettre);
}

Dictionnaire Mot_obtenirDerniereReferenceDictionnaire(Mot leMot){
  if (!Mot_estVide(leMot)) {
    Mot_Lettre laLettre = *(Mot_Lettre*)LC_obtenirElement(Mot_obtenirLesLettres(leMot));
    return Mot_obtenirReferenceDictionnaire(laLettre);
  } else {
    return NULL;
  }
}

int Mot_ajouterLettre(Mot *leMot, char lettre, Dictionnaire dico){
  int err = 0;
  Mot_Lettre motLettre;
  LC_ListeChainee laListeDeLettre = Mot_obtenirLesLettres(*leMot);
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
  LC_ListeChainee laListeDeLettre = Mot_obtenirLesLettres(*leMot);
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
  LC_ListeChainee laListeDeLettre = Mot_obtenirLesLettres(leMot);
  Mot_Lettre motLettre;
  while (i>0) {
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
