#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "produto.h"
#include "util.h"

struct Produto{

    char* nome;

    int valor;

};


Produto *criaProduto(char* nome, int valor){

    Produto *p = (Produto*)malloc(sizeof(Produto));

    p->nome = nome;

    p->valor = valor;

    return p;



}

Produto *lerProduto(){

    char* nome;

    int valor=0;

    nome = leLinha();

    scanf("%d", &valor);
    scanf("%*c");

    Produto *p;

    p = criaProduto(nome, valor);

    return p;




}

void NotificaProduto(Produto *p){
    
    printf("Item: %s, valor unitario: %d,", p->nome, p->valor);
    

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