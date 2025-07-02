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
Arv* arv_libera (Arv* a);

//retorna true se a árvore estiver vazia e false caso contrário
int arv_vazia (Arv* a);

//indica a ocorrência (1) ou não (0) do aluno (pela chave de busca mat)
int arv_pertence (Arv* a, int mat);

//imprime as informações dos nós da árvore
void arv_imprime (Arv* a);

//retorna a mãe/pai de um dado no que contém o aluno com a matrícula mat
Arv* arv_pai (Arv* a, int mat);

//retorna a quantidade de folhas de uma arvore binaria
int folhas (Arv* a);

//retorna o numero de ocorrencias de um dado aluno na árvore
int ocorrencias (Arv* a, int mat);

//retorna a altura da árvore a
int altura(Arv* a);