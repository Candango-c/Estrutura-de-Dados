#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bubble.h"

static int compara (int a, int b){
    
    if (a > b){
        return 1;
    }else{
        return 0;
    }
}

void bubblesort (int n, int* v)
{ int i, j;
  for (i=n-1; i>0; i--) {
    int troca = 0;
    for (j=0; j<i; j++)
      if (compara(v[j],v[j+1])) {
        int temp = v[j];   /* troca */
        v[j] = v[j+1];
        v[j+1] = temp;
        troca = 1;
      }
    if (troca == 0)      /* não houve troca */
      return;
  }
}

void rapida (int n, int* v){
    
    if (n <= 1){
        return;
    }else {
        int x = v[0];
        int a = 1;
        int b = n-1;

        do {
            while (a < n && v[a] <= x){
                a++;
            }
            while (v[b] > x){
                b--;
            }
            if (a < b){
                int temp = v[a];
                v[a] = v[b];
                v[b] = temp;
                a++; 
                b--;
            }
        } while (a <= b);{
            v[0] = v[b];
            v[b] = x;
            /* ordena sub-vetores restantes */
            rapida(b,v);
            rapida(n-a,&v[a]);

        }
    }
}