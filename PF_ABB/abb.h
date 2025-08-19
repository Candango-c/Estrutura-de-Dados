#ifndef ABB
#define ABB

typedef struct Arv Arv;

Arv *cria_arv();

int vazia_arv(Arv *a);

Arv *insere_arv(Arv *a, char *nome);

void chamada_arv(Arv *a, char *nome, char presenca);

int compara_nome(char *nome, char *nome2);

void atualiza_presenca(Arv *a, char presenca);

void imprime_arv(Arv *a, FILE *arq);

void libera_arv(Arv *a);


#endif