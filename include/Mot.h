#ifndef __MOT__
#define __MOT__
#include "ListeChainee.h"

typedef struct {
  LC_ListeChainee lettres; //Liste chaînée de Mot_Lettre, commençant par la dernière lettre du mot
  unsigned int longueur;
} Mot;

#include "Dictionnaire.h"

typedef struct {
  char lettre;
  Dictionnaire refDico; //pointeur vers le nœud correspondant dans le dictionnaire
                        //à générer avec DC_obtenirReferenceLettre(refPrécédente,lettreÀAjouter,dico)
} Mot_Lettre;

Mot Mot_creerMot (void);
int Mot_estVide(Mot leMot);
char Mot_obtenirLettre(Mot leMot);
Dictionnaire Mot_obtenirReferenceDictionnaire(Mot leMot);
void Mot_ajouterLettre(Mot* leMot, char lettre, Dictionnaire dico);
void Mot_retirerLettre(Mot* leMot);
Mot Mot_chaineEnMot (Dictionnaire* dico, char* chaine);
char* Mot_motEnChaine (Mot leMot);
unsigned int Mot_longueur (Mot leMot);

#endif
