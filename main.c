#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"
#include "data.h"
#include "lesao.h"

#define MAX_TAM_PACIENTES 127 // must be a prime number


//espera uma string e soma algarismos sequenciais
//ao encontrar um caracter nao numero multiplica a soma com a proxima soma(exceto 0)
// ex: 78174`9041!391 0@9203193(2  seria transformado em
//(7+8+1+7+4)*(9+0+4+1)*(3+9+1)*(1)*(9+2+0+3+1+9+3)*(2)
int converte(char* s);

int cb_otemchave(void* item);



int main()
{
    Hash *HTable = Hcreate(MAX_TAM_PACIENTES, hfunc, cb_otemchave, freePaciente);
    
    if(HTable == NULL)
     exit(0);
    
    char tipo;

    while(scanf("%c\n",&tipo)){

        if(tipo == 'F')
         break;
        
        else if(tipo == 'P'){
           
            char *nome;
            scanf("%s\n",nome);
            Data d = lerData();
            char *idSUS;
            scanf("%s\n",idSUS); //caso nao tratado, id valido, tratar depois
            char gend;
            scanf("%c\n",&gend);
                           
            if(!Hexist(converte(idSUS),HTable) ){// funcao que verefica se o bendito existe, 1 se sim 0 se n
              if(gend=='M' || gend=='O' || gend=='F')
                Hinsert(HTable, PacienteCreate(nome, idSUS, gend, &d)); //inserido caso nao existe o ID e gen valido
            }  

        }
        else if(tipo == 'L'){

            char *idSUS;
            scanf("%s\n",idSUS);
            char *idlesao;
            scanf("%s\n",idlesao);
            char *diagnostico;
            scanf("%s\n",diagnostico);
            char *regiao;
            scanf("%s\n",regiao);
            int malignidade;
            scanf("%c\n",&malignidade);
            //depois de ler tudo(resetar o buffer)
            //verefirica se ja existe ou nao esse paciente
            if(Hexist(converte(idSUS),HTable)){ 
                insereW(,WoundCreate(idSUS, idlesao, diagnostico, regiao, malignidade));

            }


        }
      
    
    }

    return 0;
}


int converte(char* s){
    int tam = strlen(s);
    unsigned int sum = 0;
    unsigned int total = 0;

    for(int i=0; i<tam ;i++){
        if(s[i] > '0'  && s[i] <= '9') // se for igual a 0 nao eh necessario somar 0
         sum = sum+(s[i]-'0');
        else if(s[i] != 0)  // caso nao esteja entre os algarismos e nao seja o 0
                if(total == 0) // em teoria so vai acontecer 1 vez
                 total = sum;
                else {
                 if(sum!=0) //caso 2 caracteres nao algarismos seguidos, nao multiplicar pois soma eh 0
                  total = total*sum;  
                 sum = 0; // condicao essencial para continuar, 
                }
    }
  return total; //espero q tudo ocorra bem
}

int cb_otemchave(void* item){
    return (converte(getID(item))); //get vai dar a id do sus, converte vai transformar pra uma chave
}