#include <stdio.h>
#include <string.h>
#include <stlib.h>
#include "produto.h"
#include "util.h"

struct Produto{

    int cod;

    char* nome;

    int preco;


};

Produto *criaProduto(char* nome, int cod, int valor){

    Produto *p = (Produto*) malloc(sizeof(Produto));

    p->nome = nome;

    p->cod = cod;

    p->preco = valor;

    return p;

}

Produto *lerProduto(){
    char* nome;

    int valor=0;

    int cod=0;

    nome = 

    return p;
}

void desalocaProduto(Produto *p){

    if(p->nome !=NULL){

        free(p->nome);
        p->nome = NULL;

    }

    if(p != NULL){

        free(p);
        p = NULL;
    }

}

void NotificaProduto(Produto *p){
    
    printf("Nome: %s\n", p->nome);
    printf("Codigo: %d\n", p->cod);
    printf("Preço: %d\n", p->preco);
}

