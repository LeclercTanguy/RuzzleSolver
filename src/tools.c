#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

int min(int a, int b) {
  if (a<=b) {
    return a;
  } else {
    return b;
  }
}

int max(int a, int b) {
  if (a>=b) {
    return a;
  } else {
    return b;
  }
}

void chaineEnMajuscule(char* chaine) {
  int i = 0;
  int min2maj = 'A'-'a';
  while (chaine[i]!='\0') {
    if ((chaine[i]>='a') && (chaine[i]<='z')) {
      chaine[i]=chaine[i]+min2maj;
    }
    i++;
  }
}

int comparer2Fichiers(char* nomFichier1, char* nomFichier2) {
    FILE* fichier1 = fopen (nomFichier1,"rb");
    FILE* fichier2 = fopen (nomFichier2,"rb");
    if ((fichier1!=NULL) && (fichier2!=NULL)) {
      char c1 = fgetc(fichier1);
      char c2 = fgetc(fichier2);
      while((c1==c2) && (c1!=EOF)) {
        c1 = fgetc(fichier1);
        c2 = fgetc(fichier2);
      }
      fclose(fichier1);
      fclose(fichier2);
      return c1==c2;
    } else {
      return -1; //erreur à l'ouverture des fichiers
    }
}

int comparerInt (Element a, Element b) {
  int int1 = *(int*)a;
  int int2 = *(int*)b;
  if (int1==int2){
    return 0;
  }
  else if (int1<int2){
    return -1;
  } else {
    return 1;
  }
}

char* caractereEnChaine(char c) {
  char* chaine = malloc(sizeof(c)*2);
  chaine[0] = c;
  chaine[1] = '\0';
  return chaine;
}
