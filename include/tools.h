/**
 * \file tools.h
 * \brief some useful functions
 * \author Yves LE GUENNEC
 */

#ifndef __TOOLS__
#define __TOOLS__

/**
  * \brief compare 2 fichiers caractère par caractère
  * \param nomFichier1 le nom (ou chemin) du premier fichier à comparer
  * \param nomFichier2 le nom (ou chemin) du fichier que l'on veut comparer au premier fichier
  * \return 1 : fichiers identiques
            0 : fichiers différents
           -1 : erreur à l'ouverture des fichiers
*/
int comparer2Fichiers(char* nomFichier1, char* nomFichier2);

/**
  *\brief remplace les caractères de la chaîne compris entre 'a' et 'z' par le caractère correspondant entre 'A' et 'Z'
  *\param la chaîne à mettre en majuscule
*/
void chaineEnMajuscule(char* chaine);

/**
  *\brief retourne le minimum entre a et b
*/
int min(int a, int b);

/**
  *\brief retourne le maximum entre a et b
*/
int max(int a, int b);



#endif
