#include <stdio.h>
#include <stdlib.h>
#include "MinHeap.h"

/*
 * FUN��O PRIVADA
 *
 * Fun��o para trocar os valores de duas vari�veis.
 * Par�metro: v1 - vari�vel 1.
 * Par�metro: v2 - vari�vel 2.
*/
void troca(int *v1, int *v2) {
    int aux = *v1;
    *v1 = *v2;
    *v2 = aux;
}

/*
 * FUN��O PRIVADA
 *
 * Fun��o para ajustar o heap. 
 * Garante que os filhos de um nodo sejam menores ou iguais ao pai.
 * Par�metro: heap - ponteiro para o heap.
 * Par�metro: i - �ndice do nodo pai.
*/
void heapify(MinHeap* heap, int i) {
    int maior = i;
    int filhoEsquerda = 2 * i;
    int filhoDireita = 2 * i + 1;
    
    // Nodo pai possui dois filhos
    if (filhoEsquerda <= heap->vetor[0] && filhoDireita <= heap->vetor[0]) {
        if (heap->vetor[filhoEsquerda] < heap->vetor[maior] && heap->vetor[filhoEsquerda] < heap->vetor[filhoDireita]) {
            maior = filhoEsquerda;
        }
        else if (heap->vetor[filhoDireita] < heap->vetor[maior] && heap->vetor[filhoDireita] < heap->vetor[filhoEsquerda]) {
            maior = filhoDireita;
        }
    }
    // Nodo pai possui apenas o filho da esquerda
    else if (filhoEsquerda <= heap->vetor[0] && heap->vetor[filhoEsquerda] < heap->vetor[maior]) {
        maior = filhoEsquerda;
    }
    // Nodo pai possui apenas o filho da direita
    else if (filhoDireita <= heap->vetor[0] && heap->vetor[filhoDireita] < heap->vetor[maior]) {
        maior = filhoDireita;
    }
    // Se um dos filhos � maior do que o pai, o maior filho assume o lugar do pai
    if (maior != i) {
        troca(&heap->vetor[i], &heap->vetor[maior]);
        heapify(heap, maior);
    }
}

MinHeap* criarMinHeap(int capacidade) {
    MinHeap* heap = (MinHeap*) malloc(sizeof(MinHeap));
    heap->vetor = (int*) malloc(capacidade * sizeof(int));
    heap->vetor[0] = 0;
    heap->capacidade = capacidade;
    return heap;
}

void inserir(MinHeap* heap, int chave) {
    if (heap != NULL && heap->vetor != NULL) {
        
        // Se o heap estiver vazio, a chave � insirida na raiz
        if (heap->vetor[0] == 0){
            heap->vetor[1] = chave;
            heap->vetor[0]++;
        }
        else {
            // Se o heap estiver cheio, sua capacidade � dobrada antes da inser��o da chave.        
            if (heap->vetor[0] == heap->capacidade) {
                int* vet = realloc(heap->vetor, heap->capacidade * 2);

                if (vet != NULL) {
                    heap->vetor = vet;
                }
                else {
                    printf("Heap cheio! N�o � poss�vel inserir mais elementos.\n");
                    return;
                }
            }
            heap->vetor[0]++;
            int i = heap->vetor[0];
            int pai = i / 2;
            heap->vetor[i] = chave;
            
            while (i > 1 && heap->vetor[i] < heap->vetor[pai]) {
                troca(&heap->vetor[i], &heap->vetor[pai]);
                i = pai;
                pai = pai/2;
            }
        }
    }
}

int remover(MinHeap* heap) {
    if (heap != NULL && heap->vetor != NULL) {    
        if (heap->vetor[0] == 0) {
            printf("Heap vazio!\n");
            return -1;
        }
        int raiz = heap->vetor[1];
        heap->vetor[1] = heap->vetor[heap->vetor[0]];
        heap->vetor[0]--;
        heapify(heap, 1);
        return raiz;
    }
}

void imprimirHeap(MinHeap* heap) {
    if (heap != NULL && heap->vetor != NULL) {
        if (heap->vetor[0] == 0) {
            printf("Heap vazio!\n");
        }
        else {
            printf("Heap: ");
            for (int i = 0; i <= heap->vetor[0]; i++) {
                printf("%d ", heap->vetor[i]);
            }
            printf("\n");
        }
    }
}

void destruirHeap(MinHeap* heap) {
    free(heap->vetor);
    free(heap);
}