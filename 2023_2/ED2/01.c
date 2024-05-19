#include <stdio.h>
typedef struct ixi{
    int a, b;
}ixi;
void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}
int main(){

    ixi *teste = malloc(sizeof(ixi));
    teste->a = 3;
    teste->b = 2;
    troca(&teste->a,&teste->b);
    printf("a = %d, b = %d\n",teste->a,teste->b);
}