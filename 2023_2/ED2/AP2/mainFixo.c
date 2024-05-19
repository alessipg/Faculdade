#include "HashFixo.h"
#include <time.h>
#include <stdio.h>
/*
 *Para compilar:
 * gcc mainFixo.c HashFixo.c -o exe
 * ./exe
 * 
*/
/*
 * Ressalva: a inserção nessa tabela é feita diretamente no nodo "raiz" de cada posição, isto é, não existe uma "cabeça" da lista,
 * a cabeça é o último elemento inserido naquela posição.
*/
int main()
{
    time_t c1, c2;
    c1 = clock();
    printf("=============Arquivo 1================\n");
    lerArquivos("in1.txt");
    printf("=============Arquivo 2================\n");
    lerArquivos("in2.txt");
    printf("=============Arquivo 3================\n");
    lerArquivos("in3.txt");
    c2 = clock();
    printf("======================================\n");
    printf("Tempo total de execucao em segundos: %lf\n",((c2-c1))/(double)CLOCKS_PER_SEC);
}
