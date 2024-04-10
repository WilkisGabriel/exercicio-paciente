#ifndef _PACIENTE_H_
#define _PACIENTE_H_

typedef struct paciente Paciente;

Paciente *PacienteCreate(char *Name, char *IDcard, char Gender, Data *Birth);

void freePaciente(Paciente *p);

void insertwound(Paciente *p, Lesao *w);

void prntWounds(Paciente *p);

void prntPaciente(Paciente *p);

char *getID(Paciente *p);

#endif