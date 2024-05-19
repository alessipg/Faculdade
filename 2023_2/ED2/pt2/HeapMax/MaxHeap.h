#ifndef MAX_HEAP_H
#define MAX_HEAP_H

typedef struct {
    int* vetor;
    int capacidade;
} MaxHeap;

/*
 * Função para alocar o heap em memória.
*/
MaxHeap* criarMaxHeap(int capacidade);

/*
 * Função para inserir uma chave no heap.
 * Parâmetro: heap - ponteiro para o heap.
 * Parâmetro: chave - chave que será inserida no heap.
*/
void inserir(MaxHeap* heap, int chave);

/*
 * Função para remover uma chave do heap (remove sempre o maior elemento - raiz).
 * Parâmetro: heap - ponteiro para o heap.
 * Retorno: maior elemento no heap ou -1 se o heap estiver vazio.
*/
int remover(MaxHeap* heap);
/*
 * Função para imprimir o heap.
 * Parâmetro: heap - ponteiro para o heap.
*/
void imprimirHeap(MaxHeap* heap);

/*
 * Função para desalocar o heap passado por parâmetro da memória.
 * Parâmetro: heap - ponteiro para o heap.
*/
void destruirHeap(MaxHeap* heap);

#endif