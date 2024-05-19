#include <stdio.h>
#include "MinHeap.h"

int main() {
    MinHeap* heap = criarMinHeap(10);

    inserir(heap, 10);
    inserir(heap, 5);
    inserir(heap, 20);
    inserir(heap, 32);
    inserir(heap, 15);
    inserir(heap, 4);
    inserir(heap, 2);
    inserir(heap, 8);
    inserir(heap, 3);
    inserir(heap, 1);

    imprimirHeap(heap);
    printf("Elementos removidos em ordem crescente: ");
    while (heap->vetor[0] > 0) {
        printf("%d ", remover(heap));
    }
    printf("\n");

    imprimirHeap(heap);
    destruirHeap(heap);

    return 0;
}