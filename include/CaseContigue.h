#ifndef __CASE_CONTIGUE__
#define __CASE_CONTIGUE__
#include "Case.h"
#include "ListeChainee.h"

typedef struct CaseContigue{
    Case ListeChainee;
    int nbCases;
}
CaseContigue CaseContigue();
void CC_ajouterCase(CaseContigue,Case);
void CC_SuprimmerCase(CaseContigue);
int CC_nbCaseContigue(CaseContigue);
*char CC_CaseContigueEnChaine(CaseContigue); //Doit retourner une chaine de caractere

#endif
