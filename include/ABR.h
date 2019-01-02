#ifndef __ABR__
#define __ABR__

#include "ListeChainee.h"

typedef struct ABR_Noeud* ABR;
typedef struct ABR_Noeud{
  Element lElement;
  ABR filsGauche;
  ABR filsDroit;
} ABR_Noeud;

ABR ABR_creer(void);
ABR ABR_allouer(void);
bool ABR_estVide(ABR a);
void ABR_inserer(ABR* a, Element e, int(*comparerElement)(Element,Element));
bool ABR_estPresent(ABR a, Element e, int(*comparerElement)(Element,Element));
Element ABR_obtenirElement(ABR a);
ABR ABR_obtenirFilsGauche(ABR a);
ABR ABR_obtenirFilsDroit(ABR a);
void ABR_fixerFilsDroit(ABR a, ABR ad);
void ABR_fixerFilsGauche(ABR a, ABR ag);
void ABR_fixerElement(ABR a, Element e);
#endif
