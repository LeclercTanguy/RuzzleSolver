#ifndef __RUZZLE__
#define __RUZZLE__

#include "ABR.h"
#include "Grille.h"
#include "Dictionnaire.h"
#include "Mot.h"
#include "CasesContigues.h"

typedef struct {
  ABR motsTrouvesParPoints; //ABR de MotRuzzle trié par nb de points
  ABR motsTrouvesParMot; //ABR de MotRuzzle trié par mot
  int nbMots;
} SolutionRuzzle;

typedef struct {
  char* mot;
  unsigned short nbPoints;
} MotRuzzle;

/**
 * \brief Permet d'initialiser une variable de type SolutionRuzzle.
 * Elle initialise celle-ci avec un arbre Vide et nombre de mots égale à 0.
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
  * \brief Permet d'afficher dans le terminal tous les mots qui ont été trouvés
  * et qui sont contenus dans une variable de type SolutionRuzzle
  * \author Simon LEBEAUD
  * \param resultat l'arbre contenant tous les mots trouvés.
  */
void RZ_afficherResultat(SolutionRuzzle resultat);

/**
* \brief permet de connaître les cases pouvant être choisies pour construire le Mot
* \author Tanguy LECLERC
* \param posX la position (de 1 à 4) de la case en largeur
* \param posY la position (de 1 à 4) de la case en hauteur
* \param g la grille de Ruzzle
* \return un ensemble contenant les cases adjacentes à la case de position (posX,posY)
* et qui ne sont pas utilisées dans le Mot en cours
*/
Ens_Ensemble RZ_casesAdjacentesNonUtilisees(unsigned short posX, unsigned short posY, Grille g);

/**
* \brief insère un mot trouvé dans la grille Ruzzle dans la solution
* \author Yves LE GUENNEC
* \version 1.1
* \diff prise en compte des éventuels doublons lors de la recherche des mots
* \param cheminRuzzle le mot trouvé dans la grille Ruzzle, stocké sous forme de CasesContigues
* \param resultat un pointeur vers la solution à mettre à jour
*/
void RZ_insererMotResultat(CasesContigues cheminRuzzle, SolutionRuzzle* resultat);

/**
* \brief permet de comparer deux MotRuzzle afin d'être utilisée dans des fonctions génériques.
* La comparaison se base sur le nombre de points associé à chaque mot, et, en cas d'égalité, sur le mot lui même.
* \author Yves LE GUENNEC
* \param mr1 un pointeur vers le premier MotRuzzle à comparer (pour correspondre au type générique Element)
* \param mr2 un pointeur vers le deuxième MotRuzzle à comparer
* \return un nombre négatif si mr1<mr2,
          0 si les deux MotRuzzle sont identiques
          un nombre positif si mr1>mr2;
*/
int RZ_comparerMotRuzzleParPoints(Element mr1, Element mr2);

/**
* \brief permet de comparer deux mots d'un MotRuzzle afin d'être utilisée dans des fonctions génériques.
* \author Yves LE GUENNEC
* \param mr1 un pointeur vers le premier mot à comparer (mot1)
* (pour correspondre au type générique Element)
* \param mr2 un pointeur vers le deuxième mot à comparer (mot2)
* \return un nombre négatif si mot1<mot2,
          0 si les deux mots sont identiques
          un nombre positif si mot1>mot2;
*/
int RZ_comparerMotRuzzleParMot(Element mr1, Element mr2);

/**
* \brief indique comment doit être décrite la grille de Ruzzle en cas de saisie incorrecte
* \author Yves LE GUENNEC
*/
void infosGrille(void);

/**
* \brief conversion d'un caractère en chaîne de caractères
* \author Yves LE GUENNEC
* \param c le caractère à convertir
* \return la chaîne obtenue
*/
char* caractereEnChaine(char c);

#endif
