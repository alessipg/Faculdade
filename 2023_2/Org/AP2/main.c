#include <stdio.h>
#include "Direto.h"
#include "FIFO.h"
#include "LFU.h"
#include "LRU.h"
// Nome: Gabriel Alessi Posonski RA: 2259583
// Informacoes importantes:
// Compila��o: gcc Direto.c FIFO.c LRU.c LFU.c main.c -o exe
// Execu��o: ./exe
// Estava encontrando alguns problemas com vazamento de mem�ria, ent�o mantive cada implementa��o em um arquivo �nico
// mesmo que algumas fun��es pudessem ser reaproveitadas em mais de um tipo de mem�ria cache.
// O desempenho para as instru��es disponibilizadas no Moodle ficaram id�nticas ao final da execu��o, por�m realizei alguns
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