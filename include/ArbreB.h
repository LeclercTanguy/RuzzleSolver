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
int AB_estVide(ArbreBinaire);
ArbreBinaire AB_ajouterRacine(ArbreBinaire,ArbreBinaire,char);
char AB_obtenirElement(ArbreBinaire);
ArbreBinaire AB_obtenirFilsGauche(ArbreBinaire);
ArbreBinaire AB_obtenirFilsDroit(ArbreBinaire);

#endif
