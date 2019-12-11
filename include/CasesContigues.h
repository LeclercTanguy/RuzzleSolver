/**
 * \file CasesContigues.h
 * \brief Implantation du TAD CasesContigues
 * \author Nina LARDIERE
 * \version 1.0
 */

#ifndef __CASE_CONTIGUE__
#define __CASE_CONTIGUE__
#include "ListeChainee.h"
#include "Case.h"

/**
* \brief contient une suite de cases contiguës de la grille de Ruzzle
*/
typedef struct {
    LC_ListeChainee listeCases; /**< la liste chaînée des cases */
    int nbCases; /**< le nombre de cases contenues dans la liste */
} CasesContigues;

/**
  * \brief Permet de créer une "case contiguë vide"
  * \return une CaseContigue vide c'est à dire une liste de case vide, et un nombre de case égal à 0
  * \warning utilisez CC_supprimer(CasesContigues*) à la fin de l'utilisation des CasesContigues
*/
CasesContigues CC_creer_CasesContigues(void);

/**
  * \brief Permet d'ajouter une case à la suite de cases contiguës
  * \param desCasesContigues un pointeur vers les cases contiguës auxquelles on souhaite rajouter une case
  * \param uneCase la case que l'on souhaite rajouter aux cases contiguës
*/
void CC_ajouterCase(CasesContigues* desCasesContigues,Case uneCase);

/**
  * \brief Permet de supprimer la dernière case des cases contiguës
  * \param desCasesContigues un pointeur vers les cases contiguës auxquelles on souhaite supprimer la dernière case
*/
void CC_supprimerCase(CasesContigues* desCasesContigues);

/**
  * \brief Permet de supprimer l'ensemble des cases contiguës
  * \param desCasesContigues un pointeur vers les cases contiguës à supprimer
*/
void CC_supprimer(CasesContigues* desCasesContigues);

/**
  * \brief Permet d'obtenir le nombre de cases présentes dans les cases contiguës
  * \param desCasesContigues les cases contiguës dont on souhaite connaitre le nombre de case
  * \return un entier correspondant au nombre de cases contenues dans les cases contiguës
*/
int CC_nbCasesContigues(CasesContigues desCasesContigues);

/**
  * \brief Permet de convertir en chaine de caracteres les cases contigues, c'est à dire les lettres de chacunes des cases contenues dans les cases contiguës
  * \param desCasesContigues les cases contiguës que l'on souhaite convertir en chaîne de caractères
  * \return une chaîne de caractères composée des lettres des cases contenues dans les cases contiguës.
  * La première lettre est celle de la première case ajoutée, la dernière celle de la dernière case ajoutée.
*/
char* CC_CasesContiguesEnChaine(CasesContigues desCasesContigues);

/**
  * \brief Permet d'obtenir le nombre total de points contenus dans les cases contiguës, c'est à dire la somme des points et des bonus de chaque cases des cases contiguës
  * \param desCasesContigues les cases contiguës dont on souhaite connaitre le nombre total de points
  * \return un entier positif représentant la somme des points de toutes les cases composant les cases contiguës
*/
unsigned int CC_totalPointsCasesContigues(CasesContigues desCasesContigues);

#endif
