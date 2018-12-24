#include <stdio.h>

int comparer_R(FILE* fichier1, FILE* fichier2) {
  char c = fgetc(fichier1);
  if (c==fgetc(fichier2)) {
    if (c==EOF) {
      return 1; //fichiers identiques
    } else {
      return comparer_R(fichier1,fichier2);
    }
  } else {
    return 0; //fichiers différents
  }
}

// compare 2 fichiers caractère par caractère
// 1 : fichiers identiques
// 0 : fichiers différents
// -1 : erreur à l'ouverture des fichiers
int comparer2Fichiers(char* nomFichier1, char* nomFichier2) {
    FILE* fichier1 = fopen (nomFichier1,"rb");
    FILE* fichier2 = fopen (nomFichier2,"rb");
    if ((fichier1!=NULL) && (fichier2!=NULL)) {
      int comp = comparer_R(fichier1,fichier2);
      fclose(fichier1);
      fclose(fichier2);
      return comp;
    } else {
      return -1;
    }
}
