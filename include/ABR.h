#ifndef __ABR__
#define __ABR__

#include "ArbreBinaire.h"

typedef ArbreBinaire ABR;

ABR ABR_creer(void);
bool ABR_estVide(ABR a);
void ABR_inserer(ABR* a, Element e, int(*comparerElement)(Element,Element));
bool ABR_estPresent(ABR a, Element e, int(*comparerElement)(Element,Element));
Element ABR_obtenirElement(ABR a);
ABR ABR_obtenirFilsGauche(ABR a);
ABR ABR_obtenirFilsDroit(ABR a);

#endif
