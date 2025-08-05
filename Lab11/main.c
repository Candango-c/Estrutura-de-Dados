#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "arvoreGen.h"

int main(){

    int n;

    scanf("%d", &n);

    Arv *arvore;
    arvore = criaArv();

    Aluno *aluno;

    for(int i=0; i < n; i++){
        aluno = CriaAluno();
        LeAluno(aluno);

       arvore = insereArv(arvore, aluno, ComparaMatricula);
    }

    imprimeArv(arvore, ImprimeAluno);
    liberaArv(arvore, ApagaAluno);

    return 0;
}