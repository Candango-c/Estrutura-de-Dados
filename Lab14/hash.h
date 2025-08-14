#ifndef HASH
#define HASH

typedef struct Palavra Palavra;

typedef struct Hash Hash;

Hash *cria_hash();
Palavra *cria_palavra(char *str);
static int hash(Hash *tab, char *str);
static void redimensiona(Hash *tab);
void *hash_insere(Hash *tab, Palavra *pal);



#endif