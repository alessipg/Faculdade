/*5) Pesquise pelo significado dos seguintes erros relacionados a ponteiros e forne�a um exemplo de programa para cada erro. 
COloque a explica��o em forma de coment�rio dentro de cada respectivo c�digo.
*/
#include <stdio.h>
#include <stdlib.h>

int main (){
    
//a) leitura ilegal
int *p;
printf("%d", *p);
//explica��o: foi tentado ler o valor de um ponteiro inicializado sem defini��o, ou seja, ele est� apontado para um local lixo da
//mem�ria, mas em alguns casos pode estar em um local de dados de outros programas ou at� do SO, o que seria um erro cr�tico em alguns casos.
//b) escrita ilegal
scanf("%d", p);
//aqui ocorre o mesmo, por�m com inser��o de valor. Eu posso estar alterando um valor na mem�ria de algum dado importante, isso
//na programa��o � algo inadmiss�vel
}