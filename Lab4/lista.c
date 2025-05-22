#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "produto.h"
#include "util.h"
#include "lista.h"

typedef struct Celula Celula;

struct Celula{

    Produto *produto;
    Celula *prox;

};

struct Lista{

    Celula *prim;
    Celula *ult;

};

Lista *criaLista(){

    Lista* l = (Lista*) malloc(sizeof(Lista));

    l->ult = NULL;
    l->prim = NULL;

    return l;
}

void *insereNaLista (Produto* p, Lista* Lista){

    Celula* novo = (Celula*) malloc(sizeof(Celula));

    if (Lista->ult == NULL){

        Lista->prim = Lista->ult = novo;

    }else{

        Lista->ult->prox = novo;
        Lista->ult = Lista->ult->prox;

    }

    Lista->ult->produto = p;
    Lista->ult->prox = NULL;
}

void *retiraDaLista (Lista *Lista, int codSol){

    Celula* ant = NULL;

    Celula* p = Lista->prim;

    while (p != NULL && RetornaCodProduto(p->produto) != codSol){

        ant = p;

        p = p->prox;
    }

    if (p == NULL){

        return;

    }

    if (p == Lista->prim && p == Lista->ult){
        
        Lista->prim = Lista->ult = NULL;

        free (p);

        return;

    }

    if (p == Lista->ult){

        Lista->ult = ant; ant->prox = NULL;

        free (p);

        return;
    }

    if (p == Lista->prim){

        Lista->prim = p->prox;

    }else{

        ant->prox = p->prox;

    }

    free(p);
}

void *desalocaLista(Lista *l){

    Celula *prim = l->prim;
    Celula *prox;

    while(prim != NULL){

        prox = prim->prox;
        desalocaProduto(prim->produto);
        free(prim);
        prim = prox;

    }

    free(l);
}