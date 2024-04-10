#include <stdio.h>
#include "data.h"

struct data
{
    int dia;
    int mes;
    int ano;
};

Data lerData()
{
    Data d;
    scanf("%d/%d/%d\n", &d.dia, &d.mes, &d.ano);
    return d;
}

int idade(Data d)
{
    int a = 2024-d.ano;
    if(d.mes >= 4)
     a++;
    return a;
}