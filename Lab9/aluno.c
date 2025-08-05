#include "aluno.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Aluno{

    char* nome; /**< Ponteiro para nome do aluno, que será alocado dinamicamente*/
    int matricula; /**< Matrícula do aluno */
    int n1, n2, n3; /**< Notas das avaliações */

};

Aluno* CriaAluno(){

    Aluno *aluno = (Aluno *)malloc(sizeof(struct Aluno));

    aluno->nome = NULL;

    aluno->matricula = -1;
    aluno->n1 = -1;
    aluno->n2 = -1;
    aluno->n3 = -1;

    return aluno;

}

void ApagaAluno(Aluno *aluno){

    free(aluno->nome);

    free(aluno);

}

void LeAluno(Aluno *aluno){

    aluno->nome = (char *)malloc(10 * sizeof(char));

    scanf("%s", aluno->nome);
    scanf("%*c");

    scanf("%d", &aluno->matricula);
    scanf("%*c");

    scanf("%d %d %d", &aluno->n1, &aluno->n2, &aluno->n3);
    scanf("%*c");

}

int ComparaMatricula(Aluno* aluno1, Aluno* aluno2){

    if(aluno1->matricula > aluno2->matricula){
        return 1;
    } else if(aluno1->matricula < aluno2->matricula){
        return -1;
    } else {
        return 0;
    }

}

int retornaMatricula(Aluno* a){

    return a->matricula;
}

int CalculaMediaAluno(Aluno* aluno){

    int media = 0;

    media = (aluno->n1 + aluno->n2 + aluno->n3) / 3;

    return media;

}

int VerificaAprovacao(Aluno* aluno){

    int media = 0;

    media = CalculaMediaAluno(aluno);

    if(media >= 7){
        return 1;
    } else {
        return 0;
    }

}

void ImprimeAluno(Aluno* aluno){

    printf("%s\n", aluno->nome);
    printf("%d\n", aluno->matricula);

}