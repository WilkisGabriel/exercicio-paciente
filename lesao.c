#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lesao.h"

struct lesao
{
    char *Diagnosis;
    char *ID;
    char *Body_region;
    int Malice;
    char *IDcard;
};

Lesao *WoundCreate(char *IDcard, char *ID, char *Diagnosis, char *Body_region, int MaliceP)
{
    Lesao *w = (Lesao *)malloc(sizeof(Lesao));

    w->Diagnosis = (char *)malloc(sizeof(char) * (strlen(Diagnosis) + 1));
    w->ID = (char *)malloc(sizeof(char) * (strlen(ID) + 1));
    w->IDcard = (char *)malloc(sizeof(char) * (strlen(IDcard) + 1));
    w->Body_region = (char *)malloc(sizeof(char) * (strlen(Body_region) + 1));

    strcpy(w->Diagnosis, Diagnosis);
    strcpy(w->ID, ID);
    strcpy(w->IDcard, IDcard);
    strcpy(w->Body_region, Body_region);

    w->Malice = MaliceP;

    return w;
}

int MfaW(Lesao *wound)
{
    if (wound->Malice >= 50)
        return 1;
    return 0;
}

void freeWound(Lesao *w)
{
    free(w->Diagnosis);
    free(w->ID);
    free(w->Body_region);
    free(w->IDcard);
    free(w);
}

void prntWounds(Lesao *w)
{
    printf(" %s", p->ID);
}