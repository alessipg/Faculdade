/*1) Escreva um programa em C que executa o seguinte sequ�ncia de passos:

a) declare uma vari�vel do tipo unsigned int e outra do tipo ponteiro para unsigned int; 
Lembre de inicializar o ponteiro com NULL;

b) fa�a a vari�vel ponteiro apontar para a vari�vel unsigned int;

c) utilize a vari�vel ponteiro para alterar o valor da vari�vel short int(aqui acredito que o correto seria unsigned int) para 3
e imprime o endere�o de mem�ria das vari�veis bem como seus respectivos valores.
A impress�o do valor da vari�vel unsigned int voc� deve ser feita por meio da vari�vel ponteiro.

Em caso de d�vidas, tome a decis�o que julgar mais apropriada para o enunciado.*/
#include <stdio.h>
#include <stdlib.h>
int main (){
    unsigned int a;//a)
    unsigned int *p = NULL;//a)
    p = &a;//b)
    *p = 3;
    printf("Endereco de p: %p / Endereco que p aponta: %p / Valor que p aponta: %d\n\n",&p,p,*p);
    printf("Endereco de a: %p / Valor de a: %d / Valor de a referenciado por ponteiro: %d",&a,a,*p);
    return 0;
}