#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "produto.h"
#include "util.h"

struct Produto{

    char* nome;

    int valor;

    int quantidade;

};


Produto *criaProduto(char* nome, int valor, int qntd){

    Produto *p = (Produto*)malloc(sizeof(Produto));

    p->nome = nome;

    p->valor = valor;

    p->quantidade = qntd;

    return p;



}

Produto *lerProduto(){

    char* nome;

    int valor=0;

    int qntd=0;

    nome = leLinha();

    scanf("%d", &valor);
    scanf("%*c");

    scanf("%d", &qntd);
    scanf("%*c");

    Produto *p;

    p = criaProduto(nome, valor, qntd);

    return p;




}

void NotificaProduto(Produto *p){
    
    printf("Item: %s, valor unitario: %d, quantidade: %d\n", p->nome, p->valor, p->quantidade);
    

}

int getQuantidade(Produto *p){

    return p->quantidade;
}

void desalocaProduto(Produto *p){

    if(p != NULL){

        if(p->nome != NULL){

            free(p->nome);
            p->nome = NULL;

        }

        free(p);
        p = NULL;

    }

}