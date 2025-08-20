#include <stdio.h>
#include <stdlib.h>
#include "alunos.h"

int main(){

    Hash tab;
    inicializa_hash(tab);

    FILE* ptr = fopen("entrada.txt", "r");
    if (ptr == NULL) {
        printf("no such file.");
    return 0;
    }

    int num_arqs=0;

    fscanf(ptr, "%*c %d", &num_arqs);
    fscanf(ptr, "%*c");

    char nome[100];
    char presenca;

    while(!feof(ptr)){

        fscanf(ptr, "%s", nome);
        //printf("%s\n", nome);

        insere_hash(tab, nome, 'c');
        fscanf(ptr, "%*c");

    }

    fclose(ptr);

        for(int i=1; i <= num_arqs; i++){

        char caminho[50];
        sprintf(caminho,"entrada%d.txt", i);
        
        FILE * arq = fopen(caminho, "r");

        while (fscanf(arq, "%s %c", nome, &presenca) == 2){

            insere_hash(tab, nome, presenca);
            
        }

        fclose(arq);

    }

    FILE *arq = fopen("saida.txt", "w");

    imprime_hash(tab, arq);

    fclose(arq);

    libera_hash(tab);


    return 0;
}