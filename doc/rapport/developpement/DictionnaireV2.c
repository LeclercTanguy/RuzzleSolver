//SAUVEGARDE ET CHARGEMENT
#define NB_MAX_NOEUDS 1000000
#define VIDE -1

void DC_preparationSauvegarde_R(Dictionnaire dico, char lettres[], int nFD[], int nFG[], int* ind) {
  if (!DC_estVide(dico)) {
    int indFD, indFG;
    Dictionnaire fd = AB_obtenirFilsDroit(dico);
    Dictionnaire fg = AB_obtenirFilsGauche(dico);
    lettres[*ind]=*(char*)AB_obtenirElement(dico); //on sauvegarde la lettre du nœud
    if (!DC_estVide(fd)) { //on détermine l'indice du fils droit
      indFD = *ind+1;
    } else {
      indFD = VIDE;
    }
    nFD[*ind] = indFD; //on sauvegarde le numéro du fils droit
    DC_preparationSauvegarde_R(fd,lettres,nFD,nFG,&indFD); //on s'occupe du sous-arbre droit

    if (!DC_estVide(fg)) { //on détermine l'indice du fils gauche
        if (indFD!=VIDE) {
        indFG = indFD+1;
      } else {
        indFG = *ind+1;
      }
    } else {
      indFG = VIDE;
    }
    nFG[*ind] = indFG; //on écrit le numéro du fils gauche
    DC_preparationSauvegarde_R(fg,lettres,nFD,nFG,&indFG); //on s'occupe du sous-arbre gauche

    //on met à jour l'indice s'il a augmenté
    if (indFG!=VIDE) {
      *ind = indFG;
    } else if (indFD!=VIDE){
      *ind = indFD;
    }
  }
}

void DC_preparationSauvegarde(Dictionnaire dico, char lettres[], int nFD[], int nFG[], int* nbNoeuds) {
  if (!DC_estVide(dico)) {
    int ind = 0;
    DC_preparationSauvegarde_R(dico,lettres,nFD,nFG,&ind);
    *nbNoeuds=ind+1; //ind commence à 0
  }
}

int DC_sauvegarder(Dictionnaire dico, char* nomFichier) {
  FILE* data = fopen (nomFichier,"w");
  if (data!=NULL) {
    char* lettres = malloc(NB_MAX_NOEUDS*sizeof(char));
    int* nFD = malloc(NB_MAX_NOEUDS*sizeof(int));
    int* nFG = malloc(NB_MAX_NOEUDS*sizeof(int));
    int nbNoeuds = 0;
    DC_preparationSauvegarde(dico,lettres,nFD,nFG,&nbNoeuds);
    fprintf(data,"%i\n",nbNoeuds); //on écrit le nombre de nœuds au début du fichier
    for (int ind = 0; ind < nbNoeuds; ind++) { //l'indice 0 est utilisé pour l'arbre vide
      fprintf(data,"%i ",ind); //on écrit l'indice du nœud
      fprintf(data,"%c ",lettres[ind]); //on écrit le caractère
      fprintf(data,"%i ",nFD[ind]); //on écrit l'indice du fils droit
      fprintf(data,"%i\n",nFG[ind]); //on écrit l'indice du fils gauche
    }
    free(lettres);
    free(nFD);
    free(nFG);
    return fclose(data);
  } else {
    return 1;
    printf("Impossible de créer le fichier de sauvegarde %s",nomFichier);
  }
}

int DC_charger(char *nomFichier, Dictionnaire* dico) {
  FILE* data = fopen (nomFichier,"r");
  if (data!=NULL) {
    int nbNoeuds;
    fscanf(data,"%i",&nbNoeuds);
    size_t tailleNoeud = (3*sizeof(void*)+sizeof(char));
    *dico = malloc(nbNoeuds*tailleNoeud*24);
    //24 : taille minimale qui ne provoque pas de segmentation fault, mais pas d'explication là-dessus, l'indice max étant nbNoeuds*tailleNoeud à la dernière itération ...
    int ind,fd,fg;
    char lettre;
    int nbVal;
    nbVal = fscanf(data,"%i %c %i %i",&ind,&lettre,&fd,&fg);
    while (nbVal==4) {
      Dictionnaire noeud = (Dictionnaire)(*dico+ind*tailleNoeud);
      noeud->lElement=noeud+sizeof(Element);
      //la lettre est stockée juste après le pointeur sur la lettre, d'où la valeur du pointeur
      *(char*)AB_obtenirElement(noeud)=lettre;
      Dictionnaire pFG,pFD;
      if (fg!=VIDE) {
        pFG = (Dictionnaire)(*dico+fg*tailleNoeud);
      } else {
        pFG = NULL;
      }
      if (fd!=VIDE) {
        pFD = (Dictionnaire)(*dico+fd*tailleNoeud);
      } else {
        pFD = NULL;
      }
      AB_fixerFilsDroit(noeud,pFD);
      AB_fixerFilsGauche(noeud,pFG);
      nbVal = fscanf(data,"%i %c %i %i",&ind,&lettre,&fd,&fg);
    }
    return fclose(data);
  } else {
    return 1;
    printf("Impossible d'ouvrir le fichier %s",nomFichier);
  }
}
