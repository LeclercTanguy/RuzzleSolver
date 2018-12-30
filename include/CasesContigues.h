#ifndef __CASE_CONTIGUE__
#define __CASE_CONTIGUE__
#include "Case.h"
#include "ListeChainee.h"

typedef struct {
    LC_ListeChainee listeCases;
    int nbCases;
} CasesContigues;

CasesContigues CC_creer_CasesContigues(void);
void CC_ajouterCase(CasesContigues*,Case);
void CC_suprimerCase(CasesContigues*);
int CC_nbCasesContigues(CasesContigues);
char* CC_CasesContiguesEnChaine(CasesContigues); //Doit retourner une chaine de caractere
unsigned int totalPointsCasesContigues(CasesContigues);

#endif
