#ifndef __LISTE_CHAINEE__
#define __LISTE_CHAINEE__

typedef struct LC_Noeud* LC_ListeChainee;
typedef struct LC_Noeud {
  char lettreLC;
  LC_ListeChainee listeSuivante;
}LC_Noeud;

LC_ListeChainee LC_listeVide(void);
int LC_estVide(LC_ListeChainee);
void LC_ajouter(LC_ListeChainee,char);
char LC_obtenirElement(LC_ListeChainee);
LC_ListeChainee LC_obtenirListeSuivante(LC_ListeChainee);
void LC_fixerElement(LC_ListeChainee,char);
void LC_fixerListeSuivante(LC_ListeChainee,LC_ListeChainee);

#endif
