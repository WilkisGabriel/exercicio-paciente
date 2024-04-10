#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

struct bucket
{
    int chave;
    void *item;
    struct bucket *next;
};
typedef struct bucket bucket_t;

struct hash
{
    int tam; //tamanho
    int qnt; //quantidade no array 
    bucket_t **buckets;
    hash_func hfunc; 
    get_akey getkey;
    free_bucket_item freecb;
};

Hash *Hcreate(int tam, hash_func hashf, get_akey getf, free_bucket_item freeb)
{
    if (hashf == NULL || getf == NULL || freeb == NULL)
        return NULL;

    Hash *h = (Hash *)calloc(1, sizeof(Hash));
    h->tam = tam;
    h->qnt = 0;
    h->hfunc = hashf;
    h->getkey = getf;
    h->freecb = freeb;
    h->buckets = (bucket_t **)calloc(tam, sizeof(bucket_t *));
    return h;
}

void Herase(Hash *h)
{ // se existir
    if (h != NULL)
    { // nao for vazio
        if (h->qnt > 0)
        { // roda a tabela
            for (int i = 0; i < h->tam; i++)
            { // liberando os remanescentes
                if (h->buckets[i] != NULL)
                    Berase(h->buckets[i], h->freecb);
            }
        }
        free(h->buckets); // tabela
        free(h);          // struct
    }
}


bucket_t *Bcreate(int key, void *item)
{
    bucket_t *b = (bucket_t *)calloc(1, sizeof(bucket_t));
    b->chave = key;
    b->item = item;
    b->next = NULL;
    return b;
}


void Berase(bucket_t *b, free_bucket_item cb)
{
    bucket_t *aux = b->next;
    while (b != NULL)
    {
        cb(b->item);
        free(b);
        b = aux;

        if (aux != NULL)
            aux = aux->next;
    }
}


int hfunc(int akey, int htam) //retorna posicao do vetor basicamente
{
    return akey % htam;
}


void Hinsert(Hash *h, void *item)
{
    bucket_t *b = Bcreate(h->getkey(item), item); // cria o slot

    if (h->buckets[h->hfunc(b->chave, h->tam)] == NULL) // se a posicao da tabela gerada pela chave estiver vazia
        h->buckets[h->hfunc(b->chave, h->tam)] = b;     // insere
    else
    { // colisao, tratamento lista
        bucket_t *aux = h->buckets[h->hfunc(b->chave, h->tam)];
        ; // auxiliar
        while (aux->next != NULL)
        {                    // enquanto o proximo da lista nao for null
            aux = aux->next; // recebe o proximo
        }
        aux->next = b; // insere no prox;
    }
    h->qnt++;
}

int Hexist(int key, Hash *h){
    if(h->buckets[h->hfunc(a,h->tam)] != NULL){ // se a posicao dessa chave nao estiver vazia
      if(h->buckets[h->hfunc(a,h->tam)]->chave == key) //e for igual a chave
        return 1; // verdadeiro
      else{
       bucket_t *aux = h->buckets[h->hfunc(a,h->tam)]; 
       for(aux->next != NULL){ //roda a lista
         aux = aux->next;
         if(aux->chave == key)
          return 1;
       }
      }
        
    }
  return 0; // se chegar eh pq nao existe 
}

void* Hget(Hash *h, int key){

    bucket_t *aux = h->buckets[h->hfunc(key, h->tam)];
    if(aux == NULL)
     return NULL;
    else{
      if(aux->chave == key)
       return aux->item;
      else 
       for(aux=aux->next; aux!=NULL ;aux=aux->next)
         if(aux->chave == key)
          return aux->item;      
    }
   return NULL;
}
