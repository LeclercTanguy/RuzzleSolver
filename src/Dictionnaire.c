#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "ArbreB.h"
#include "Ensemble.h"
#include "Dictionnaire.h"
#define TRUE 1
#define FALSE 0

Dictionnaire DC_creerDictionnaire(void) {
  return AB_arbreBinaire();
}

int DC_estVide(Dictionnaire dico) {
  return AB_estVide(dico);
}

void DC_ajouterMot_R(Dictionnaire* dico, char* leMot, int* finDuMot) {
  Dictionnaire temp;
  if (DC_estVide(*dico)) {
    //aucun nœud frère ni fils
    *dico = AB_ajouterRacine(AB_arbreBinaire(),AB_arbreBinaire(),leMot[0]);
  } else if (AB_obtenirElement(*dico)-leMot[0]<0) {
    //la lettre à insérer est plus grande, on passe au frère suivant
    temp = AB_obtenirFilsDroit(*dico);
    DC_ajouterMot_R(&temp,leMot,finDuMot);
    AB_fixerFilsDroit(*dico,temp);
  } else if (AB_obtenirElement(*dico)-leMot[0]>0) {
    //la lettre à insérer est plus petite, on insère le nœud avant le frère suivant
    *dico = AB_ajouterRacine(AB_arbreBinaire(),*dico,leMot[0]);
  }
  //si le nœud est déjà présent : rien à faire

  *finDuMot = *finDuMot || (leMot[0]=='\0');
  //pour ne pas recommencer à descendre quand on remonte les appels récursifs
  if (!(*finDuMot)) {
    //si on n'est pas à la fin du mot, on continue
    temp = AB_obtenirFilsGauche(*dico);
    DC_ajouterMot_R(&temp,leMot+1,finDuMot);
    AB_fixerFilsGauche(*dico,temp);
  }
}

void DC_ajouterMot(Dictionnaire* dico, char* leMot) {
  int finDuMot = FALSE;
  DC_ajouterMot_R(dico,leMot,&finDuMot);
}

void DC_supprimerMot(Dictionnaire dico, Mot motASupprimer) {

}

int DC_estUnPrefixe(Dictionnaire dico, char *chaine) {
  if (DC_estVide(dico)) {
    //la chaîne est plus longue que le plus long mot du dictionnaire
    return FALSE;
  } else if (chaine[0]=='\0') {
    return TRUE; //on est à la fin de la chaine, c'est donc un préfixe
  } else if (AB_obtenirElement(dico)==chaine[0]) {
    //le caractère est dans le dictionnaire, on passe au suivant
    return DC_estUnPrefixe(AB_obtenirFilsGauche(dico),chaine+1);
  } else if (AB_obtenirElement(dico)-chaine[0]<0) {
    //le caractère est plus grand, on essaye le frère suivant
    return DC_estUnPrefixe(AB_obtenirFilsDroit(dico),chaine);
  } else {
    //le caractère est plus petit, le début de la chaîne n'est pas dans le dictionnaire
    return FALSE;
  }
}

int DC_estUnMot(Dictionnaire dico, Mot prefixe) {
  return 0; //AB_obtenirElement(AB_obtenirFilsGauche(prefixe->lettres->refDico))=='\0';
}

Ensemble DC_obtenirLettresSuivantes(Dictionnaire dico, Mot prefixe) {
  return Ens_ensemble();
}

void DC_sauvegarder_R(Dictionnaire dico, FILE* data) {
  if (!DC_estVide(dico)) {
    //écrire élement
    fputc(AB_obtenirElement(dico),data);
    //écrire fils gauche
    DC_sauvegarder_R(AB_obtenirFilsGauche(dico),data);
    //écrire fils droit
    DC_sauvegarder_R(AB_obtenirFilsDroit(dico),data);
  } else {
    //si vide -> espace
    fputc('\n',data);
  }
}

int DC_sauvegarder(Dictionnaire dico, char* nomFichier) {
  FILE* data = fopen (nomFichier,"w");
  if (data!=NULL) {
    DC_sauvegarder_R (dico,data);
    return fclose(data);
  } else {
    return 1;
    printf("Impossible de créer le fichier de sauvegarde %s",nomFichier);
  }
}

int DC_charger(char *nomFichier, Dictionnaire dico) {
  return 0;
}
