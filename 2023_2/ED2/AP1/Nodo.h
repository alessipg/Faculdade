#ifndef NODO_H
#define NODO_H

typedef struct No{
    int chave;               // Chave que identifica o nodo.
    struct No* pai;          // Ponteiro para o pai do nodo.
    struct No* direita;      // Ponteiro para o filho da direita.
    struct No* esquerda;     // Ponteiro para o filho da esquerda.
} Nodo;

/*
 * Função para alocar um nodo em memória.
 * Parâmetro: chave - identificador do nodo.
 * Retorno: endereço do nodo em memória. O valor NULL será retornado em caso de falha na alocação.
*/
Nodo* criarNodo(int chave);

/*
 * Função para calcular o nível do nodo passado por parâmetro.
 * Parâmetro: nodo - ponteiro para um nodo.
 * Retorno: nível do nodo.
*/
int calcNivel(Nodo* nodo);

/*
 * Função para calcular a altura do nodo passado por parâmetro.
 * Parâmetro: nodo - ponteiro para um nodo.
 * Retorno: altura do nodo.
*/
int calcAltura(Nodo* nodo);

/*
 * Função para calcular o grau do nodo passado por parâmetro.
 * Parâmetro: nodo - ponteiro para um nodo.
 * Retorno: grau do nodo.
*/
int calcGrau(Nodo* nodo);

/*
 * Função para desalocar o nodo passado por parâmetro da memória.
 * Parâmetro: nodo - ponteiro para um nodo.
*/
void destruirNodo(Nodo* nodo);

#endif