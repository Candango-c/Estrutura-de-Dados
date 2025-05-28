#ifndef LISTA_H
#define LISTA_H

#include "produto.h"

typedef struct Celula Celula;

Celula *criaLista();

Celula *insereNaLista (Produto* p, Celula* c);

Celula *buscaNaLista (Celula* c, int codSol);

Celula* retiraDaLista (Celula *c, int codSol);

void desalocaLista(Celula *c);

void imprimeLista(Celula *c);

#endif