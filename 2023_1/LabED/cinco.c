/*5) Pesquise pelo significado dos seguintes erros relacionados a ponteiros e forneça um exemplo de programa para cada erro. 
COloque a explicação em forma de comentário dentro de cada respectivo código.
*/
#include <stdio.h>
#include <stdlib.h>

int main (){
    
//a) leitura ilegal
int *p;
printf("%d", *p);
//explicação: foi tentado ler o valor de um ponteiro inicializado sem definição, ou seja, ele está apontado para um local lixo da
//memória, mas em alguns casos pode estar em um local de dados de outros programas ou até do SO, o que seria um erro crítico em alguns casos.
//b) escrita ilegal
scanf("%d", p);
//aqui ocorre o mesmo, porém com inserção de valor. Eu posso estar alterando um valor na memória de algum dado importante, isso
//na programação é algo inadmissível
}