#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "ArbreBinaire.h"
#include "Ensemble.h"
#include "Dictionnaire.h"
#define TRUE 1
#define FALSE 0

Dictionnaire DC_creerDictionnaire(void) {
  return AB_arbreBinaire();
}

Dictionnaire* DC_allouer(void) {
  return (Dictionnaire*)AB_allouer();
}

int DC_estVide(Dictionnaire dico) {
  return AB_estVide(dico);
}

void DC_ajouterMot_R(Dictionnaire* dico, char* leMot, int* finDuMot) {
  Dictionnaire temp;
  if (DC_estVide(*dico)) {
    //aucun nœud frère ni fils
    *dico = AB_ajouterRacine(AB_arbreBinaire(),AB_arbreBinaire(),leMot,sizeof(char));
  } else if (*(char*)AB_obtenirElement(*dico)-leMot[0]<0) {
    //la lettre à insérer est plus grande, on passe au frère suivant
    temp = AB_obtenirFilsDroit(*dico);
    DC_ajouterMot_R(&temp,leMot,finDuMot);
    AB_fixerFilsDroit(*dico,temp);
  } else if (*(char*)AB_obtenirElement(*dico)-leMot[0]>0) {
    //la lettre à insérer est plus petite, on insère le nœud avant le frère suivant
    *dico = AB_ajouterRacine(AB_arbreBinaire(),*dico,leMot,sizeof(char));
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
  } else if (*(char*)AB_obtenirElement(dico)==chaine[0]) {
    //le caractère est dans le dictionnaire, on passe au suivant
    return DC_estUnPrefixe(AB_obtenirFilsGauche(dico),chaine+1);
  } else if (*(char*)AB_obtenirElement(dico)-chaine[0]<0) {
    //le caractère est plus grand, on essaye le frère suivant
    return DC_estUnPrefixe(AB_obtenirFilsDroit(dico),chaine);
  } else {
    //le caractère est plus petit, le début de la chaîne n'est pas dans le dictionnaire
    return FALSE;
  }
}

Dictionnaire DC_obtenirReferenceLettre_R(Dictionnaire dico, char lettre) {
  if (!DC_estVide(dico)) {
    if (*(char*)AB_obtenirElement(dico)==lettre) {
      //on a trouvé la bonne lettre
      return dico;
    } else if (*(char*)AB_obtenirElement(dico)-lettre<0) {
      //le caractère est plus grand, on essaye le frère suivant
      return DC_obtenirReferenceLettre(AB_obtenirFilsDroit(dico),lettre);
    } else {
      return NULL;  //la lettre n'est pas dans le dictionnaire
    }
  } else {
    return NULL; //la lettre n'est pas dans le dictionnaire (pas de fils droit)
  }
}

Dictionnaire DC_obtenirReferenceLettre(Dictionnaire refPrecedente, char lettre) {
  assert(!DC_estVide(refPrecedente));
  //la référence pointe vers un dictionnaire vide, on ne peut pas continuer
  Dictionnaire dico = AB_obtenirFilsGauche(refPrecedente);
  return DC_obtenirReferenceLettre_R(dico,lettre);
}

int DC_estUnMot(Dictionnaire dico, Mot prefixe) {
  return 0; //AB_obtenirElement(AB_obtenirFilsGauche(prefixe->lettres->refDico))=='\0';
}

Ens_Ensemble DC_obtenirLettresSuivantes(Dictionnaire dico, Mot prefixe) {
  Ens_Ensemble lettresSuivantes = Ens_ensemble();
  //Dictionnaire temp = AB_obtenirFilsGauche(prefixe);
  //AB_obtenirElement(AB_obtenirFilsGauche);
  return lettresSuivantes;
}

void DC_sauvegarder_R(Dictionnaire dico, FILE* data) {
  if (!DC_estVide(dico)) {
    //écrire élement
    fputc(*(char*)AB_obtenirElement(dico),data);
    //écrire fils gauche
    DC_sauvegarder_R(AB_obtenirFilsGauche(dico),data);
    //écrire fils droit
    DC_sauvegarder_R(AB_obtenirFilsDroit(dico),data);
  } else {
    //si vide -> \n (on peut donc stocker des mots avec des espaces)
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

void DC_charger_R(Dictionnaire* dico, FILE* data) {
  char c = fgetc(data);
  if (c!=EOF) { //tant que l'on est pas à la fin
    if (c!='\n') { //arbre non vide
      *dico = AB_ajouterRacine(DC_creerDictionnaire(),DC_creerDictionnaire(),&c,sizeof(char));
      //fils gauche
      Dictionnaire* arbreGauche = DC_allouer();
      DC_charger_R(arbreGauche,data);
      AB_fixerFilsGauche(*dico,*arbreGauche);
      //fils droit
      Dictionnaire* arbreDroit = DC_allouer();
      DC_charger_R(arbreDroit,data);
      AB_fixerFilsDroit(*dico,*arbreDroit);
    } else { //arbre vide
      *dico = DC_creerDictionnaire();
    }
  }
}

int DC_charger(char *nomFichier, Dictionnaire* dico) {
  FILE* data = fopen (nomFichier,"r");
  if (data!=NULL) {
    *dico = DC_creerDictionnaire();
    DC_charger_R(dico,data);
    return fclose(data);
  } else {
    return 1;
    printf("Impossible d'ouvrir le fichier %s",nomFichier);
  }
}
