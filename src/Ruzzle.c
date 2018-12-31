#include <string.h>
#include "Ruzzle.h"
#include "ABR.h"
#include "Grille.h"
#include "Dictionnaire.h"
#include "Mot.h"
#include "CasesContigues.h"
#include "Ensemble.h"
#include "tools.h"

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

}

void RZ_afficherResultat(SolutionRuzzle resultat) {

}

Ens_Ensemble RZ_casesAdjacentesNonUtilisees(unsigned short posX, unsigned short posY, Grille g) {
  return Ens_ensemble();
}

void RZ_insererMotResultat(CasesContigues cheminRuzzle, SolutionRuzzle* resultat) {

}

int RZ_comparerMotRuzzle(MotRuzzle* mot1, MotRuzzle* mot2) {
  if ((mot1->nbPoints)<(mot2->nbPoints)) {
    return 1;
  } else {
    return 0;
  }
}
