#ifndef ALUNOS
#define ALUNOS

#define TAM_MAX 200

typedef struct Aluno Aluno;

typedef Aluno *Hash[TAM_MAX];

void inicializa_hash(Hash tab);

void insere_hash(Hash tab, char *nome, char presenca);

void imprime_aluno(Aluno *a, FILE *arq);

void libera_aluno(Aluno *a);

void libera_hash(Hash tab);

void imprime_hash(Hash tab, FILE *arq);



#endif