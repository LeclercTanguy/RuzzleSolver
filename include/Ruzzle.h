#ifndef __RUZZLE__
#define __RUZZLE__

#include "ABR.h"
#include "Grille.h"
#include "Dictionnaire.h"
#include "Mot.h"
#include "CasesContigues.h"

typedef struct {
  ABR motsTrouves; //ABR de MotRuzzle
  int nbMots;
} SolutionRuzzle;

typedef struct {
  char* mot;
  unsigned short nbPoints;
} MotRuzzle;

/**
 * \brief Permet d'initialiser une variable de type RZ_creerSolutionRuzzle.
 * Elle initialise celle-ci avec un arbre Vide et nombre de Mots égale à 0.
 * \author Simon LEBEAUD
 * \version 1.1
 * \return SolutionRuzzle Vide
*/

SolutionRuzzle RZ_creerSolutionRuzzle(void);

/**
* \brief Permet de convertir une chaîne de 2 caractères en un Bonus utilisé dans une Case de la Grille de Ruzzle.
*
* Si la chaîne fait plus de deux caractères, seul les 2 premiers sont utilisés.
* \author Yves LE GUENNEC
* \version 1.1
* \diff Prise en compte des notations du jeu Ruzzle (DL, TL, DW, TW) pour faciliter la saisie de la Grille
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
* \warning Pensez à vérifier que la procédure n'a pas retourné d'erreur avant d'utiliser la Grille produite.
* \return  0 : pas d'erreur,
*         -1 : la chaine n'a pas la taille attendue,
*          1 : caractère inattendu dans la chaine
*/
int RZ_chaineEnGrille(char* chaine, Grille* grilleRuzzle);

void RZ_trouverMots(unsigned short posX, unsigned short posY, Dictionnaire dico, Grille* g, Mot* prefixe, CasesContigues* cheminRuzzle, SolutionRuzzle* resultat);

  /**
  * \brief Permet d'afficher dans le terminal tout les Mot qui on été trouver et qui sont contenue dans une variable
  * SolutionRuzzle
  * \author Simon LEBEAUD
  *\param variable resultat qui est de type SolutionRuzzle et qui contient
  * un arbre contenant tout les mots trouvé.
  */

void RZ_afficherResultat(SolutionRuzzle resultat);

Ens_Ensemble RZ_casesAdjacentesNonUtilisees(unsigned short posX, unsigned short posY, Grille g);

/**
* \brief insère un mot trouvé dans la grille Ruzzle dans la solution
* \author Yves LE GUENNEC
* \param cheminRuzzle le mot trouvé dans la grille Ruzzle, stocké sous forme de CasesContigues
* \param resultat un pointeur vers la solution à mettre à jour
*/
void RZ_insererMotResultat(CasesContigues cheminRuzzle, SolutionRuzzle* resultat);

/**
* \brief permet de comparer deux MotRuzzle afin d'être utilisée dans des fonctions génériques.
* La comparaison se base sur le nombre de points associé à chaque mot, et, en cas d'égalité, sur le mot lui même.
* \author Yves LE GUENNEC
* \param mr1 un pointeur vers le premier mot à comparer (pour correspondre au type générique Element)
* \param mr2 un pointeur vers le deuxième mot à comparer
* \return un nombre négatif si mr1<mr2,
          0 si les deux mots sont identiques
          un nombre positif si mr1>mr2;
*/
int RZ_comparerMotRuzzle(Element mr1, Element mr2);

#endif
