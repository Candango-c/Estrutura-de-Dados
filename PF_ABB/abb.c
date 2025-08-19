#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "abb.h"

struct Arv{

    char *nome;
    int presenca;
    int falta;

    Arv *esq;
    Arv *dir;

};

Arv *cria_arv(){

    return NULL;
}

int vazia_arv(Arv *a){

    return a == NULL;
}

Arv *insere_arv(Arv *a, char *nome){

    if(vazia_arv(a)){

        a = (Arv*)malloc(sizeof(Arv));
        a->nome = strdup(nome);
        a->falta = 0;
        a->presenca = 0;
        a->esq = a->dir = cria_arv();

    } else {

        if(compara_nome(a->nome, nome) == -1){

            a->dir = insere_arv(a->dir, nome);

        } else {

            a->esq = insere_arv(a->esq, nome);
        }

    }

    return a;
}

int compara_nome(char *nome, char *nome2){

    if(strcmp(nome, nome2) == 0){ //nomes iguais

        return 2;

    } else if(strcmp(nome, nome2) < 0){ //nome do nó é menor que o novo nome

        return -1;
    
    } else {

        return 1;
    }

}

void chamada_arv(Arv *a, char *nome, char presenca){

    if(!vazia_arv(a)){

        if(compara_nome(a->nome, nome) == 2){

            atualiza_presenca(a, presenca);

        } else if(compara_nome(a->nome, nome) != -1){

            chamada_arv(a->esq, nome, presenca);

        } else {

            chamada_arv(a->dir, nome, presenca);
        }
    
    }

}

void atualiza_presenca(Arv *a, char presenca){

    if(presenca == 'F'){
        a->falta++;
    } else {
        a->presenca++;
    }

}

void imprime_arv(Arv *a, FILE * arq){

    if(!vazia_arv(a)){

        
        imprime_arv(a->esq, arq);
        fprintf(arq, "%s    %dP %dF\n", a->nome, a->presenca, a->falta);
        imprime_arv(a->dir,arq);

    }
}

void libera_arv(Arv *a){

    if(!vazia_arv(a)){

        free(a->nome);
        libera_arv(a->esq);
        libera_arv(a->dir);
        free(a);

    }

}