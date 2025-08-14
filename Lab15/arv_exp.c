#include <stdio.h>
#include <stdlib.h>
#include "arv_exp.h"

/*Tipo que define a arvore(tipo opaco)
  Estrutura interna do tipo deve ser definida na implementa��o do TAD. */
struct Arv{

    char c;
    int num;

    Arv* dir;
    Arv* esq;

};

/*Cria uma arvore vazia, ou seja, retorna NULL
* inputs: nenhum
* output: NULL
*/
Arv* CriaVazia(void){

    return NULL;
}

/*cria um n� raiz de operador dados o operador e as duas sub-�rvores, a da esquerda e a da direita
* inputs: o operador, as sub-arvores da esquerda e da direita
* output: o endere�o do n� raiz criado
*/
Arv*  CriaOperador(char c, Arv* esq, Arv* dir){

    Arv *a = (Arv*)malloc(sizeof(Arv*));

    
    a->c = c;
    a->esq = esq;
    a->dir = dir;

    return a;


}

/*cria um n� operando dado o valor do no (como o operando � um n� folha, as sub-arvores da esquerda e da direita s�o nulas
* inputs: o operando
* output: o endere�o do n� raiz criado
*/
Arv* CriaOperando(int valor){

    Arv *a = (Arv*)malloc(sizeof(Arv*));

    a->c = 'v';
    a->num = valor;
    a->esq = NULL;
    a->dir = NULL;

    return a;



}

/*Imprime a �rvore em nota��o InOrder (esq, raiz, direita)
* inputs: o endere�o da raiz da �rvore
* output: nenhum
*/
void Imprime(Arv* arv){

    if(!(arv==NULL)){

        Imprime(arv->esq);
        if(!(arv->c == 'v')){
            printf("%c",arv->c);
        } else {
            printf("%d", arv->num);
        }
        Imprime(arv->dir);

    }

}

/* Libera mem�ria alocada pela estrutura da �rvore
as sub-�rvores devem ser liberadas antes de se liberar o n� raiz
* inputs: o endere�o da raiz da �rvore
* output: uma �rvore vazia, representada por NULL
*/
Arv* Libera (Arv* arv){

    if(!(arv==NULL)){

        if(arv->esq !=NULL){
            Libera(arv->esq);
        }
        if(arv->dir !=NULL){
            Libera(arv->dir);
        }
        free(arv);
    }

    return NULL;
}

/* Retorna o valor correspondente � avalia��o da express�o representada na �rvore
* inputs: o endere�o da raiz da �rvore
* output: o valor da express�o
*/
float Avalia(Arv* arv) {

    //retorna 0 em caso da arvore vazia
    if (arv == NULL) {
        return 0.0;
    }
    
    //
    if (arv->c == 'v') {
        return (float)arv->num;
    }

    float valor_esq = Avalia(arv->esq);
    float valor_dir = Avalia(arv->dir);

    // Aplique a operação apropriada
    switch (arv->c) {
        case '+':
            return valor_esq + valor_dir;
        case '-':
            return valor_esq - valor_dir;
        case '*':
            return valor_esq * valor_dir;
        case '/':
            return valor_esq / valor_dir;
        default:
            printf("Erro: operador invalido\n");
            exit(1);
    }
}



/* Retorna o n�mero de folhas da �rvore
* inputs: o endere�o da raiz da �rvore
* output: o n�mero de folhas
*/
int Folhas(Arv* arv){

 int soma=0;

 if(arv->esq == NULL && arv->dir==NULL){
    return 1;
 }

 soma += Folhas(arv->dir);
 soma += Folhas(arv->esq);

 return soma;

}

/* Retorna a altura da �rvore
* inputs: o endere�o da raiz da �rvore
* output: a altura da �rvore
*/
int Altura(Arv* arv){

    if(arv == NULL){
        return -1;
    } else {
        int alturaEsq=0;
        int alturaDir=0;

        alturaEsq = Altura(arv->esq);
        alturaDir = Altura(arv->dir);

        int alturamax=0;

        if(alturaDir > alturaEsq){

            alturamax = alturaDir + 1;

        } else {

            alturamax = alturaEsq + 1; // caso a direita nao seja maior que a esquerda, as duas sao iguais ou a esquerda é maior

        }

        return alturamax;

    }
}


