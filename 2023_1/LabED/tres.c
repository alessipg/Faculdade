/*3) O que acontece se tentarmos imprimir na tela o conteúdo armazenado no byte de endereço igual a NULL? 
Explique e apresente um programa para exemplificar.*/
#include <stdio.h>
#include <stdlib.h>


int main (){
    int *a = NULL;
    printf("%p", a);
    //quando tento imprimir o endereco, o programa roda normal e imprime o valor 000000, afinal
    //o ponteiro não está em nenhum endereço

    //printf("%d", *a);
    //porém se eu tentar imprimir o conteúdo do ponteiro, o programa apresentará um segmentation fault, um comportamento
    //indevido, pois como o ponteiro sequer está em um endereço, ele também não possui conteúdo.


}