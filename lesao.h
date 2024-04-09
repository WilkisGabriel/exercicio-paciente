#ifndef _LESAO_H_
#define _LESAO_H_

typedef struct lesao Lesao;

Lesao *WoundCreate(char *IDcard, char *ID, char *Diagnosis, char *Body_region, int MaliceP);
// Malice of a Wound
// return 0 if malice is less then 50 porcent or 1 if its higher
int MfaW(Lesao *wound);
void prntWounds(Lesao *w);
void freeWound(Lesao *w);

#endif