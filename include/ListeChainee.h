#ifndef __LISTE_CHAINEE__
#define __LISTE_CHAINEE__

typedef void* Element;

typedef struct LC_Noeud* LC_ListeChainee;
typedef struct LC_Noeud {
  Element element;
  LC_ListeChainee listeSuivante;
} LC_Noeud;

LC_ListeChainee LC_listeVide(void);
LC_ListeChainee LC_allouer(size_t tailleElement);
int LC_estVide(LC_ListeChainee);
int LC_estPresent(LC_ListeChainee lc,Element unElement,size_t tailleElement);
void LC_ajouter(LC_ListeChainee* lc,Element elementAAjouter,size_t tailleElement);
Element LC_obtenirElement(LC_ListeChainee);
LC_ListeChainee LC_obtenirListeSuivante(LC_ListeChainee);
void LC_fixerElement(LC_ListeChainee,Element);
void LC_fixerListeSuivante(LC_ListeChainee,LC_ListeChainee);
void LC_supprimerTete(LC_ListeChainee*);
void LC_supprimer(LC_ListeChainee*);

#endif
