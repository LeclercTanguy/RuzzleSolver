#ifndef __ARBRE_BINAIRE__
#define __ARBRE_BINAIRE__
#include "ListeChainee.h"

typedef struct AB_Noeud* ArbreBinaire;
typedef struct AB_Noeud{
  Element lElement;
  ArbreBinaire filsGauche;
  ArbreBinaire filsDroit;
} AB_Noeud;

ArbreBinaire AB_arbreBinaire();
ArbreBinaire AB_allouer(void);
int AB_estVide(ArbreBinaire a);
ArbreBinaire AB_ajouterRacine(ArbreBinaire fg, ArbreBinaire fd, Element element,size_t tailleElement);
Element AB_obtenirElement(ArbreBinaire a);
ArbreBinaire AB_obtenirFilsGauche(ArbreBinaire a);
ArbreBinaire AB_obtenirFilsDroit(ArbreBinaire a);
void AB_fixerFilsGauche(ArbreBinaire a, ArbreBinaire ag);
void AB_fixerFilsDroit(ArbreBinaire a, ArbreBinaire ad);
void AB_supprimerRacine(ArbreBinaire a, ArbreBinaire *fg, ArbreBinaire *fd);
void AB_supprimer(ArbreBinaire a);


#endif
