#ifndef ARVGEN
#define ARVGEN

typedef int (*compara_fcpt)(void *, void *);
typedef void (*imprime_fcpt)(void *);
typedef void (*libera_fcpt)(void *);

typedef struct Arv Arv;

Arv *criaArv();

int arv_vazia(Arv *a);

Arv* insereArv(Arv *a, void *dado, compara_fcpt compara);

void imprimeArv(Arv *a, imprime_fcpt imprime);

void liberaArv(Arv *a, libera_fcpt libera);


#endif