#ifndef _FILIAL_H
#define _FILIAL_H

#include "produto.h"
#include "util.h"

typedef struct Loja Loja;

Loja *criaFilial();

void desalocaFilial(Loja *l);

void insereProdutoFilial(Loja *l);

int getEstoqueLoja(Loja *l);

int getQntdProdutosNaFilial(Loja *l);

Produto *getProdutoNaFilial(Loja *l, int i);

void notificaFilial(Loja *l);


#endif