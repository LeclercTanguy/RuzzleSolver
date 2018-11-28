#ifndef __Mot__
#define __Mot__

//typedef Mot ;

Mot chaineEnMot (Dictionnaire dico, *char chaine); //precondition ??
char motEnChaine (Mot lemot);
unsigned int longueur (Mot lemot);
void ajouterLettre(Mot lemot, char lettre, Dictionnaire dico); //precondition ??
void retirerLettre(Mot lemot);//precondition ??
#endif
