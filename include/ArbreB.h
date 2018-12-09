#ifndef __ARBRE_B__
#define __ARBRE_B__

typedef struct Noeud Noeud;
typedef Noeud* ArbreBinaire;
struct Noeud{
  char lELement;
  ArbreBinaire filsGauche;
  ArbreBinaire filsDroit;
};

ArbreBinaire AB_arbreBinaire();
int AB_estVide(ArbreBinaire a);
ArbreBinaire AB_ajouterRacine(ArbreBinaire fg, ArbreBinaire fd, char element);
char AB_obtenirElement(ArbreBinaire a);
ArbreBinaire AB_obtenirFilsGauche(ArbreBinaire a);
ArbreBinaire AB_obtenirFilsDroit(ArbreBinaire a);
void AB_fixerFilsGauche(ArbreBinaire a, ArbreBinaire ag);
void AB_fixerFilsDroit(ArbreBinaire a, ArbreBinaire ad);
void AB_supprimerRacine(ArbreBinaire a, ArbreBinaire fg, ArbreBinaire fd);
void AB_supprimer(ArbreBinaire a);


#endif
