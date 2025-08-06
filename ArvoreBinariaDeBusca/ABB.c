#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"

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

//busca um valor especifico na arvore
Arv *abb_Busca(Arv *a, void *valor){

    if(arv_vazia(a)){
        return a;
    }else if(a->dado > valor){

     return abb_Busca (a->e, valor);

    }else if (a->dado < valor){
         return abb_Busca (a->d, valor);
    }else{
         return a;
    }

}

Arv *abb_retira(Arv *a, void *valor){

    if(arv_vazia(a)){

        return NULL;

    } else if(a->dado > valor){ //busca onde esta o nó

        a->e = abb_retira(a->e, valor);

    } else if( a->dado < valor){ //busca onde esta o nó

        a->d = abb_retira(a->d, valor);

    } else { //achou o nó a ser removido
        
        if(a->e == NULL && a->d == NULL){ //nó sem filhos
            free(a);
            a = NULL;

        } else if(a->e == NULL){ //o nó só tem filho na direita
            Arv *aux = a;
            a= a->d;
            free(aux);

        } else if(a->d == NULL){ //o nó só tem filho na esquerda
            Arv *aux = a;
            a= a->e;
            free(aux);

        } else { // o nó tem filhos na esquerda e na direita
            Arv *aux = a->e;

            while(!arv_vazia(aux->d)){
                aux = aux->d;
            }
            a->dado = aux->dado;            //
            aux->dado = valor;              // TROCA AS INFORMAÇÕES
            a->e = abb_retira(a->e, valor); //


        }

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