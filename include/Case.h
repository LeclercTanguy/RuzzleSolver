/**
 * \file Case.h
 * \brief Implantation du TAD Case
 * \author Nina LARDIERE
 * \version 1.0
 */

#ifndef _CASE_
#define _CASE_


/**
* \enum Bonus
* \brief liste des bonus pouvant être attribués à une Case de la grille de Ruzzle
*/
typedef enum {
  AB,   /**< absence de bonus */
  LD,   /**< lettre compte double */
  LT,   /**< lettre compte triple */
  MD,   /**< mot compte double */
  MT    /**< mot compte triple */
} Bonus;

typedef struct {
  char lettre;
  unsigned short nbPoints;
  Bonus bonus;
  unsigned short posX;
  unsigned short posY;
} Case;

/**
  * \brief Permet de créer une case
  * \return une case dont la lettre par défaut est A, le nombre de point est égal à 1, et sans bonus (AB).
  * La position est déterminée au moment de l'insertion dans la grille
*/
Case CASE_creerCase(void);

/**
  * \brief Permet d'attribuer une lettre à une case
  * \param uneCase un pointeur vers la case à laquelle on souhaite attribuer une lettre
  * \param uneLettre la lettre que l'on souhaite attribuer à la case
*/
void CASE_fixerLettre(Case* uneCase,char uneLettre);

/**
  * \brief Permet d'attribuer un nombre de points à une case
  * \param uneCase un pointeur vers la case à laquelle on souhaite attribuer les points
  * \param points un entier positif représentatnt le nombre de points que l'on souhaite attribuer
*/
void CASE_fixerNbPoints(Case* uneCase,unsigned short points);

/**
  * \brief Permet d'attribuer un bonus à une case
  * \param uneCase un pointeur vers la case à laquelle on souhaite attribuer un bonus
  * \param unBonus le bonus que l'on souhaite attribuer à la case
*/
void CASE_fixerBonus(Case* uneCase,Bonus unBonus);

/**
  * \brief Permet d'obtenir la lettre d'une case
  * \param uneCase la case dont on souhaite obtenir la lettre
  * \return un caractère représentant la lettre attribuée à la case
*/
char CASE_obtenirLettre(Case uneCase);

/**
  * \brief Permet d'obtenir le nombre de points d'une case
  * \param uneCase la case dont on souhaite obtenir le nombre de points
  * \return un entier positif représentant le nombre de points attribué à la case
*/
unsigned short CASE_obtenirNbPoints(Case uneCase);

/**
  * \brief Permet d'obtenir le bonus attribué à une case
  * \param uneCase la case dont on souhaite obtenir le bonus
  * \return le bonus attribué à la case
*/
Bonus CASE_obtenirBonus(Case uneCase);

/**
  * \brief Permet d'attribuer une position à une case
  * \param uneCase un pointeur vers la case à laquelle on souhaite attribuer une position
  * \param positionX la position horizontale dans la grille
  * \param positionX la position verticale dans la grille
*/
void CASE_fixerPosition(Case* uneCase,unsigned short positionX,unsigned short positionY);


/**
  * \brief Permet d'obtenir la position horizontale d'une case dans la grille
  * \param uneCase la case dont on souhaite obtenir la position
  * \return une entier positif représentant la position horizontale de la case
*/
unsigned short CASE_obtenirPositionX(Case);

/**
  * \brief Permet d'obtenir la position verticale d'une case dans la grille
  * \param uneCase la case dont on souhaite obtenir la position
  * \return une entier positif représentant la position verticale de la case
*/
unsigned short CASE_obtenirPositionY(Case);

#endif
