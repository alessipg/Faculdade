/*2) Repita o programa da questão 1 fazendo a seguinte modificação: altere o passo c de forma que a variável unsigned int
seja iniciada com um valor lido do teclado pela função scanf. Nesta questão, você não poderá usar a variável unsigned int 
dentro da função scanf. Em vez disto, use o ponteiro. É uma questão desafio: pesquise/pense como fazer isso.*/

#include <stdio.h>
#include <stdlib.h>
int main (){
    unsigned int a;//a)
    unsigned int *p = NULL;//a)
    p = &a;//b)
    scanf("%d", p);
    /*Vi em alguns exemplos que o programador pode utilizar malloc para alocar o espaço necessário para o unsigned int,
    porém como apontei p para a na linha 10, acredito que isso já tenha sido feito, dessa forma o código rodou normalmente.*/
    
    printf("Endereco de p: %p / Endereco que p aponta: %p / Valor que p aponta: %d\n\n",&p,p,*p);
    printf("Endereco de a: %p / Valor de a: %d / Valor de a referenciado por ponteiro: %d",&a,a,*p);
    return 0;
}