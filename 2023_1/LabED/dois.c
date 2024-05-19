/*2) Repita o programa da quest�o 1 fazendo a seguinte modifica��o: altere o passo c de forma que a vari�vel unsigned int
seja iniciada com um valor lido do teclado pela fun��o scanf. Nesta quest�o, voc� n�o poder� usar a vari�vel unsigned int 
dentro da fun��o scanf. Em vez disto, use o ponteiro. � uma quest�o desafio: pesquise/pense como fazer isso.*/

#include <stdio.h>
#include <stdlib.h>
int main (){
    unsigned int a;//a)
    unsigned int *p = NULL;//a)
    p = &a;//b)
    scanf("%d", p);
    /*Vi em alguns exemplos que o programador pode utilizar malloc para alocar o espa�o necess�rio para o unsigned int,
    por�m como apontei p para a na linha 10, acredito que isso j� tenha sido feito, dessa forma o c�digo rodou normalmente.*/
    
    printf("Endereco de p: %p / Endereco que p aponta: %p / Valor que p aponta: %d\n\n",&p,p,*p);
    printf("Endereco de a: %p / Valor de a: %d / Valor de a referenciado por ponteiro: %d",&a,a,*p);
    return 0;
}