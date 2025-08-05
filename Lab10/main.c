#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bubble.h"


#define TAMANHO_VETOR 100000

int main() {
    
    int *vetor_aleatorio;
    int i;
    double tempo=0;
    clock_t start, end;

    start = clock();

    srand(time(NULL));

    vetor_aleatorio = malloc(TAMANHO_VETOR * sizeof(int));

    printf("Gerando %d números aleatórios...\n", TAMANHO_VETOR);

    // Preenche o vetor com números aleatórios
    for (i = 0; i < TAMANHO_VETOR; i++) {
    
        vetor_aleatorio[i] = rand();
    }

    printf("Vetor com %d números aleatórios gerado com sucesso!\n", TAMANHO_VETOR);

    //bubblesort(TAMANHO_VETOR, vetor_aleatorio);
    rapida(TAMANHO_VETOR, vetor_aleatorio);
    
    printf("\nExibindo os 10 primeiros números do vetor:\n");
    for (i = 0; i < 10; i++) {
        printf("%d\n", vetor_aleatorio[i]);
    }
    
    end = clock();

    tempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execucao : %.6f\n", tempo);

    return 0;
}