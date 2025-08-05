#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "arvore.h"

struct Arv{

    Aluno *aluno;

    Arv *esq;
    Arv *dir;
};


//Cria uma árvore vazia
Arv* arv_criavazia (void){
    return NULL;
}

//cria uma árvore com a informação do nó raiz c, e com subárvore esquerda e e subárvore direita d
Arv* arv_cria (Aluno* c, Arv* e, Arv* d){

    Arv* p = (Arv*)malloc(sizeof(Arv));

    p->aluno = c;

    p->esq = e;

    p->dir = d;

    return p;
}

//libera o espaço de memória ocupado pela árvore a
Arv* arv_libera (Arv* a){

    if(!arv_vazia(a)){
        
        ApagaAluno(a->aluno);
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }

    return NULL;
}

//retorna true se a árvore estiver vazia e false caso contrário
int arv_vazia (Arv* a){

    return a==NULL;
}

//indica a ocorrência (1) ou não (0) do aluno (pela chave de busca mat)
int arv_pertence (Arv* a, int mat){

    if(arv_vazia(a)){
        return 0; // a arvore esta vazia
    } else{
        if(retornaMatricula(a->aluno) == mat){
            return 1;
        } else {
            return arv_pertence(a->esq, mat) || arv_pertence(a->dir, mat);
        }
    }
}

//imprime as informações dos nós da árvore
void arv_imprime (Arv* a){

    if(!arv_vazia(a)){
        ImprimeAluno(a->aluno);
        arv_imprime(a->esq);
        arv_imprime(a->dir);
    }
}

//retorna a mãe/pai de um dado no que contém o aluno com a matrícula mat
Arv* arv_pai (Arv* a, int mat);

//retorna a quantidade de folhas de uma arvore binaria
int folhas (Arv* a);

//retorna o numero de ocorrencias de um dado aluno na árvore
int ocorrencias (Arv* a, int mat);

//retorna a altura da árvore a
int altura(Arv* a);