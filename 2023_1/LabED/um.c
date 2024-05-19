/*1) Escreva um programa em C que executa o seguinte sequência de passos:

a) declare uma variável do tipo unsigned int e outra do tipo ponteiro para unsigned int; 
Lembre de inicializar o ponteiro com NULL;

b) faça a variável ponteiro apontar para a variável unsigned int;

c) utilize a variável ponteiro para alterar o valor da variável short int(aqui acredito que o correto seria unsigned int) para 3
e imprime o endereço de memória das variáveis bem como seus respectivos valores.
A impressão do valor da variável unsigned int você deve ser feita por meio da variável ponteiro.

Em caso de dúvidas, tome a decisão que julgar mais apropriada para o enunciado.*/
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