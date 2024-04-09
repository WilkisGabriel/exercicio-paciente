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

void printData(Data d)
{
    printf("%d/%d/%d\n", d.dia, d.mes, d.ano);
}