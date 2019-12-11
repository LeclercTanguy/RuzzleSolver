/**
 * \file Grille.h
 * \brief Implantation du TAD Grille
 * \author Tanguy LECLERC
 */

#ifndef __GRILLE__
#define __GRILLE__
#include <stdbool.h>
#include "Case.h"
/**
 * \brief Une grille contient l'ensemble des 4*4 cases de la grille de Ruzzle et permet de savoir si une Case a déjà été utilisée pour former un mot.
*/
typedef struct {
    Case grille[4][4]; /**< le tableau des cases de la grille */
    bool caseUtilisee[4][4]; /**< le tableau des booléens permettant de savoir si une case est utilisée ou non */
}Grille;
/**
 * \brief Création d'un grille vide.
 * \author T.LECLERC
 * \return Une grille vide.
 */
Grille G_grille();
/**
 * \brief Permet d'obtenir une case pour une position donnée.
 * \author T.LECLERC
 * \param laGrille la grille où est la case voulue.
 * \param posX la position de la case sur l'axe x de la grille.
 * \param posY la position de la case sur l'axe y.
 * \return La case à la position donnée.
 */
Case G_obtenirCase(Grille laGrille,int posX,int posY);
/**
 * \brief Permet de fixer une case pour une position donnée.
 * \author T.LECLERC
 * \param laGrille pointeur sur la grille où l'on veut fixer la case.
 * \param uneCase la case que l'on veut fixer.
 * \param posX la position sur l'axe x de la grille.
 * \param posY la position sur l'axe y.
 */
void G_fixerCase(Grille* laGrille,Case uneCase,int posX,int posY);
/**
 * \brief Permet de savoir si une case est utilisée ou non.
 * \author T.LECLERC
 * \param laGrille la grille où est la case.
 * \param posX la position de la case sur l'axe x de la grille.
 * \param posY la position de la case sur l'axe y.
 * \return Vrai si la case est utilisée , Faux sinon.
 */
bool G_estUtilisee(Grille laGrille,int posX,int posY);
/**
 * \brief Défini qu'une case est utilisée.
 * \author T.LECLERC
 * \param laGrille pointeur sur la grille où l'on veut définir qu'une case est utilisée.
 * \param posX la position de la case sur l'axe x de la grille.
 * \param posY la position de la case sur l'axe y.
 */
void G_debutUtilisation(Grille* laGrille,int posX,int posY);
/**
 * \brief Défini qu'une case n'est plus utilisée.
 * \author T.LECLERC
 * \param laGrille pointeur sur la grille où l'on veut définir qu'une case n'est plus utilisée.
 * \param posX la position de la case sur l'axe x de la grille.
 * \param posY la position de la case sur l'axe y.
 */
void G_finUtilisation(Grille* laGrille,int posX,int posY);

#endif
