#include <stdio.h>
#include <stdlib.h>
#include "arvoreGen.h"

struct Arv{

    void *dado;

    Arv *e;
    Arv *d;
};


Arv *criaArv(){
    return NULL;
}

int arv_vazia(Arv *a){
    return a==NULL;
}

Arv* insereArv(Arv *a, void *dado, compara_fcpt compara){
    
    if(arv_vazia(a)){

        a = (Arv*)malloc(sizeof(Arv));
        a->dado = dado;
        a->e = a->d = criaArv();

    } else if(compara(dado, a->dado) < 0){
        a->e = insereArv(a->e, dado, compara);
    } else {
        a->d = insereArv(a->d, dado, compara);
    }

    return a;
}

void imprimeArv(Arv *a, imprime_fcpt imprime){

    if(!arv_vazia(a)){
        imprimeArv(a->e, imprime);
        imprimeArv(a->d, imprime);
        imprime(a->dado);
    }
}

void liberaArv(Arv *a, libera_fcpt libera){

    if(!arv_vazia(a)){
        liberaArv(a->e, libera);
        liberaArv(a->d, libera);
        libera(a->dado);
        free(a);
    }
}