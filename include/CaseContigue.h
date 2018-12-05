#ifndef _CaseContigue_
#define _CaseContigue_
#include "Case.h"

typedef struct CaseContigue{
    Case ListeChainee;
    int nbCases;
}
CaseContigue CaseContigue();
void CC_ajouterCase(CaseContigue,Case);
void CC_SuprimmerCase(CaseContigue);
int CC_nbCaseContigue(CaseContigue);
*char CC_CaseContigueEnChaine(CaseContigue); //Doit retourner une chaine de caractere 
