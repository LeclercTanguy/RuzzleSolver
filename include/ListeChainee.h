#ifndef _ListeChainee_
#define _ListeChainee_

typedef struct LC_Noeud* LC_ListeChainee;
typedef struct LC_Noeud {
  char lettre;
  LC_ListeChainee listeSuivante;
};

LC_ListeChainee listeVide(void);
int estVide(LC_ListeChainee);
void ajouter(LC_ListeChainee,char);
char obtenirElement(LC_ListeChainee);
LC_ListeChainee obtenirListeSuivante(LC_ListeChainee);

#endif
