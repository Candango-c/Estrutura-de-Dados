#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "produto.h"
#include "util.h"
#include "filial.h"
#include "market.h"

int main(){

    Market *mercado;

    int n=0;
    int qntd=0;

    printf("Informe o nome do supermercado: ");

    mercado = criaMercado();

    printf("Quantas filiais esse supermercado possui?\n");

    scanf("%d", &n);
    scanf("%*c");


    for(int i = 0; i < n; i++){

        printf("Qual o nome da filial de numero %d?\n", i+1);

        insereFilialMarket(mercado);

        printf("Quantos Produtos essa filial possui?\n");

        scanf("%d", &qntd);
        scanf("%*c");

        for(int i2 = 0; i2 < qntd; i2++){

            printf("Diga o nome, valor e quantidade em estoque do produto de numero %d.\n", i2+1);

            insereProdutoFilial(getFilialDoMarkert(mercado, i));

        }


    }

    printf("\n");
    printf("Relatorio:\n");

    notificaMarket(mercado);

    desalocaMarket(mercado);


    return 0;
}