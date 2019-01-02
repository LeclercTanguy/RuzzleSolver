#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "ABR.h"


ABR ABR_creer(void){
    return NULL;
}

ABR ABR_allouer(void){
  return (ABR)malloc(sizeof(ABR_Noeud));
}

bool ABR_estVide(ABR a){
  return a==NULL;
}

void ABR_inserer(ABR* a, Element e, int(*comparerElement)(Element,Element)){
    if (ABR_estVide(*a)) {
        *a = ABR_allouer();
        ABR_fixerElement(*a,e);
    }
    else if (comparerElement(e,ABR_obtenirElement(*a))<=0) {
        ABR fd = ABR_obtenirFilsDroit(*a);
        ABR_inserer(&fd,e,comparerElement);
        ABR_fixerFilsDroit(*a,fd);
    }
    else {
        ABR fg = ABR_obtenirFilsGauche(*a);
        ABR_inserer(&fg,e,comparerElement);
        ABR_fixerFilsGauche(*a,fg);
    }
}

bool ABR_estPresent(ABR a, Element e, int(*comparerElement)(Element,Element)){
    if (ABR_estVide(a)){
        return false;
    }
    else {
        if (comparerElement(ABR_obtenirElement(a),e)==0){
            return true;
        }

        else if (comparerElement(ABR_obtenirElement(a),e)<0){
        return ABR_estPresent(ABR_obtenirFilsDroit(a),e,comparerElement);
        }
        else{
        return ABR_estPresent(ABR_obtenirFilsGauche(a),e,comparerElement);
        }

    }
}

Element ABR_obtenirElement(ABR a){
  return a->lElement;
}

ABR ABR_obtenirFilsGauche(ABR a){
  return a->filsGauche;
}

ABR ABR_obtenirFilsDroit(ABR a){
  return a->filsDroit;
}

void ABR_fixerElement(ABR a,Element element){
    assert (!ABR_estVide(a));
    a->lElement=element;
}

void ABR_fixerFilsGauche(ABR a, ABR ag){
    assert (!ABR_estVide(a));
    a->filsGauche=ag;
}

void ABR_fixerFilsDroit(ABR a, ABR ad){
    assert (!ABR_estVide(a));
    a->filsDroit=ad;
}
