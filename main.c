#include<stdio.h>
#include<stdlib.h>
#include "matriz.h"

int main(){

    int linhas=0, colunas=0;
    int numero=0;

    printf("Indique as proporções das matrizes:\n");

    scanf("%d %d", &linhas, &colunas);
    scanf("%*c");

    Matriz *m1 = inicializaMatriz(linhas, colunas);

    Matriz *m2 = inicializaMatriz(linhas, colunas);

    printf("Escreva quais numeros irão preencher a Primeira Matriz:\n");

    for(int i=0; i < linhas; i++){
        for(int j=0; j < colunas; j++){

            scanf("%d", &numero);
            scanf("%*c");

            modificaElemento(m1, i, j, numero);

        }
    }

    printf("Escreva quais numeros irão preencher a Segunda Matriz:\n");

    for(int i=0; i < linhas; i++){
        for(int j=0; j < colunas; j++){

            scanf("%d", &numero);
            scanf("%*c");

            modificaElemento(m2, i, j, numero);

        }
    }

    printf("Matriz Numero 1:\n");

    imprimeMatriz(m1);

    printf("Matriz Numero 2:\n");

    imprimeMatriz(m2);



    return 0;
}