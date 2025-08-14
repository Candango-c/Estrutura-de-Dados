#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

#define NPAL 64
#define NTAB 127

struct Palavra{

    char *pal;
    int frequencia;

    Palavra *prox;

};  

struct Hash{

    int n;
    int dim; //dimensao da tabela
    Palavra **v;

};

Palavra *cria_palavra(char *str){

    Palavra *p = (Palavra*)malloc(sizeof(Palavra));

    p->pal = strdup(str);
    p->frequencia = 1;
    p->prox = NULL;

    return p;
}

Hash *cria_hash(){

    Hash *tab = (Hash*)malloc(sizeof(Hash));
    tab -> n = 0;
    tab -> dim = 7; //dimensao da tabela
    tab ->v = (Palavra**)malloc(tab -> dim*sizeof (Palavra*));

    for (int i=0; i<tab -> dim; ++i){
        tab ->v[i] = NULL;
    }
    return tab;
    
}

static int hash(Hash *tab, char *str){

    int total = 0;

    for(int i=0; str[i] != '\0'; i++){

        total +=str[i];
    }

    return (total % tab->dim);
}

static void redimensiona(Hash *tab){

    int max_ant = tab->dim;
    Palavra **ant = tab->v;

    tab ->n = 0;
    tab -> dim *= 1.947; // evitar múltiplos
    tab ->v = (Palavra**) malloc(tab -> dim*sizeof (Palavra*));

    for (int i=0; i<tab -> dim; ++i){
        tab ->v[i] = NULL;
    }
    for (int i=0; i< max_ant; ++i) {
        if (ant[i]) {
            hash_insere(tab ,ant[i]);
    }
    }
    free(ant);
}

void *hash_insere(Hash *tab, Palavra *pal){

    if(tab->n > 0.75 * tab->dim){
        redimensiona(tab);
    }

    int h = hash(tab, pal->pal);

    while(tab->v[h] != NULL){
        h = (h+1) % tab -> dim; // incremento c i r c u l a r 
    }

    tab->v[h] = pal;
    tab->n++;

}