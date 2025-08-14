#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main(){

    Hash * tab = cria_hash();

    FILE* arq = fopen("entrada.txt", "r");

    while(!feof(arq)){

        char *str;

        fscanf(arq, "%[^\n ]", str);
        fscanf(arq, "%*c");

        Palavra *p = cria_palavra(str);

        hash_insere(tab, p);
    }

    printf("pronto");

}