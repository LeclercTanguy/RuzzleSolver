#include "Dictionnaire.h"

int main(int argc, char const *argv[]) {
  Dictionnaire dico;
  DC_charger("dico.dat", &dico);
  return 0;
}
