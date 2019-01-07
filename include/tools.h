/**
 * \file tools.h
 * \brief quelques fonctions utiles
 */

#ifndef __TOOLS__
#define __TOOLS__

#include "ListeChainee.h" //définition de Element

/**
  * \brief compare 2 fichiers caractère par caractère
  * \param nomFichier1 le nom (ou chemin) du premier fichier à comparer
  * \param nomFichier2 le nom (ou chemin) du fichier que l'on veut comparer au premier fichier
  * \version 2.0
  * \diff passage à une version itérative pour éviter un stack overflow lors de la comparaison de gros fichiers
  * \author Yves LE GUENNEC
  * \return 1 : fichiers identiques,
            0 : fichiers différents,
           -1 : erreur à l'ouverture des fichiers
*/
int comparer2Fichiers(char* nomFichier1, char* nomFichier2);

/**
  *\brief remplace les caractères de la chaîne compris entre 'a' et 'z' par le caractère correspondant entre 'A' et 'Z'
  * \author Yves LE GUENNEC
  *\param la chaîne à mettre en majuscule
*/
void chaineEnMajuscule(char* chaine);

/**
* \brief conversion d'un caractère en chaîne de caractères
* \param c le caractère à convertir
* \return la chaîne obtenue
*/
char* caractereEnChaine(char c);

/**
  *\brief retourne le minimum entre a et b
*/
int min(int a, int b);

/**
  *\brief retourne le maximum entre a et b
*/
int max(int a, int b);

/**
  * \brief compare 2 int
  * \param a l'adresse du premier int (pour être du type Ensemble)
  * \param b l'adresse du deuxième int
  * \author Tanguy LECLERC
  * \return -1 : a<b,
             0 : a=b,
             1 : a>b
*/
int comparerInt (Element a, Element b);

#endif
