/*3) O que acontece se tentarmos imprimir na tela o conte�do armazenado no byte de endere�o igual a NULL? 
Explique e apresente um programa para exemplificar.*/
#include <stdio.h>
#include <stdlib.h>


int main (){
    int *a = NULL;
    printf("%p", a);
    //quando tento imprimir o endereco, o programa roda normal e imprime o valor 000000, afinal
    //o ponteiro n�o est� em nenhum endere�o

    //printf("%d", *a);
    //por�m se eu tentar imprimir o conte�do do ponteiro, o programa apresentar� um segmentation fault, um comportamento
    //indevido, pois como o ponteiro sequer est� em um endere�o, ele tamb�m n�o possui conte�do.


}