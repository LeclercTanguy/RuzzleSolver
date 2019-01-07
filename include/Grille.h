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
 * \brief Une grille est tableau de Case 4*4 et un tableau de booléen 4*4 pour définir si une case est utilisée ou non.
*/
typedef struct {
    Case grille[4][4];
    bool caseUtilisee[4][4];
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
 * \param *laGrille pointeur sur la grille où l'on veut fixer la case.
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
 * \param *laGrille pointeur sur la grille où l'on veut définir qu'une case est utilisée.
 * \param posX la position de la case sur l'axe x de la grille.
 * \param posY la position de la case sur l'axe y.
 */
void G_debutUtilisation(Grille* laGrille,int posX,int posY);
/**
 * \brief Défini qu'une case n'est plus utilisée.
 * \author T.LECLERC
 * \param *laGrille pointeur sur la grille où l'on veut définir qu'une case n'est plus utilisée.
 * \param posX la position de la case sur l'axe x de la grille.
 * \param posY la position de la case sur l'axe y.
 */
void G_finUtilisation(Grille* laGrille,int posX,int posY);

#endif
