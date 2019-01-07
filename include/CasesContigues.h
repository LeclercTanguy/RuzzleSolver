/**
 * \file CasesContigues.h
 * \brief Implantation du TAD CasesContigues
 * \author Nina LARDIERE
 * \version 1.0
 */

#ifndef __CASE_CONTIGUE__
#define __CASE_CONTIGUE__
#include "ListeChainee.h" // le type CasesContigues est constitué d'une liste chainée de case.s
#include "Case.h"

typedef struct {
    LC_ListeChainee listeCases;
    int nbCases;
} CasesContigues;

/**
  * \brief Permet de créer une case contigue vide
  * \return une CaseContigue vide c'est à dire une liste de case vide, et un nombre de case égale à 0
  * \warning utilisez CC_supprimer(CasesContigues*) à la fin de l'utilisation des CasesContigues
*/
CasesContigues CC_creer_CasesContigues(void);

/**
  * \brief Permet d'ajouter une case des cases contigues
  * \param desCasesContigues un pointeur vers les cases contigues auxquelles on souhaite rajouter une case
  * \param uneCase la case que l'on souhaite rajouter aux cases contigues
*/
void CC_ajouterCase(CasesContigues* desCasesContigues,Case uneCase);

/**
  * \brief Permet de supprimer la derniere case des cases contigues
  * \param desCasesContigues un pointeur vers les cases contigues auxquelles on souhaite supprimer la derniere case
*/
void CC_supprimerCase(CasesContigues* desCasesContigues);

/**
  * \brief Permet de supprimer l'ensemble des cases contiguës
  * \param desCasesContigues un pointeur vers les cases contiguës à supprimer
*/
void CC_supprimer(CasesContigues* desCasesContigues);

/**
  * \brief Permet d'obtenir le nombre de cases présentes dans les cases contigues
  * \param desCasesContigues les cases contigues dont on souhaite connaitre le nombre de case
  * \return un entier correspondant au nombre de case.s contenue.s dans les cases contigues
*/
int CC_nbCasesContigues(CasesContigues desCasesContigues);

/**
  * \brief Permet de convertir en chaine de caracteres les cases contigues, c'est à dire les lettres de chacunes des cases contenues dans les cases contigues
  * \param desCasesContigues les cases contigues qu'on souhaite convertir en chaine de caractères
  * \return une chaine de caractère composée des lettres des cases contenues dans les cases contigues.
  * La première lettre est celle de la première case, la derniere celle de la dernière case ajoutée.
*/
char* CC_CasesContiguesEnChaine(CasesContigues desCasesContigues);

/**
  * \brief Permet d'obtenir le nombre total de points contenus dans les cases contigues, c'est à dire la somme des points et des bonus de chaque cases des cases contigues
  * \param desCasesContigues les cases contigues dont on souhaite connaitre le nombre total de points
  * \return un entier positif représentatntla somme des points de toutes les cases composant les cases contigues
*/
unsigned int CC_totalPointsCasesContigues(CasesContigues desCasesContigues);

#endif
