#ifndef _PRODUTO_H
#define _PRODUTO_H


typedef struct Produto Produto;

Produto *criaProduto();

Produto *lerProduto();

void desalocaProduto(Produto *p);

void NotificaProduto(Produto *p);

#endif