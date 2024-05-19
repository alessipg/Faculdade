#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBB.h"

Nodo *criarAVL()
{
    return NULL;
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
        raiz->esquerda->pai = raiz;
    }
    else
    {
        raiz->direita = inserirChave(raiz->direita, chave);
        raiz->direita->pai = raiz;
    }
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

bool existeChave(Nodo *raiz, int chave)
{
    if (raiz == NULL)
    {
        return false;
    }

    if (chave == raiz->chave)
    {
        return true;
    }
    else if (chave < raiz->chave)
    {
        return existeChave(raiz->esquerda, chave);
    }
    else
    {
        return existeChave(raiz->direita, chave);
    }
}
/*
 * FUN��O PRIVADA
 *
 * Fun��o para buscar o sucessor de um nodo
 * Par�metro: raiz - ponteiro para o nodo que representa a raiz da �rvore
 * Par�metro: nodo - ponteiro para o nodo usado como refer�ncia para busca pelo sucessor.
 * Retorno: o sucessor do nodo informado por par�metro.
 */
Nodo *encontrarSucessor(Nodo *raiz, Nodo *nodo)
{

    // CASO 1: o sucessor est� na sub�rvore da direita do nodo

    if (nodo->direita != NULL)
    {
        nodo = nodo->direita;

        while (nodo->esquerda != NULL)
        {
            nodo = nodo->esquerda;
        }
        return nodo;
    }

    // CASO 2: o nodo n�o possui uma sub�rvore � direita

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

Nodo *removerChave(Nodo *raiz, int chave)
{
    // encontra o nodo desejado
    Nodo *nodo = buscarChave(raiz, chave);
    // se nodo == nulo, n�o est� na �rvore
    if (!nodo)
    {
        // se nao houver chave na arvore, retornar� nulo, como especificado no enunciado da AP1
        // por�m achei melhor destruir a �rvore antes para n�o haver vazamento de mem�ria
        destruirAVL(raiz);
        return NULL;
    }
    // auxiliar com endere�o do pai do nodo a ser removido
    Nodo *aux = nodo->pai;

    // verifica o tipo de nodo para a remo��o correta

    // Caso nodo com 2 filhos
    if (nodo->esquerda != NULL && nodo->direita != NULL)
    {

        // encontramos o substituto para a remo��o
        Nodo *sucessor = encontrarSucessor(raiz, nodo);
        // sub-caso: remo��o do nodo raiz com 2 filhos
        if (!aux)
        {
            // apontamos o antigo pai do sucessor para nulo
            if (sucessor->pai->direita != sucessor && sucessor->pai != raiz)
            {
                sucessor->pai->esquerda = NULL;
            }
            // raiz nao tem pai
            sucessor->pai = NULL;
            // apontamos para os devidos nodos
            sucessor->esquerda = raiz->esquerda;
            if (raiz->direita != sucessor)
            {
                sucessor->direita = raiz->direita;
            }
            sucessor->direita->pai = sucessor;
            sucessor->esquerda->pai = sucessor;
            aux = raiz;
            raiz = sucessor;
            free(aux);
            aux = NULL;
        }
        // nodo qualquer com 2 filhos
        else
        {
            // verificamos a qual lado o filho pertence
            if (aux->esquerda == nodo)
            {
                aux->esquerda = sucessor;
            }
            else
            {
                aux->direita = sucessor;
            }
            // apontamos o pai para nulo
            if (sucessor->pai->esquerda == sucessor)
            {
                sucessor->pai->esquerda = NULL;
            }
            // realizamos os endere�amento para os devidos nodos
            sucessor->pai = aux;
            sucessor->esquerda = nodo->esquerda;
            if (sucessor->esquerda != NULL)
            {
                sucessor->esquerda->pai = sucessor;
            }
            if (sucessor != nodo->direita)
            {
                sucessor->direita = nodo->direita;
            }
            if (sucessor->direita != NULL)
            {
                sucessor->direita->pai = sucessor;
            }
            free(nodo);
            nodo = NULL;
        }
    }
    // caso nodo com 1 filho
    else if (nodo->direita != NULL || nodo->esquerda != NULL)
    {
        // nodo raiz com 1 filho
        if (!aux)
        {
            if (nodo->direita != NULL)
            {
                raiz = nodo->direita;
            }
            else
            {
                raiz = nodo->esquerda;
            }
            raiz->pai = NULL;
        }
        // verifica em qual lado est� o nodo
        else if (aux->esquerda == nodo)
        {
            // verifica qual lado do nodo a ser removido possui filhos e remove-o
            if (aux->esquerda->esquerda != NULL)
            {
                aux->esquerda = nodo->esquerda;
            }
            else
            {
                aux->esquerda = nodo->direita;
            }
            // em ambos os casos, nodo n�o deve apontar mais para uma regi�o da mem�ria
            aux->esquerda->pai = aux;
            free(nodo);
            nodo = NULL;
        }
        else
        {
            // passos semelhantes, por�m percorrendo o lado direito do nodo pai do nodo removido
            if (aux->direita->esquerda != NULL)
            {
                aux->direita = nodo->esquerda;
            }
            else
            {
                aux->direita = nodo->direita;
            }
            aux->direita->pai = aux;
            free(nodo);
            nodo = NULL;
        }
    }
    // Caso nodo folha
    else
    {
        // um unico nodo na arvore;
        if (!aux)
        {
            return NULL;
        }
        // verifica se o nodo � filho da direita ou esquerda do nodo pai
        if (aux->esquerda == nodo)
        {
            free(nodo);
            aux->esquerda = NULL;
        }
        else
        {
            free(nodo);
            aux->direita = NULL;
        }
    }
    return raiz;
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
        printf("%d ", raiz->chave);
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
        int nivel = calcNivel(raiz);
        int grau = calcGrau(raiz);
        printf("chave: %d,\taltura: %d,\tnivel: %d,\tgrau: %d\n", raiz->chave, altura, nivel, grau);

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