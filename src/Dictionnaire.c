#include "ArbreB.h"
#include "Dictionnaire.h"

Dictionnaire DC_creerDictionnaire(char *fichierDictionnaire) {
  return AB_arbreBinaire();
}

void DC_ajouterMot(Dictionnaire dico, char *leMot) {
  Dictionnaire temp;
  if (AB_estVide(dico)) {
    //aucun nœud frère ni fils
    dico = AB_ajouterRacine(AB_arbreBinaire(),AB_arbreBinaire(),leMot[0]);
  } else if (AB_obtenirElement(dico)-leMot[0]<0) {
    //la lettre à insérer est plus grande, on passe au frère suivant
    temp = AB_obtenirFilsDroit(dico);
    DC_ajouterMot(temp,leMot);
    AB_fixerFilsDroit(dico,temp);
  } else if (AB_obtenirElement(dico)-leMot[0]>0) {
    //la lettre à insérer est plus petite, on insère le nœud avant le frère suivant
    dico = AB_ajouterRacine(AB_arbreBinaire(),dico,leMot[0]);
  }
  //si le nœud est déjà présent : rien à faire
  if (leMot[0]!='\0') {
    //si on n'est pas à la fin du mot, on continue
    temp = AB_obtenirFilsGauche(dico);
    DC_ajouterMot(temp,leMot+1);
    AB_fixerFilsGauche(dico,temp);
  }
};
