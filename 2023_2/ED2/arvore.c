#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int chave;
    struct No *pai;
    struct No *direita;
    struct No *esquerda;
} Nodo;

Nodo *criarNodo(int chave)
{
    Nodo *nodo = malloc(sizeof(Nodo));
    nodo->chave = chave;
    nodo->direita = NULL;
    nodo->esquerda = NULL;
    nodo->pai = NULL;
    return nodo;
}

void emOrdem(Nodo *raiz)
{
    if (raiz != NULL)
    {
        emOrdem(raiz->esquerda);
        printf("%d 0x%p\n", raiz->chave, raiz);
        emOrdem(raiz->direita);
    }
}

Nodo *insereNodo(Nodo *nodo, int k, Nodo *pai)
{
    if (!nodo)
    {
        nodo = malloc(sizeof(Nodo));
        nodo->chave = k;
        nodo->pai = pai;
        nodo->direita = NULL;
        nodo->esquerda = NULL;
    }
    else if (k < nodo->chave)
    {
        nodo->esquerda = insereNodo(nodo->esquerda, k, nodo);
    }
    else
    {
        nodo->direita = insereNodo(nodo->direita, k, nodo);
    }
    return nodo;
}

Nodo *removeNodo(Nodo *nodo, int k)
{
    
}
int main()
{
    Nodo *nodo = criarNodo(50);
    nodo = insereNodo(nodo, 25, NULL);
    nodo = insereNodo(nodo, 75, NULL);
    nodo = insereNodo(nodo, 35, NULL);
    emOrdem(nodo);
    nodo = removeNodo(nodo, 35);
    emOrdem(nodo);
    printf("\n%d %d", nodo->direita->chave,nodo->direita->pai->chave);
}