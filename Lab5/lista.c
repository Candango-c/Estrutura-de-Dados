#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "produto.h"
#include "util.h"
#include "lista.h"


struct Celula{

    Produto *produto;
    Celula *prox;
    Celula *ant;

};

Celula *criaLista(){

    return NULL;
}

Celula *insereNaLista (Produto* p, Celula* c){

    Celula* novo = (Celula*) malloc(sizeof(Celula));

    novo->produto = p;
    novo->prox = c;
    novo->ant = NULL;

    if(c != NULL){

        c->ant = novo;

    }

    return novo;
}

Celula *buscaNaLista (Celula* c, int codSol){
    Celula *b;

    for(b = c; b != NULL; b = b->prox){
        if(RetornaCodProduto(b->produto) == codSol){

            return b;
        }
    }

    return NULL;
}

Celula* retiraDaLista (Celula *c, int codSol){

    Celula* b = buscaNaLista(c, codSol);

    if(b == NULL){

        return c; 

    }

    if(c == b){

        c = b->prox;
    } else {

        b->ant->prox = b->prox;
    }

    if(b->prox != NULL){

        b->prox->ant = b->ant;
    }

    if (b->produto != NULL) {  // Libera o produto antes de liberar a célula
        desalocaProduto(b->produto);
    }

    free(b);
    return c;
}

void desalocaLista(Celula *c){

    Celula* b = c;

    while(b != NULL){

        Celula* proximo = b->prox;

        if(b->produto != NULL){

            desalocaProduto(b->produto);
        }

        free(b);

        b = proximo;
    }
}

void imprimeLista(Celula *c){

    Celula* aux;

    aux = c;

    while(aux != NULL){

        if(aux->produto != NULL){

            NotificaProduto(aux->produto);
            printf("-----------------------\n");
        }

        aux = aux->prox;
    }
}
