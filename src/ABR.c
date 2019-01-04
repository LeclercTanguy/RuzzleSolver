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

void ABR_inserer(ABR* a, Element e, int(*comparerElement)(Element,Element)){
    if (ABR_estVide(*a)) {
        *a = AB_allouer();
        AB_fixerElement(*a,e);
    }
    else if (comparerElement(e,AB_obtenirElement(*a))<=0) {
        ABR fd = AB_obtenirFilsDroit(*a);
        ABR_inserer(&fd,e,comparerElement);
        AB_fixerFilsDroit(*a,fd);
    }
    else {
        ABR fg = AB_obtenirFilsGauche(*a);
        ABR_inserer(&fg,e,comparerElement);
        AB_fixerFilsGauche(*a,fg);
    }
}

bool ABR_estPresent(ABR a, Element e, int(*comparerElement)(Element,Element)){
    if (ABR_estVide(a)){
        return false;
    }
    else {
        if (comparerElement(AB_obtenirElement(a),e)==0){
            return true;
        }

        else if (comparerElement(AB_obtenirElement(a),e)<0){
        return ABR_estPresent(AB_obtenirFilsDroit(a),e,comparerElement);
        }
        else{
        return ABR_estPresent(AB_obtenirFilsGauche(a),e,comparerElement);
        }

    }
}

Element ABR_estPresentAvecReference(ABR a, Element e, int(*comparerElement)(Element,Element)){
    if (ABR_estVide(a)){
        return NULL;
    }
    else {
        if (comparerElement(AB_obtenirElement(a),e)==0){
            return AB_obtenirElement(a);
        }

        else if (comparerElement(AB_obtenirElement(a),e)<0){
        return ABR_estPresentAvecReference(AB_obtenirFilsDroit(a),e,comparerElement);
        }
        else{
        return ABR_estPresentAvecReference(AB_obtenirFilsGauche(a),e,comparerElement);
        }

    }
}

void ABR_supprimer(ABR* a) {
  AB_supprimer(a);
}
