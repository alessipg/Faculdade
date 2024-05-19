#include <stdio.h>
#include <stdlib.h>


typedef struct TNo{
    int chave;
    struct TNo *prox;
    struct TNo *ant;
} TNo;

TNo **pesquisa(TNo **prim, int k){

    while(prim != NULL){
        k--;
        if(k == 0) return prim;
        prim = &((*prim)->prox);
    }
}

void remove(TNo *prim){
    
}

int main (){
    TNo *prim;
    int k = 3;

    TNo *aux = pesquisa(&prim, k);
    remove(aux);
}