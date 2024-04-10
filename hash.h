#ifndef _HASH_H_
#define _HASH_H_

typedef struct hash Hash;

typedef int (*hash_func)(int akey, int htam); // funcao hash, retorna posicao da tabela
typedef int (*get_akey)(void *object);        // funcao para obter chave
typedef void (*free_bucket_item)(void *item); // funcao para liberar um item da hash

Hash *Hcreate(int tam, hash_func hashf, get_akey getf, free_bucket_item freeb);
void Herase(Hash *h);
int hfunc(int akey, int htam);
void Hinsert(Hash *h, void *item);
int Hexist(int a, Hash *h);
void* Hget(Hash *h, int key);

#endif