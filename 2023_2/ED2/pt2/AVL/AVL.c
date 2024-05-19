#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

Nodo *criarAVL()
{
    return NULL;
}
int altura(Nodo* nodo) {
    if (nodo == NULL) {
        return 0;
    }
    return 1 + maximo(nodo->altEsquerda, nodo->altDireita);
}

int maximo(int a, int b) {
    return (a > b) ? a : b;
}

Nodo *inserirChave(Nodo *raiz, int chave)
{
    if (raiz == NULL)
    {
        return criarNodo(chave);
    }

    if (chave < raiz->chave)
    {
        raiz->esquerda = inserirChave(raiz->esquerda, chave);
    }
    else
    {
        raiz->direita = inserirChave(raiz->direita, chave);
    }

    raiz->altEsquerda = altura(raiz->esquerda);
    raiz->altDireita = altura(raiz->direita);
    
    return raiz;
}

Nodo *buscarChave(Nodo *raiz, int chave)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    if (chave == raiz->chave)
    {
        return raiz;
    }
    else if (chave < raiz->chave)
    {
        return buscarChave(raiz->esquerda, chave);
    }
    else
    {
        return buscarChave(raiz->direita, chave);
    }
}

/*
 * FUNÇÃO PRIVADA
 *
 * Função para buscar o sucessor de um nodo
 * Parâmetro: raiz - ponteiro para o nodo que representa a raiz da árvore
 * Parâmetro: nodo - ponteiro para o nodo usado como referência para busca pelo sucessor.
 * Retorno: o sucessor do nodo informado por parâmetro.
 */
Nodo *encontrarSucessor(Nodo *raiz, Nodo *nodo)
{

    // CASO 1: o sucessor está na subárvore da direita do nodo

    if (nodo->direita != NULL)
    {
        nodo = nodo->direita;

        while (nodo->esquerda != NULL)
        {
            nodo = nodo->esquerda;
        }
        return nodo;
    }

    // CASO 2: o nodo não possui uma subárvore à direita

    else
    {
        Nodo *sucessor = NULL;
        while (raiz != NULL)
        {
            if (nodo->chave < raiz->chave)
            {
                sucessor = raiz;
                raiz = raiz->esquerda;
            }
            else if (nodo->chave > raiz->chave)
            {
                raiz = raiz->direita;
            }
            else
            {
                break;
            }
        }
        return sucessor;
    }
}

void exibirPreOrdem(Nodo *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->chave);
        exibirPreOrdem(raiz->esquerda);
        exibirPreOrdem(raiz->direita);
    }
}

void exibirEmOrdem(Nodo *raiz)
{
    if (raiz != NULL)
    {
        exibirEmOrdem(raiz->esquerda);
        printf("Chave %d \n", raiz->chave);
        printf("Esquerda %d \n", raiz->altEsquerda);
        printf("Direita %d \n", raiz->altDireita);
        exibirEmOrdem(raiz->direita);
    }
}

void exibirPosOrdem(Nodo *raiz)
{
    if (raiz != NULL)
    {
        exibirPosOrdem(raiz->esquerda);
        exibirPosOrdem(raiz->direita);
        printf("%d ", raiz->chave);
    }
}

void exibirInfNodos(Nodo *raiz)
{
    if (raiz != NULL)
    {
        int altura = calcAltura(raiz);
        int grau = calcGrau(raiz);

        printf("chave: %d,\taltura: %d,\tgrau: %d\n", raiz->chave, altura, grau);

        exibirInfNodos(raiz->esquerda);
        exibirInfNodos(raiz->direita);
    }
}

void destruirAVL(Nodo *raiz)
{
    if (raiz != NULL)
    {
        destruirAVL(raiz->esquerda);
        destruirAVL(raiz->direita);
        destruirNodo(raiz);
    }
}