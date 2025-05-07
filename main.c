#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "produto.h"
#include "util.h"

int main(){

    //TADS
    Produto *p;

    p = lerProduto();

    NotificaProduto(p);

    desalocaProduto(p);


    return 0;
}