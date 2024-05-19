#ifndef NODO_H
#define NODO_H

typedef struct No{
    int chave;               // Chave que identifica o nodo.
    struct No* pai;          // Ponteiro para o pai do nodo.
    struct No* direita;      // Ponteiro para o filho da direita.
    struct No* esquerda;     // Ponteiro para o filho da esquerda.
} Nodo;

/*
 * Fun��o para alocar um nodo em mem�ria.
 * Par�metro: chave - identificador do nodo.
 * Retorno: endere�o do nodo em mem�ria. O valor NULL ser� retornado em caso de falha na aloca��o.
*/
Nodo* criarNodo(int chave);

/*
 * Fun��o para calcular o n�vel do nodo passado por par�metro.
 * Par�metro: nodo - ponteiro para um nodo.
 * Retorno: n�vel do nodo.
*/
int calcNivel(Nodo* nodo);

/*
 * Fun��o para calcular a altura do nodo passado por par�metro.
 * Par�metro: nodo - ponteiro para um nodo.
 * Retorno: altura do nodo.
*/
int calcAltura(Nodo* nodo);

/*
 * Fun��o para calcular o grau do nodo passado por par�metro.
 * Par�metro: nodo - ponteiro para um nodo.
 * Retorno: grau do nodo.
*/
int calcGrau(Nodo* nodo);

/*
 * Fun��o para desalocar o nodo passado por par�metro da mem�ria.
 * Par�metro: nodo - ponteiro para um nodo.
*/
void destruirNodo(Nodo* nodo);

#endif