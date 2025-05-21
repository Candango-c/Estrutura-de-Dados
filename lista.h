#ifndef LISTA_H
#define LISTA_H

#include "produto.h"

typedef struct Lista Lista;

Lista *criaLista();

void *insereNaLista(Produto* p, Lista* l);

void *retiraDaLista(Lista *l, int codSol);

void *desalocaLista(Lista *l);

void *imprimeLista(Lista *l);

#endif