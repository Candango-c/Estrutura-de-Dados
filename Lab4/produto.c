#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

    printf("Diga o nome do produto: ");

    nome = leLinha();

    printf("\n");

    printf("Informe o codigo do produto: ");

    scanf("%d", &cod);
    scanf("%*c");

    printf("\n");

    printf("Digite o preço do produto: ");

    scanf("%d", &valor);
    scanf("%*c");

    printf("\n");

    Produto* p;

    p = criaProduto(nome, cod, valor);


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

int RetornaCodProduto(Produto *p){

    return p->cod;
}

void NotificaProduto(Produto *p){
    
    printf("Nome: %s\n", p->nome);
    printf("Codigo: %d\n", p->cod);
    printf("Preço: %d\n", p->preco);
}
