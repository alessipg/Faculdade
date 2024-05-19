#include <stdio.h>
#include "Direto.h"
#include "FIFO.h"
#include "LFU.h"
#include "LRU.h"
// Nome: Gabriel Alessi Posonski RA: 2259583
// Informacoes importantes:
// Compilação: gcc Direto.c FIFO.c LRU.c LFU.c main.c -o exe
// Execução: ./exe
// Estava encontrando alguns problemas com vazamento de memória, então mantive cada implementação em um arquivo único
// mesmo que algumas funções pudessem ser reaproveitadas em mais de um tipo de memória cache.
// O desempenho para as instruções disponibilizadas no Moodle ficaram idênticas ao final da execução, porém realizei alguns
// testes e pareceu se comportar da maneira prevista para cada formato de cache.
int main()
{
    int opcao = 0;
    printf("======================================\n");
    printf("======SIMULADOR DE MEMORIA CACHE======\n");
    printf("======================================\n");
    printf("Selecione o formato de memoria desejado:\n");
    printf("1 - Mapeamento Direto\n");
    printf("2 - Associativo - FIFO\n");
    printf("3 - Associativo - LRU\n");
    printf("4 - Associativo - LFU\n");
    printf("5 - Sair\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        menuDireto();
        break;
    case 2:
        menuFIFO();
        break;
    case 3:
        menuLRU();
        break;
    case 4:
        menuLFU();
        break;
    case 5:
        printf("Finalizando...\n");
        break;
    default:
        printf("Opcao invalida\n");
    }
}