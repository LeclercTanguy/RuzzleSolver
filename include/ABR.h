#ifndef __ABR__
#define __ABR__

#include "ArbreBinaire.h"

typedef ArbreBinaire ABR;

ABR ABR_creer(void);
bool ABR_estVide(ABR a);
void ABR_inserer(ABR* a, Element e, int(*comparerElement)(Element,Element),size_t tailleElement);
bool ABR_estPresent(ABR a, Element e, int(*comparerElement)(Element,Element));

/**
* \brief indique si l'Element est présent dans l'ABR, et auquel cas renvoi son adresse
* \author Yves LE GUENNEC, modification de ABR_estPresent de Tanguy LECLERC
* \param a l'ABR dans lequel on veut vérifier la présence
* \param e l'élément recherché (pointeur sur la valeur recherchée)
* \param comparerElement fonction permettant de comparer les éléments utilisés
* \return NULL si l'élément n'est pas présent
          l'Element (pointeur vers la zone contenant l'élément) si l'élément est présent
*/
Element ABR_estPresentAvecReference(ABR a, Element e, int(*comparerElement)(Element,Element));
ABR ABR_lePlusGrand(ABR a);
void ABR_supprimer(ABR* a);
void ABR_supprimerElement(ABR* a, Element e, int(*comparerElement)(Element,Element));
#endif
