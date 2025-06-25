#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Lista.h"

typedef struct Celula Celula;

struct Celula{

    char *nome;
    int calorias;
    float valor;

    //se for vegana tipo =2 se for nao vegana tipo =3
    int tipo;

    Celula *prox;

};

struct Lista{

    Celula *prim;
    Celula *ult;

    //quantas comidas estao na lista
    int quantidade;

    //valor total da lista
    float valorTL;


};

Lista *criaLista(){

    Lista *l = (Lista*)malloc(sizeof(Lista));

    l->ult = NULL;
    l->prim = NULL;
    l->quantidade =0;
    l->valorTL=0;

    return l;
}

void *insereNaLista(char *nome, int calorias, float valor, int tipo, Lista *l){

    Celula *novo = (Celula*)malloc(sizeof(Celula));

    if(l->ult == NULL){
        
        l->prim = l->ult = novo;
    } else {

        l->ult->prox = novo;
        l->ult = l->ult->prox;
    }

    l->ult->nome = strdup(nome);
    l->ult->calorias = calorias;
    l->ult->valor = valor;
    l->ult->tipo = tipo;
    l->ult->prox = NULL;
    l->quantidade++;
    l->valorTL += valor;
}

int retonarQntdLista(Lista *l){

    return l->quantidade;
}

float retonaValorDaLista(Lista *l){

    return l->valorTL;

}

void *desalocaLista(Lista *l){

    Celula *prim = l->prim;
    Celula *prox;

    while(prim != NULL){

        prox = prim->prox;
        
        if(prim != NULL){

            if(prim->nome != NULL){

                free(prim->nome);
            }
            free(prim);
        }
        prim = prox;

    }

    free(l);
}

void *imprimeLista(Lista *l){

    Celula* aux;

    aux = l->prim;

    while(aux != NULL){

        if(aux->tipo == 2){

            printf("Nome comida vegana: %s, calorias: %d\n", aux->nome, aux->calorias);

        } else {

            printf("Nome comida nao vegana: %s, valor: %.2f, calorias: %d\n", aux->nome, aux->valor, aux->calorias);
        }

        aux = aux->prox;

    }

}