#include <stdio.h>
#include <stdlib.h>

void vetorPrimeiroRec(int v[], int i, int tam)
{
    if (i < 0)
        return;
    if (i < tam)
        printf("%d ", v[i]);
    vetorPrimeiroRec(v, i - 1, tam);
}

int main (){
    int *v;
    int tam;
    printf("Insira um tamanho de vetor: ");
    scanf("%d", &tam);
    v = (int*)malloc(sizeof(int)*tam);
    if(v == NULL){
        printf("Erro ao alocar memoria\n");
        return -1;
    }
    
    printf("Insira valores para o vetor: \n");
    for (int i = 0; i < tam; i++)
    {
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }
    
    vetorPrimeiroRec(v, tam, tam);
    return 0;
}