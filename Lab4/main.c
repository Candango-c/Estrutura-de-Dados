#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "produto.h"
#include "util.h"
#include "lista.h"

int painel(){
    int n=0;
    printf("Digite o numero da ordem que quer executar:\n");
    printf("1 - Criar um produto e adiciona ele na lista\n");
    printf("2 - Retirar um produto da lista\n");
    printf("3 - Imprimir a lista completa de produtos\n");
    printf("4 - Encerrar o Programa\n");

    scanf("%d", &n);
    scanf("%*c");

    return n;
}

int main(){

    int escolha=0;
    int codSol=0;

    Lista *l = criaLista();

    while(1){

        escolha = painel();

        if(escolha == 1){

            insereNaLista(lerProduto(), l);


        } else if(escolha == 2){

            printf("Informe o codigo do produto a ser retirado: ");

            scanf("%d", &codSol);
            scanf("%*c");

            printf("\n");

            retiraDaLista(l, codSol);

            printf("Produto(%d) retirado.\n", codSol);


        } else if(escolha == 3){

            printf("Relatorio da lista de produtos:\n");

            imprimeLista(l);


        } else if(escolha == 4){

            printf("Programa encerrado.\n");

            break;


        }
    }

    desalocaLista(l);



    return 0;
}