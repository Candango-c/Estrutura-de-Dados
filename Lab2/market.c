#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "market.h"

struct Market{

    Loja **lojas;

    int estoque;

    int qntdLojas;

    int maxL;

    char *nome;

};

Market *criaMercado(){

    char *nome;

    nome = leLinha();

    Market *m = (Market*) malloc(sizeof(Market));

    m->lojas = malloc(sizeof(Loja*)*10); 

    m->nome = nome;

    m->qntdLojas = 0;

    m->maxL = 10;

    m->estoque = 0;

    return m;

}

void desalocaMarket(Market *m){

    int i=0;
    int n=0;

    n = getQntdFilialDoMarkert(m);

    if(m != NULL){

        if(m->lojas != NULL){

            for(i=0; i < n; i++){

                desalocaFilial(getFilialDoMarkert(m, i));

            }
        }
    }

    free(m->lojas);
    free(m->nome);
    free(m);


}

void insereFilialMarket(Market *m){
    
    if(m->qntdLojas == m->maxL){

        m->maxL *= 2;

        m->lojas = realloc (m->lojas, sizeof(Loja*)*m->maxL);

    }

    m->lojas[m->qntdLojas] = criaFilial();

    m->qntdLojas++;


}

int getQntdFilialDoMarkert(Market *m){

    return m->qntdLojas;
}

Loja *getFilialDoMarkert(Market *m, int i){

    return m->lojas[i];
}

int getEstoqueTotal(Market *m){

    int i=0;
    int n=0;
    int emEstoque=0;
    int soma=0;

    n = getQntdFilialDoMarkert(m);

    for(i=0; i < n; i++){

        emEstoque = getEstoqueLoja(m->lojas[i]);

        soma += emEstoque;

    }

    return soma;

}

void notificaMarket(Market *m){

    int i=0;
    int n=0;

    n = getQntdFilialDoMarkert(m);

    printf("Nome:%s,Estoque Total:%d\n", m->nome, getEstoqueTotal(m));

    for(i=0; i < n; i++){

        printf("    ");
        notificaFilial(getFilialDoMarkert(m, i));
        printf("\n");

    }


}

