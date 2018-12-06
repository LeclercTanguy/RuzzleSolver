#ifndef _ArbreB_
#define _ArbreB_

typedef ArbreB *Noeud
typedef struct Noeud{
  char IELement;
  ArbreBinaire filsGauche;
  ArbreBinaire filsDroit;
};

ArbreBinaire arbreBinaire(void);
int estVide(ArbreBinaire);
ArbreBinaire ajouterRacine(ArbreBinaire,ArbreBinaire,char);
char obtenirElement(ArbreBinaire);
ArbreBinaire obtenirFilsGauche(ArbreBinaire);
ArbreBinaire obtenirFilsDroit(ArbreBinaire);

#endif
