#ifndef ARVORE_BB_H
#define ARVORE_BB_H

#include "Nodo.h"
#include <stdbool.h>
Nodo *raiz; // Ponteiro para a raiz da árvore.

/*
 * Função para inicializar a raiz da árvore.
 * Retorno: valor NULL, indica que a árvore está vazia.
 */
Nodo *criarAVL();

/*
 * Funçao para localizar o sucessor de determinado nodo;
 * Parâmetro: raiz - ponteiro para o nodo que representa a raiz da árvore.
 * Parâmetro: nodo - ponteiro para o nodo que deseja encontrar seu sucessor.
 * Retorno: ponteiro para o nodo sucessor do parâmetro nodo
 */
Nodo *encontrarSucessor(Nodo *raiz, Nodo *nodo);

/*
 * Função para inserir uma nova chave na árvore.
 * Parâmetro: raiz - ponteiro para o nodo que representa a raiz da árvore.
 * Parâmetro: chave - chave que será inserida.
 * Retorno: a nova raiz da árvore.
 */
Nodo *inserirChave(Nodo *raiz, int chave);

/*
 * Função para buscar uma chave na árvore.
 * Parâmetro: raiz - ponteiro para o nodo que representa a raiz da árvore.
 * Parâmetro: chave - chave de busca.
 * Retorno: o nodo associado a chave de busca. O valor NULL será retornado se a chave não estiver na árvore.
 */
Nodo *buscarChave(Nodo *raiz, int chave);

/*
 * Função para saber se há um nodo na árvore.
 * Parâmetro: raiz - ponteiro para o nodo que representa a raiz da árvore.
 * Parâmetro: chave - chave de busca.
 * Retorno: true se existir a chave na árvore, false caso não exista.
 */
bool existeChave(Nodo *raiz, int chave);
/*
 * Função para remover uma chave da árvore.
 * Parâmetro: raiz - ponteiro para o nodo que representa a raiz da árvore.
 * Parâmetro: chave - chave que será removida.
 * Retorno: a raiz atualizada da árvore após a remoção. O valor NULL é retornado se a chave não estiver na árvore.
 */
Nodo *removerChave(Nodo *raiz, int chave);

/*
 * Função para exibir a árvore em pré-ordem (exibição: raiz, esquerda, direita).
 * Parâmetro: raiz - ponteiro para o nodo que representa a raiz da árvore.
 */
void exibirPreOrdem(Nodo *raiz);

/*
 * Função para exibir a árvore em ordem (exibição: esquerda, raiz, direita).
 * Parâmetro: raiz - ponteiro para o nodo que representa a raiz da árvore.
 */
void exibirEmOrdem(Nodo *raiz);

/*
 * Função para exibir a árvore em pós-ordem (esquerda, direita, raiz).
 * Parâmetro: raiz - ponteiro para o nodo que representa a raiz da árvore.
 */
void exibirPosOrdem(Nodo *raiz);

/*
 * Função para exibir algumas informações sobre os nodos na árvore (por exemplo: altura, nível e grau).
 * Parâmetro: raiz - ponteiro para o nodo que representa a raiz da árvore.
 */
void exibirInfNodos(Nodo *raiz);

/*
 * Função para desalocar a árvore passada por parâmetro da memória.
 * Parâmetro: raiz - ponteiro para o nodo que representa a raiz da árvore.
 */
void destruirAVL(Nodo *raiz);

#endif