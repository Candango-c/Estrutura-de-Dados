#ifndef _MARKET_H
#define _MARKET_H

#include "filial.h"

typedef struct Market Market;

Market *criaMercado();

void desalocaMarket(Market *m);

void insereFilialMarket(Market *m);

int getQntdFilialDoMarkert(Market *m);

Loja *getFilialDoMarkert(Market *m, int i);

int getEstoqueTotal(Market *m);

void notificaMarket(Market *m);



#endif