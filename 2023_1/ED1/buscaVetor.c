#include <stdio.h>

int buscaVetor(int vet[], int ind, int i){
    for(int j = 0; j<ind ;j++){
        if(vet[j]==i){
            return j;
        }
    }
    return -1;
}

void printRecursivo(int v[], int n){
    //caso base 
    if(n <= 0 || v == NULL) return;

    printf("%d\n", v[n-1]);
    printRecursivo(v,n-1);
    
}
int main(){
    int vetor[10] = {0,1,2,3,4,5,6,7,8,9};
    //printf("%d\n",buscaVetor(vetor,10,11)); 
    printRecursivo(vetor,10);
}


/*
 *Busca binária
 * requisito: vetor ordenado
 * desempenho: ~log² n para n chaves
 * busca sequencial>desempenho: n iterações
 * 
 * 
 *
 */