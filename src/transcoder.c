#include <stdio.h>
#include <string.h>
#include "Dictionnaire.h"
#include "tools.h"
#define LONGUEUR_MAX_MOT 30

int main(int argc, char* argv[]) {
  if (argc==3) {
    char* source = argv[1];
    char* destination = argv[2];
    FILE* listeMots = fopen (source,"r");
    if (listeMots!=NULL) {
      Dictionnaire dico = DC_creerDictionnaire();
      char mot[LONGUEUR_MAX_MOT];
      char* err = fgets(mot,LONGUEUR_MAX_MOT,listeMots);
      while (err!=NULL) { // tant que l'on n'est pas à la fin du fichier
        *(mot+strlen(mot)-1)='\0'; // pour remplacer le \n provenant de la lecture du fichier
        chaineEnMajuscule(mot); //pour que tous les mots soient en majuscule
        DC_ajouterMot (&dico,mot);
        err = fgets(mot,LONGUEUR_MAX_MOT,listeMots);
      }
      DC_sauvegarder(dico,destination);
      return fclose(listeMots);
    } else {
      printf("Impossible d'ouvrir le fichier %s \n",source);
      return 1;
    }
  } else {
    printf("Il n'y a pas assez d'arguments\n");
    printf("transcoder nécessite dans l'ordre : \n");
    printf("1) le nom du fichier où est stocké le dictionnaire sous forme de liste de mots avec un mot par ligne. \n");
    printf("2) le nom du fichier où doit être enregistré le résultat de la sérialisation. Si le fichier existe, il sera écrasé.\n");
    return 1;
  }
}
