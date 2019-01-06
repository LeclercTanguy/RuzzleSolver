#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "ABR.h"

ABR ABR_creer(void){
    return AB_arbreBinaire();
}

bool ABR_estVide(ABR a){
  return AB_estVide(a);
}

void ABR_inserer(ABR* a, Element e, int(*comparerElement)(Element,Element),size_t tailleElement){
    if (ABR_estVide(*a)) {
        *a = AB_allouer();
        AB_fixerElement(*a,e,tailleElement);
    }
    else if (comparerElement(AB_obtenirElement(*a),e)<=0) {
        ABR fd = AB_obtenirFilsDroit(*a);
        ABR_inserer(&fd,e,comparerElement,tailleElement);
        AB_fixerFilsDroit(*a,fd);
    }
    else {
        ABR fg = AB_obtenirFilsGauche(*a);
        ABR_inserer(&fg,e,comparerElement,tailleElement);
        AB_fixerFilsGauche(*a,fg);
    }
}

bool ABR_estPresent(ABR a, Element e, int(*comparerElement)(Element,Element)){
  if (ABR_estVide(a)){
    return false;
  } else if (comparerElement(AB_obtenirElement(a),e)==0){
    return true;
  } else if (comparerElement(AB_obtenirElement(a),e)<0){
    return ABR_estPresent(AB_obtenirFilsDroit(a),e,comparerElement);
  } else {
    return ABR_estPresent(AB_obtenirFilsGauche(a),e,comparerElement);
  }
}

Element ABR_estPresentAvecReference(ABR a, Element e, int(*comparerElement)(Element,Element)){
  if (ABR_estVide(a)){
    return NULL;
  } else if (comparerElement(AB_obtenirElement(a),e)==0){
    return AB_obtenirElement(a);
  } else if (comparerElement(AB_obtenirElement(a),e)<0){
    return ABR_estPresentAvecReference(AB_obtenirFilsDroit(a),e,comparerElement);
  } else {
    return ABR_estPresentAvecReference(AB_obtenirFilsGauche(a),e,comparerElement);
  }
}

void ABR_supprimer(ABR* a) {
  AB_supprimer(a);
}

ABR ABR_lePlusGrand(ABR a){
    assert(!AB_estVide(a));
    if (AB_estVide(AB_obtenirFilsDroit(a))){
        return a;
    }
    else {
        return ABR_lePlusGrand(a);
    }
}

void ABR_supprimerElement(ABR* a, Element e, int(*comparerElement)(Element,Element)){
    assert(ABR_estPresent(*a,e,comparerElement));
    if (!AB_estVide(*a)){
        if (comparerElement(AB_obtenirElement(*a),e)>0){
            ABR tempfg = AB_obtenirFilsGauche(*a);
            ABR_supprimerElement(&tempfg,e,comparerElement);
            AB_fixerFilsGauche(*a,tempfg);
        }
        else {
            if (comparerElement(AB_obtenirElement(*a),e)<0){
                ABR tempfd = AB_obtenirFilsDroit(*a);
                ABR_supprimerElement(&tempfd,e,comparerElement);
                AB_fixerFilsDroit(*a,tempfd);
            }
            else {
                if (ABR_estVide(AB_obtenirFilsGauche(*a)) && ABR_estVide(AB_obtenirFilsDroit(*a))){
                    ABR tempfd = AB_obtenirFilsDroit(*a); // Ou tempfd = ABR_creer doit etre plus correct
                    ABR tempfg = AB_obtenirFilsGauche(*a);
                    AB_supprimerRacine(a,&tempfg,&tempfd);
                }
                else {
                    if(ABR_estVide(AB_obtenirFilsGauche(*a)) || ABR_estVide(AB_obtenirFilsDroit(*a))){
                        ABR tempfd = AB_obtenirFilsDroit(*a);
                        ABR tempfg = AB_obtenirFilsGauche(*a);
                        AB_supprimerRacine(a,&tempfg,&tempfd);
                        if (AB_estVide(tempfg)){
                            *a = tempfd;
                        }
                        else {
                            *a = tempfg;
                        }
                    }
                    else{
                        ABR tempfd = AB_obtenirFilsDroit(*a);
                        ABR tempfg = AB_obtenirFilsGauche(*a);
                        AB_supprimerRacine(a,&tempfg,&tempfd);
                        Element nouveauSommet = AB_obtenirElement(ABR_lePlusGrand(tempfg));
                        ABR_supprimerElement(&tempfg,nouveauSommet,comparerElement);
                        *a = AB_ajouterRacine(tempfg,tempfd,nouveauSommet,sizeof(Element));

                    }
                }
            }

        }
    }
}
