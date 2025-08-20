#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alunos.h"

struct Aluno{

    char *nome;

    int presenca;
    int falta;

    Aluno *prox;

};

void inicializa_hash(Hash tab){

    for(int i=0; i < TAM_MAX; i++){

        tab[i] = NULL;

    }

}

static int hash(char *nome){

    int id=0;

    for(int i=0; nome[i] != '\0'; i++){

        id += (int)nome[i];

    }

    return(id % TAM_MAX);

}

void insere_hash(Hash tab, char *nome, char presenca){

    int h = hash(nome);

    Aluno *a = tab[h];

    while(a != NULL){
        if(strcmp(nome, a->nome)==0){
            break;
        }
        a = a->prox;
    }

    if(a==NULL){

        a = (Aluno*)malloc(sizeof(Aluno));
        a->nome = strdup(nome);
        a->prox = tab[h];
        a->falta =0;
        a->presenca=0;
        tab[h] = a;

    }

    if(presenca == 'F'){
        a->falta++;
    } else if(presenca == 'P'){
        a->presenca++;
    }

}

Aluno *retorna_aluno(Hash tab, int h){
    return tab[h];
}

void imprime_aluno(Aluno *a, FILE *arq){

    if(a != NULL){

        fprintf(arq, "%s    %dP %dF\n", a->nome, a->presenca, a->falta);
        imprime_aluno(a->prox, arq);

    }
}

void libera_aluno(Aluno *a){

    if(a != NULL){

        free(a->nome);
        libera_aluno(a->prox);
        free(a);

    }

}

void libera_hash(Hash tab){

    for(int i=0; i < TAM_MAX; i++){

        if(tab[i] != NULL){

            libera_aluno(tab[i]);

        }

    }

}

void imprime_hash(Hash tab, FILE *arq){

    for(int i=0; i < TAM_MAX; i++){

        if(tab[i] != NULL){

            imprime_aluno(tab[i], arq);

        }

    }

}