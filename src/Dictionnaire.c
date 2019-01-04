#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "ArbreBinaire.h"
#include "Ensemble.h"
#include "Dictionnaire.h"

Dictionnaire DC_creerDictionnaire(void) {
  return AB_arbreBinaire();
}

Dictionnaire* DC_allouer(void) {
  return (Dictionnaire*)AB_allouer();
}

bool DC_estVide(Dictionnaire dico) {
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
  int finDuMot = false;
  DC_ajouterMot_R(dico,leMot,&finDuMot);
}

Dictionnaire DC_obtenirFilsPrecedent(Dictionnaire pere, Dictionnaire fils, Dictionnaire dico) {
  assert (!DC_estVide(fils));
  Dictionnaire frere;
  if (DC_estVide(pere)) {
    frere = dico;
  } else {
    frere = AB_obtenirFilsGauche(pere);
  }
  if (fils==frere) {
    return NULL; //pas de fils précédent
  } else {
    Dictionnaire filsPrecedent;
    while (fils!=frere) {
      filsPrecedent = frere;
      frere = AB_obtenirFilsDroit(frere);
    }
    return filsPrecedent;
  }
}

void DC_supprimerMot_R(Dictionnaire* dico, Mot* motASupprimer) {
  assert(!Mot_estVide(*motASupprimer));
  Dictionnaire fils = Mot_obtenirDerniereReferenceDictionnaire(*motASupprimer);
  Dictionnaire fg = AB_obtenirFilsGauche(fils);
  Dictionnaire fd = AB_obtenirFilsDroit(fils);
  if (DC_estVide(fg)) {
    // si il y a un fils gauche, on ne fait rien (la lettre appartient à d'autres mots)
    //on récupère le père
    Dictionnaire pere;
    Mot_retirerLettre(motASupprimer);
    if (!Mot_estVide(*motASupprimer)) {
      pere = Mot_obtenirDerniereReferenceDictionnaire(*motASupprimer);
    } else {
      pere = NULL;
    }
    //pour trouver le fils précédent
    Dictionnaire filsPrecedent = DC_obtenirFilsPrecedent(pere,fils,*dico);
    //on supprime la lettre de l'arbre
    AB_supprimerRacine(&fils,&fg,&fd);
    //s'il y a un fils précédent, on lui accroche le nouveau fils droit
    if (!DC_estVide(filsPrecedent)) {
      AB_fixerFilsDroit(filsPrecedent,fd);
    } else { //sinon (le fils était le premier), on accroche le nouveau fils gauche du père
      AB_fixerFilsGauche(pere,fd);
    }
    //si il reste encore des lettres dans le mot (et que le fils gauche était vide), on continue
    if (!Mot_estVide(*motASupprimer)) {
      DC_supprimerMot_R(dico,motASupprimer);
    }
  }
}

void DC_supprimerMot(Dictionnaire* dico, Mot* motASupprimer) {
  assert(DC_estUnMotComplet(*motASupprimer));
  //on ajoute le \0 au mot
  Mot_ajouterLettre(motASupprimer,'\0',*dico);
  //on supprime le mot du dictionnaire
  DC_supprimerMot_R(dico,motASupprimer);
  //on supprime le reste du mot (les références au dictionnaire ne sont plus valides)
  Mot_supprimerMot(motASupprimer);
}

void DC_supprimer(Dictionnaire* dico) {
  AB_supprimer(dico);
}

bool DC_estUnPrefixe(Dictionnaire dico, char* chaine) {
  if (DC_estVide(dico)) {
    //la chaîne est plus longue que le plus long mot du dictionnaire
    return false;
  } else if (chaine[0]=='\0') {
    return true; //on est à la fin de la chaine, c'est donc un préfixe
  } else if (*(char*)AB_obtenirElement(dico)==chaine[0]) {
    //le caractère est dans le dictionnaire, on passe au suivant
    return DC_estUnPrefixe(AB_obtenirFilsGauche(dico),chaine+1);
  } else if (*(char*)AB_obtenirElement(dico)-chaine[0]<0) {
    //le caractère est plus grand, on essaye le frère suivant
    return DC_estUnPrefixe(AB_obtenirFilsDroit(dico),chaine);
  } else {
    //le caractère est plus petit, le début de la chaîne n'est pas dans le dictionnaire
    return false;
  }
}

Dictionnaire DC_obtenirReferenceLettre_R(Dictionnaire dico, char lettre) {
  if (!DC_estVide(dico)) {
    if (*(char*)AB_obtenirElement(dico)==lettre) {
      //on a trouvé la bonne lettre
      return dico;
    } else if (*(char*)AB_obtenirElement(dico)-lettre<0) {
      //le caractère est plus grand, on essaye le frère suivant
      return DC_obtenirReferenceLettre_R(AB_obtenirFilsDroit(dico),lettre);
    } else {
      return NULL;  //la lettre n'est pas dans le dictionnaire
    }
  } else {
    return NULL; //la lettre n'est pas dans le dictionnaire (pas de fils droit)
  }
}

Dictionnaire DC_obtenirReferenceLettre(Dictionnaire refPrecedente, char lettre, Dictionnaire dico) {
  Dictionnaire dicoSuivant;
  if (DC_estVide(refPrecedente)) {
    dicoSuivant = dico;
  } else {
    dicoSuivant = AB_obtenirFilsGauche(refPrecedente);
  }
  return DC_obtenirReferenceLettre_R(dicoSuivant,lettre);
}

bool DC_estUnMotComplet(Mot prefixe) {
  assert(!Mot_estVide(prefixe));
  Dictionnaire refDico = Mot_obtenirDerniereReferenceDictionnaire(prefixe);
  return *(char*)AB_obtenirElement(AB_obtenirFilsGauche(refDico))=='\0';
}

Ens_Ensemble DC_obtenirLettresSuivantes(Mot prefixe) {
  assert(!Mot_estVide(prefixe));
  Ens_Ensemble lettresSuivantes = Ens_ensemble();
  Dictionnaire dico = Mot_obtenirDerniereReferenceDictionnaire(prefixe);
  char lettre;
  dico = AB_obtenirFilsGauche(dico);
  while (!DC_estVide(dico)) {
    lettre = *(char*)AB_obtenirElement(dico);
    if (lettre!='\0') {
      Ens_ajouter(&lettresSuivantes,&lettre,sizeof(char));
    }
    dico = AB_obtenirFilsDroit(dico);
  }
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
      Dictionnaire arbreGauche = DC_creerDictionnaire();
      DC_charger_R(&arbreGauche,data);
      AB_fixerFilsGauche(*dico,arbreGauche);
      //fils droit
      Dictionnaire arbreDroit = DC_creerDictionnaire();
      DC_charger_R(&arbreDroit,data);
      AB_fixerFilsDroit(*dico,arbreDroit);
    } else { //arbre vide
      *dico = DC_creerDictionnaire();
    }
  }
}

int DC_charger(char *nomFichier, Dictionnaire* dico) {
  FILE* data = fopen (nomFichier,"r");
  if (data!=NULL) {
    *dico = DC_creerDictionnaire();
    if (DC_estVide(*dico)) {
      *dico = DC_creerDictionnaire();
    } else {
      DC_supprimer(dico);
    }
    DC_charger_R(dico,data);
    return fclose(data);
  } else {
    return 1;
    printf("Impossible d'ouvrir le fichier %s",nomFichier);
  }
}
