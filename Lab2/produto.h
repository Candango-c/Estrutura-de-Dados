#ifndef _PRODUTO_H
#define _PRODUTO_H


typedef struct Produto Produto;

Produto *criaProduto(char* nome, int valor, int qntd);

Produto *lerProduto();

int getQuantidade(Produto *p);

void desalocaProduto(Produto *p);

void NotificaProduto(Produto *p);

#endif