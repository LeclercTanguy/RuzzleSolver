#ifndef __ABR__
#define __ABR__

#include "ArbreBinaire.h"

typedef ArbreBinaire ABR;

ABR ABR_creer(void);
bool ABR_estVide(ABR a);
void ABR_inserer(ABR* a, Element e, int(*comparerElement)(Element,Element));
bool ABR_estPresent(ABR a, Element e, int(*comparerElement)(Element,Element));
//supprimerUnElement n'est pas utilisé dans ce projet
void ABR_supprimer(ABR* a);
#endif
