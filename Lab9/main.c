#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include "aluno.h"
#include "arvore.h"

int main(){

    Aluno *a;
    Aluno *b;
    Aluno *c;

    a = CriaAluno();
    b = CriaAluno();
    c = CriaAluno();
    
    LeAluno(a);

    LeAluno(b);

    LeAluno(c);

    Arv* arvore = arv_criavazia();
    Arv* dir = arv_criavazia();
    Arv* esq = arv_criavazia();

    dir = arv_cria(c, NULL, NULL);
    esq = arv_cria(b, NULL, NULL);
    arvore = arv_cria(a, esq, dir);

    arv_imprime(arvore);

    arv_libera(arvore);






    return 0;
}