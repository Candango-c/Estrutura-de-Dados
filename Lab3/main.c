#include<stdio.h>
#include<stdlib.h>
#include "matriz.h"

int main(){

    int linhas1=0, colunas1=0, linhas2=0, colunas2=0;
    int numero=0;

    printf("Indique as proporções da matriz 1:\n");

    scanf("%d %d", &linhas1, &colunas1);
    scanf("%*c");

    Matriz *m1 = inicializaMatriz(linhas1, colunas1);

    printf("Escreva quais numeros irão preencher a Primeira Matriz:\n");

    for(int i=0; i < linhas1; i++){
        for(int j=0; j < colunas1; j++){

            scanf("%d", &numero);
            scanf("%*c");

            modificaElemento(m1, i, j, numero);

        }
    }

    printf("Indique as proporções da matriz 2:\n");

    scanf("%d %d", &linhas2, &colunas2);
    scanf("%*c");

    Matriz *m2 = inicializaMatriz(linhas2, colunas2);

    printf("Escreva quais numeros irão preencher a Segunda Matriz:\n");

    for(int i=0; i < linhas2; i++){
        for(int j=0; j < colunas2; j++){

            scanf("%d", &numero);
            scanf("%*c");

            modificaElemento(m2, i, j, numero);

        }
    }

    printf("Matriz Numero 1:\n");

    imprimeMatriz(m1);

    printf("Matriz Numero 2:\n");

    imprimeMatriz(m2);

    printf("A matriz transposta da Matriz numero 1:\n");

    Matriz *trp1; 

    trp1 = transposta(m1);

    imprimeMatriz(trp1);

    printf("A matriz transposta da Matriz numero 2:\n");

    Matriz *trp2;

    trp2 = transposta(m2);

    imprimeMatriz(trp2);

    printf("A multiplicao entre as matrizes:\n");

    if(linhas2 == colunas1){

        Matriz *multi;

        multi = multiplicacao(m1, m2);

        imprimeMatriz(multi);

        destroiMatriz(multi);

    } else {

        printf("nao é possivel multiplicar as matrizes.\n");

    }

    destroiMatriz(m1);

    destroiMatriz(m2);

    destroiMatriz(trp1);

    destroiMatriz(trp2);

    return 0;
}