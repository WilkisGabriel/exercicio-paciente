#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lesao.h"
#include "paciente.h"
#include "data.h"

struct paciente
{
   char *Name;
   Data *Birth;
   char *IDcard;
   char Gender;
   Lesao **wounds;
   int n_wounds;
};

Paciente *PacienteCreate(char *Name, char *IDcard, char Gender, Data *Birth)
{

   Paciente *p = (Paciente *)malloc(sizeof(Paciente));

   p->Name = (char *)malloc(sizeof(char) * (strlen(Name) + 1));
   p->IDcard = (char *)malloc(sizeof(char) * (strlen(IDcard) + 1));

   strcpy(p->Name, Name);
   strcpy(p->IDcard, IDcard);

   p->Gender = Gender;
   p->Birth = Birth;
   p->n_wounds = 0;
   p->wounds = NULL;

   return p;
}

void freePaciente(Paciente *p)
{
   for (int i = 0; i < p->n_wounds; i++)
   {
      if (p->wounds[i] != NULL)
         freeWound(p->wounds[i]);
   }
   free(p->IDcard);
   free(p->Name);
   free(p);
}

void insertNwound(Paciente *p, Lesao *w)
{
   if (p->n_wounds == 0)
   {
      p->wounds = (Lesao **)malloc(sizeof(Lesao *));
      p->wounds[p->n_wounds] = w;
      p->n_wounds++;
   }
   else
   {
      p->wounds = (Lesao **)realloc()
   }
}

void prntWounds(Paciente *p)
{

   prntNL(p->Nwound, prntWounds);
}

void prntPaciente(Paciente *p)
{

   printf("%s", p->Name);
}