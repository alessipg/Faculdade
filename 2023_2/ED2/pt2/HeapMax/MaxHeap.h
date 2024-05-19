#ifndef MAX_HEAP_H
#define MAX_HEAP_H

typedef struct {
    int* vetor;
    int capacidade;
} MaxHeap;

/*
 * Fun��o para alocar o heap em mem�ria.
*/
MaxHeap* criarMaxHeap(int capacidade);

/*
 * Fun��o para inserir uma chave no heap.
 * Par�metro: heap - ponteiro para o heap.
 * Par�metro: chave - chave que ser� inserida no heap.
*/
void inserir(MaxHeap* heap, int chave);

/*
 * Fun��o para remover uma chave do heap (remove sempre o maior elemento - raiz).
 * Par�metro: heap - ponteiro para o heap.
 * Retorno: maior elemento no heap ou -1 se o heap estiver vazio.
*/
int remover(MaxHeap* heap);
/*
 * Fun��o para imprimir o heap.
 * Par�metro: heap - ponteiro para o heap.
*/
void imprimirHeap(MaxHeap* heap);

/*
 * Fun��o para desalocar o heap passado por par�metro da mem�ria.
 * Par�metro: heap - ponteiro para o heap.
*/
void destruirHeap(MaxHeap* heap);

#endif