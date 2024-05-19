#ifndef AVL_H
#define AVL_H

#include "Nodo.h"

Nodo* raiz;     // Ponteiro para a raiz da �rvore.

/*
 * Fun��o para inicializar a raiz da �rvore.
 * Retorno: valor NULL, indica que a �rvore est� vazia.
*/
Nodo* criarAVL();
int altura(Nodo* nodo);

int maximo(int a, int b);
/*
 * Fun��o para inserir uma nova chave na �rvore.
 * Par�metro: raiz - ponteiro para o nodo que representa a raiz da �rvore.
 * Par�metro: chave - chave que ser� inserida.
 * Retorno: a nova raiz da �rvore.
*/
Nodo* inserirChave(Nodo* raiz, int chave);

/*
 * Fun��o para buscar uma chave na �rvore.
 * Par�metro: raiz - ponteiro para o nodo que representa a raiz da �rvore.
 * Par�metro: chave - chave de busca.
 * Retorno: o nodo associado a chave de busca. O valor NULL ser� retornado se a chave n�o estiver na �rvore.
*/
Nodo* buscarChave(Nodo* raiz, int chave);

/*
 * Fun��o para exibir a �rvore em pr�-ordem (exibi��o: raiz, esquerda, direita).
 * Par�metro: raiz - ponteiro para o nodo que representa a raiz da �rvore.
*/
void exibirPreOrdem(Nodo* raiz);

/*
 * Fun��o para exibir a �rvore em ordem (exibi��o: esquerda, raiz, direita).
 * Par�metro: raiz - ponteiro para o nodo que representa a raiz da �rvore.
*/
void exibirEmOrdem(Nodo* raiz);

/*
 * Fun��o para exibir a �rvore em p�s-ordem (esquerda, direita, raiz).
 * Par�metro: raiz - ponteiro para o nodo que representa a raiz da �rvore.
*/
void exibirPosOrdem(Nodo* raiz);

/*
 * Fun��o para exibir algumas informa��es sobre os nodos na �rvore (por exemplo: altura, n�vel e grau).
 * Par�metro: raiz - ponteiro para o nodo que representa a raiz da �rvore.
*/
void exibirInfNodos(Nodo* raiz);

/*
 * Fun��o para desalocar a �rvore passada por par�metro da mem�ria.
 * Par�metro: raiz - ponteiro para o nodo que representa a raiz da �rvore.
*/
void destruirAVL(Nodo* raiz);

#endif