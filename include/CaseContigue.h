#ifndef __CASE_CONTIGUE__
#define __CASE_CONTIGUE__
#include "Case.h"
#include "ListeChainee.h"

typedef struct CaseContigue{
    LC_ListeChainee listeCases;
    int nbCases;
}CaseContigue;

CaseContigue CC_creer_CasesContigues(void);
void CC_ajouterCase(CaseContigue*,Case);
void CC_suprimmerCase(CaseContigue*);
int CC_nbCaseContigue(CaseContigue);
char* CC_CaseContigueEnChaine(CaseContigue); //Doit retourner une chaine de caractere

#endif
