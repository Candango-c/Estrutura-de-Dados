#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

int main(){

    Country *c;
    Hash *tab = create_hash();

    FILE* ptr = fopen("entrada.txt", "r");
    if (ptr == NULL) {
        printf("no such file.");
    return 0;
    }

    char name[100];
    int gold=0;
    int silver=0;
    int bronze=0;

    while(fscanf(ptr, "%s %d %d %d %*d", name, &gold, &silver, &bronze) == 4){

        c = create_country(name, gold, silver, bronze);

        tab = insert_country_hash(tab, c);
        fscanf(ptr, "%*c");

    }

    fclose(ptr);

    FILE *arq = fopen("saida.txt", "w");

    print_hash(tab, arq);

    fclose(arq);

    free_hash(tab);

    return 0;
}