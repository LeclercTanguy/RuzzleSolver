#include <string.h>
#include <stdio.h>
#include "Ruzzle.h"
#include "ABR.h"
#include "Grille.h"
#include "Dictionnaire.h"
#include "Mot.h"
#include "CasesContigues.h"
#include "Ensemble.h"
#include "tools.h"
#include "ListeChainee.h"

SolutionRuzzle RZ_creerSolutionRuzzle(void){
  SolutionRuzzle solution;
  solution.motsTrouvesParPoints = ABR_creer();
  solution.motsTrouvesParMot = ABR_creer();
  solution.nbMots = 0;
  return solution;
}

int RZ_chaineEnBonus(char* chaine, Bonus* leBonus) {
  if (strlen(chaine)>=2) {
      if (strncmp(chaine,"  ",2)==0) {
        *leBonus = AB; //pas de bonus
        return 0;
      } else if ((strncmp(chaine,"LD",2)==0) || (strncmp(chaine,"DL",2)==0)){
        *leBonus = LD; //lettre compte double
        return 0;
      } else if ((strncmp(chaine,"LT",2)==0) || (strncmp(chaine,"TL",2)==0)){
        *leBonus = LT; //lettre compte triple
        return 0;
      } else if ((strncmp(chaine,"MD",2)==0) || (strncmp(chaine,"DW",2)==0)){
        *leBonus = MD; //mot compte double
        return 0;
      } else if ((strncmp(chaine,"MT",2)==0) || (strncmp(chaine,"TW",2)==0)) {
        *leBonus = MT; //mot compte triple
        return 0;
      } else {
        return 1;
      }
  } else {
      return -1; //pas assez de caractères pour déterminer le bonus
  }
}

int RZ_chaineEnGrille(char* chaine, Grille* grilleRuzzle) {
  int err = 0;
  if (strlen(chaine)==16*4) {
    unsigned short numCase = 0;
    unsigned short posX,posY;
    *grilleRuzzle = G_grille();
    Case laCase;
    char lettre;
    while ((numCase<16) && !err) {
      numCase++;
      posX = numCase % 4;
      if (posX==0) {posX=4;}
      posY = ((numCase-1)/4)+1;
      laCase = G_obtenirCase(*grilleRuzzle,posX,posY);
      //on fixe la lettre
      lettre = chaine[(numCase-1)*4];
      if ((lettre>='A') && (lettre<='Z')) {
        CASE_fixerLettre(&laCase,lettre);
      } else {
        err = 1;
      }
      //si tout est bon, on fixe le nombre de points de la case
      char nbPoints = chaine[(numCase-1)*4+1];
      if (!err && (nbPoints>='0') && (nbPoints<='9')) {
        nbPoints = nbPoints - '0'; //on convertit le caractère en chiffre
        CASE_fixerNbPoints(&laCase,(unsigned short)nbPoints);
      } else {
        err = 1;
      }
      //si tout est bon, on fixe le bonus de la case
      if (!err) {
        Bonus bonus;
        err = RZ_chaineEnBonus(chaine+(numCase-1)*4+2,&bonus); //on convertit les 2 caractères restant en Bonus
        if (!err) {
          CASE_fixerBonus(&laCase,bonus);
          //et on remet la case dans la grille
          G_fixerCase(grilleRuzzle,laCase,posX,posY);
        }
      }
    }
  } else {
    err = -1;
  }
  return err;
}

void RZ_trouverMots(unsigned short posX, unsigned short posY, Dictionnaire dico, Grille* g, Mot* prefixe, CasesContigues* cheminRuzzle, SolutionRuzzle* resultat) {
  G_debutUtilisation(g, posX, posY); // la case est marquée comme utilisée
  // Liste des lettres possibles
  Ens_Ensemble lettresPossibles = DC_obtenirLettresSuivantes(*prefixe);
  LC_ListeChainee listeLettresPossibles = Ens_obtenirLesElements(lettresPossibles);
  // Liste des cases adjacentes à partir de l'ensemble
  Ens_Ensemble casesAdjacentesNonUtilisees = RZ_casesAdjacentesNonUtilisees(posX, posY, *g);
  LC_ListeChainee listeCasesAdjacentesNonUtilisees = Ens_obtenirLesElements(casesAdjacentesNonUtilisees);

  while (!LC_estVide(listeCasesAdjacentesNonUtilisees)){
    Case  maCase=*(Case*)LC_obtenirElement(listeCasesAdjacentesNonUtilisees);
    char maLettre = CASE_obtenirLettre(maCase);
    if (LC_estPresent(listeLettresPossibles, &maLettre, sizeof(char))){ //Si la lettre de la case adjacente fait partie des lettres possibles
      Mot_ajouterLettre(prefixe,CASE_obtenirLettre(maCase),dico);
      CC_ajouterCase(cheminRuzzle,maCase);
      if (DC_estUnMotComplet(*prefixe)){
        RZ_insererMotResultat(*cheminRuzzle, resultat);
      }
      RZ_trouverMots(CASE_obtenirPositionX(maCase), CASE_obtenirPositionY(maCase), dico, g, prefixe, cheminRuzzle, resultat);
      Mot_retirerLettre(prefixe);
      CC_supprimerCase(cheminRuzzle);
    }
  }
  G_finUtilisation(g, posX, posY);
}

void RZ_afficherResultat_R(ABR arbreResultat){
  if(!ABR_estVide(arbreResultat)){
    RZ_afficherResultat_R(AB_obtenirFilsGauche(arbreResultat));
    printf("%p\n",AB_obtenirElement(arbreResultat));
    RZ_afficherResultat_R(AB_obtenirFilsDroit(arbreResultat));
  }
}


void RZ_afficherResultat(SolutionRuzzle resultat) {
  RZ_afficherResultat_R(resultat.motsTrouvesParPoints);
}

Ens_Ensemble RZ_casesAdjacentesNonUtilisees(unsigned short posX, unsigned short posY, Grille g) {
  return Ens_ensemble();
}

void RZ_insererMotResultat(CasesContigues cheminRuzzle, SolutionRuzzle* resultat) {
  //création du MotRuzzle correspondant
  MotRuzzle nouveauMot;
  nouveauMot.mot = CC_CasesContiguesEnChaine(cheminRuzzle);
  nouveauMot.nbPoints = CC_totalPointsCasesContigues(cheminRuzzle);
  //on regarde si le mot est déjà présent dans les mots trouvés
  MotRuzzle* motDansResultat = (MotRuzzle*)(ABR_estPresentAvecReference(resultat->motsTrouvesParMot,&nouveauMot,RZ_comparerMotRuzzleParMot));
  if (motDansResultat!=NULL) { //on a déjà trouvé ce mot précédemment
    if (RZ_comparerMotRuzzleParPoints(motDansResultat,&nouveauMot)>0) {
      //si le nombre de points est mieux, on remplace dans l'arbre
      memcpy(motDansResultat,&nouveauMot,sizeof(MotRuzzle));
      //évite de supprimer l'ancien puis d'ajouter le nouveau, opération plus couteuse en temps
      //on le change aussi dans l'arbre classé par points
      motDansResultat = (MotRuzzle*)(ABR_estPresentAvecReference(resultat->motsTrouvesParPoints,&nouveauMot,RZ_comparerMotRuzzleParPoints));
      memcpy(motDansResultat,&nouveauMot,sizeof(MotRuzzle));
    } //sinon on ne change rien
  } else { //sinon on l'ajoute à la liste des mots trouvés
    (resultat->nbMots)++;
    ABR_inserer(&(resultat->motsTrouvesParPoints),&nouveauMot,RZ_comparerMotRuzzleParPoints);
    ABR_inserer(&(resultat->motsTrouvesParMot),&nouveauMot,RZ_comparerMotRuzzleParMot);
  }
}

int RZ_comparerMotRuzzleParPoints(Element mr1, Element mr2) {
  //Element pour compatibilité avec les fonctions génériques (sinon warning lors de la compilation)
  unsigned short nbPointsMot1 = ((MotRuzzle*)mr1)->nbPoints;
  unsigned short nbPointsMot2 = ((MotRuzzle*)mr2)->nbPoints;
  if (nbPointsMot1<nbPointsMot2) {
    return -1;
  } else if (nbPointsMot1>nbPointsMot2) {
    return 1;
  } else { //si le nombre de points est identique, on compare les mots associés
    return RZ_comparerMotRuzzleParMot(mr1,mr2);
  }
}

int RZ_comparerMotRuzzleParMot(Element mr1, Element mr2) {
  char* mot1 = ((MotRuzzle*)mr1)->mot;
  char* mot2 = ((MotRuzzle*)mr1)->mot;
  return strcmp(mot1,mot2);
}
