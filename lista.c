#include <stdio.h>
#include <string.h>
#include <stlib.h>
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

    if (Lista->Ultimo == NULL){

        Lista->Primeiro = Lista->Ultimo = novo;

    }else{

        Lista->Ultimo->prox = novo;
        Lista->Ultimo = Lista->Ultimo->prox;

    }

    Lista->Ultimo->produto = p;
    Lista->Ultimo->prox = NULL;
}

void *retiraDaLista (Lista *Lista, int codSol){

    Celula* ant = NULL;

    Celula* p = Lista->prim;

    while (p != NULL && RetornaCodProduto(Lista->produto) != codSol){

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

        Lista->ptim = p->prox;

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