#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "filial.h"

struct Loja{

    Produto **produtos;

    char *nome;

    int estoque;

    int totalP;

    int maxP;


};

Loja *criaFilial(){

    char *nome;

    nome = leLinha();

    Loja *loja = (Loja*) malloc(sizeof(Loja));

    loja->nome = nome;

    loja->produtos = malloc(sizeof(Produto*)*10);

    loja->estoque = 0;

    loja->totalP = 0;

    loja->maxP = 10;

    return loja;

}

void desalocaFilial(Loja *l){

    int i=0;
    int n=0;

    n = getQntdProdutosNaFilial(l);

    if(l !=NULL){

        if(l->produtos !=NULL){

            for(i=0; i < n; i++){

                desalocaProduto(getProdutoNaFilial(l, i));
            }
        }
    }

    free(l->produtos);
    free(l->nome); 
    free(l);
}

void insereProdutoFilial(Loja *l){

    if(l->totalP == l->maxP){

        l->maxP *= 2;

        l->produtos = realloc (l->produtos, sizeof(Produto*)*l->maxP);
    }

    l->produtos[l->totalP] = lerProduto();

    l->totalP++;
}

int getQntdProdutosNaFilial(Loja *l){

    return l->totalP;
}

Produto *getProdutoNaFilial(Loja *l, int i){

    return l->produtos[i];
}

int getEstoqueLoja(Loja *l){

    int i=0;
    int n=0;
    int emEstoque=0;
    int soma=0;

    n = getQntdProdutosNaFilial(l);

    for(i=0; i < n; i++){

        emEstoque = getQuantidade(l->produtos[i]);

        soma += emEstoque;

    }

    return soma;

    
}

void notificaFilial(Loja *l){

    int i=0;
    int n=0;

    n = getQntdProdutosNaFilial(l);

    printf("Filial: %s, ", l->nome);

    printf("Estoque: %d\n", getEstoqueLoja(l));

    for(i=0; i < n; i++){
        printf("    ");
        NotificaProduto(getProdutoNaFilial(l, i));

    }

}
