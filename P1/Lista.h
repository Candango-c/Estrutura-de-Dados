#ifndef LISTA_H
#define LISTA_H


#include "ComidaVegana.h"
#include "ComidaNaoVegana.h"

typedef struct Lista Lista;

Lista *criaLista();

int retonarQntdLista(Lista *l);

float retonaValorDaLista(Lista *l);

void *insereNaLista(char *nome, int calorias, float valor, int tipo, Lista *l);

void retiraDalista(Lista *l);

void *desalocaLista(Lista *l);

void *imprimeLista(Lista *l);

#endif