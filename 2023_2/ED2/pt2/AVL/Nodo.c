#include <stdlib.h>
#include "Nodo.h"

Nodo* criarNodo(int chave){
    Nodo* nodo = (Nodo*) malloc(sizeof(Nodo));
    nodo->chave = chave;
    nodo->altDireita = 0;
    nodo->altEsquerda = 0;
    nodo->direita = NULL;
    nodo->esquerda = NULL;
    return nodo;
}

int calcAltura(Nodo* nodo){
    if (nodo == NULL){
        return -1;
    }

    nodo->altDireita = calcAltura(nodo->direita)+1;
    nodo->altEsquerda = calcAltura(nodo->esquerda)+1;
    return 0;

}

int calcGrau(Nodo* nodo){
    if (nodo == NULL){
        return -1;
    }
    else {
        int grau = 0;
        
        if (nodo->direita != NULL){
            grau++;
        }
        if (nodo->esquerda != NULL){
            grau++;
        }
        return grau;
    }
}

void destruirNodo(Nodo* nodo){
    free(nodo);
}