#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct Produto Produto;

Produto *criaProduto(char* nome, int cod, int valor);

Produto *lerProduto();

void desalocaProduto(Produto *p);

void NotificaProduto(Produto *p);

#endif