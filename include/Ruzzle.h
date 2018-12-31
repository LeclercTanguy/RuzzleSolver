#ifndef __RUZZLE__
#define __RUZZLE__

#include "ABR.h"
#include "Grille.h"
#include "Dictionnaire.h"
#include "Mot.h"
#include "CasesContigues.h"
#include "Ensemble.h"

typedef struct {
  ABR motsTrouves; //ABR de MotRuzzle
  int nbMots;
} SolutionRuzzle;

typedef struct {
  char* mot;
  unsigned short nbPoints;
} MotRuzzle;

/**
* \brief permet de convertir une chaîne de 2 caractères en un Bonus utilisé dans une case de la grille de Ruzzle
*
* Si la chaîne fait plus de deux caractères, seul les 2 premiers sont utilisés.
* \author Yves LE GUENNEC
* \param chaine la chaîne à convertir en Bonus
* \param leBonus le Bonus obtenu à partir de la chaîne
* \return  0 : pas d'erreur,
*         -1 : la chaine fait moins de 2 caractères,
*          1 : caractère inattendu dans la chaine
*/
int RZ_chaineEnBonus(char* chaine, Bonus* leBonus);

/**
* \brief permet de convertir une chaîne de caractères décrivant une grille de Ruzzle en une Grille utilisée par ruzzleSolver
* \author Yves LE GUENNEC
* \param chaine une chaîne de 16 * 4 caractères représentant les 16 cases de la grille de Ruzzle.
*   Le premier caractère correspond à la lettre, le deuxième au nombre de points associé à la case
*   et les deux derniers représentent le Bonus (LD, LT, MD, MT, ou deux espaces s'il n'y a pas de bonus).
*   Les cases sont prises par ligne puis par colonne.
* \param grilleRuzzle un pointeur sur une Grille, qui est remplie tel que décrite dans la chaîne.
*   Pensez à vérifier que la procédure n'a pas retourné d'erreur avant d'utiliser la Grille produite.
* \return  0 : pas d'erreur,
*         -1 : la chaine n'a pas la taille attendue,
*          1 : caractère inattendu dans la chaine
*/
int RZ_chaineEnGrille(char* chaine, Grille* grilleRuzzle);

void RZ_trouverMots(unsigned short posX, unsigned short posY, Dictionnaire dico, Grille* g, Mot* prefixe, CasesContigues* cheminRuzzle, SolutionRuzzle* resultat);

void RZ_afficherResultat(SolutionRuzzle resultat);

Ens_Ensemble RZ_casesAdjacentesNonUtilisees(unsigned short posX, unsigned short posY, Grille g);

void RZ_insererMotResultat(CasesContigues cheminRuzzle, SolutionRuzzle* resultat);

/**
* \brief permet de comparer deux MotRuzzle, en se basant sur le nombre de points associé à chaque mot
* \author Yves LE GUENNEC
* \param mot1 un pointeur vers le premier mot à comparer (pour correspondre au type générique Element)
* \param mot2 un pointeur vers le deuxième mot à comparer
* \return VRAI (1) si mot1<mot2, FAUX (0) sinon
*/
int RZ_comparerMotRuzzle(MotRuzzle* mot1, MotRuzzle* mot2);

#endif
