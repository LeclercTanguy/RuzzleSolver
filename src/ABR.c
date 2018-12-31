#include "ABR.h"
#include "ArbreBinaire.h"

ABR ABR_creer(void){
  return AB_arbreBinaire();
}

bool ABR_estVide(ABR a){
  return false;
}

void ABR_inserer(ABR* a, Element e, int(*comparerElement)(Element,Element)){

}

bool ABR_estPresent(ABR a, Element e, int(*comparerElement)(Element,Element)){
  return false;
}

Element ABR_obtenirElement(ABR a){
  return NULL;
}

ABR ABR_obtenirFilsGauche(ABR a){
  return ABR_creer();
}

ABR ABR_obtenirFilsDroit(ABR a){
  return ABR_creer();
}
