/*4) O que acontece se tentarmos gravar um valor qualquer na regi�o de mem�ria cujo endere�o � igual a NULL? 
Explique e apresente um programa para exemplificar.*/
#include <stdio.h>
#include <stdlib.h>

int main (){
    int *a = NULL;
    *a = 3;
    printf("%d",*a);
}
//o programa compilou por�m apresentou um segmentation fault, afinal o valor foi armazenado em nulo, e consequentemente perdido.