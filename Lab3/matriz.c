#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz{

    int** mat;
    int linhas;
    int colunas;


};

/*Inicializa uma matriz de nlinhas e ncolunas
 * inputs: nlinhas (no de linhas) e ncolunas (no de colunas)
 * output: ponteiro para a matriz inicializada
 * pre-condicao: nlinhas e ncolunas diferentes de 0
 * pos-condicao: matriz de retorno existe e contem nlinhas e ncolunas
 */
Matriz* inicializaMatriz (int nlinhas, int ncolunas){

    Matriz *m = malloc(sizeof(Matriz));

    m->mat = malloc(nlinhas *sizeof(int*));

    for (int i=0; i<nlinhas; i++){

       m->mat[i] = (int*) malloc (ncolunas *sizeof(int));
 
    }

    m->linhas = nlinhas;
    m->colunas = ncolunas;

    return m;

}

/*Modifica o elemento [linha][coluna] da matriz mat
 * inputs: a matriz, a linha, a coluna, e o novo elemento
 * output: nenhum
 * pre-condicao: matriz mat existe, linha e coluna sao validos na matriz
 * pos-condicao: elemento [linha][coluna] da matriz modificado
 */
void modificaElemento (Matriz* mat, int linha, int coluna, int elem){

    mat->mat[linha][coluna] = elem;

}

/*Retorna o elemento mat[linha][coluna]
 * inputs: a matriz, a linha e a coluna
 * output: elemento mat[linha][coluna]
 * pre-condicao: matriz mat existe, linha e coluna sao validos na matriz
 * pos-condicao: mat nao eh modificada
 */
int recuperaElemento(Matriz* mat, int linha, int coluna){

    return mat->mat[linha][coluna];
}

/*Retorna o numero de colunas da matriz mat
 * inputs: a matriz
 * output: o numero de colunas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada
 */
int recuperaNColunas (Matriz* mat){

    return mat->colunas;
}

/*Retorna o numero de linhas da matriz mat
 * inputs: a matriz
 * output: o numero de linhas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada
 */
int recuperaNLinhas (Matriz* mat){

    return mat->linhas;
}

/*Retorna a matriz transposta de mat
 * inputs: a matriz
 * output: a matriz transposta
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada e matriz transposta existe
 */
Matriz* transposta (Matriz* mat){

    int i, j;

    Matriz *trp = inicializaMatriz(recuperaNColunas(mat), recuperaNLinhas(mat));

    for (i=0; i<mat->linhas; i++){
        for (j=0; j<mat->colunas; j++){

        trp->mat[j][i] = mat->mat[i][j];

        }
    }

    return trp;

}

/*Retorna a matriz multiplicacao entre mat1 e mat2
 * inputs: as matrizes mat1 e mat2
 * output: a matriz multiplicacao
 * pre-condicao: matrizes mat1 e mat2 existem, e o numero de colunas de mat1 correponde ao numero de linhas de mat2
 * pos-condicao: mat1 e mat2 nao sao modificadas e a matriz multiplicacao existe
 */
Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){

    Matriz *gerada = inicializaMatriz(recuperaNLinhas(mat1), recuperaNColunas(mat2));

    int aux=0;

    for(int i=0; i < mat1->linhas; i++){

        for(int j=0; j < mat2->colunas; j++){

            gerada->mat[i][j] = 0;

            for(int x =0; x < mat2->linhas; x++){
                aux += mat1->mat[i][x] * mat2->mat[x][j];
            }

            gerada->mat[i][j] = aux;
            aux = 0;

        }
    }

    return gerada;
}

/*Imprime a matriz completa
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: nenhuma
 */
void imprimeMatriz(Matriz* mat){

    for(int i = 0; i < mat->linhas; i++){

        for(int j = 0; j < mat->colunas; j++){
            
            printf("%d ", mat->mat[i][j]);

        }
        printf("\n");
    }
}

/*Imprime apenas uma linha da matriz
 * inputs: matriz mat e o indice da linha
 * output: nenhum
 * pre-condicao: matriz mat existe e indice eh valido na matriz
 * pos-condicao: nenhuma
 */
void imprimeLinha (Matriz* mat, int indice){

    for(int i = 0; i < mat->colunas; i++){

        printf("%d ", mat->mat[indice][i]);

    }

}

/*Libera toda a memoria alocada para a matriz
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: memoria ocupada por linhas e colunas liberada!
 */
void destroiMatriz (Matriz* mat){

    for(int i = 0; i < mat->linhas; i++){

        if(mat->mat[i] != NULL){

            free(mat->mat[i]);
        }
        
    }

    if(mat->mat != NULL){

        free(mat->mat);
    }

    if(mat != NULL){

        free(mat);
    }


}