#include <stdlib.h>
#include "Nodo.h"

Nodo* criarNodo(int chave){
    Nodo* nodo = (Nodo*) malloc(sizeof(Nodo));
    nodo->chave = chave;
    nodo->pai = NULL;
    nodo->direita = NULL;
    nodo->esquerda = NULL;
    return nodo;
}

int calcNivel(Nodo* nodo){
    if (nodo == NULL){
        return -1;
    }
    return calcNivel(nodo->pai) + 1;
}

int calcAltura(Nodo* nodo){
    if (nodo == NULL){
        return -1;
    }

    int alturaDireita = calcAltura(nodo->direita);
    int alturaEsquerda = calcAltura(nodo->esquerda);

    if (alturaDireita > alturaEsquerda) {
        return alturaDireita + 1;
    }
    return alturaEsquerda + 1;
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
    //optei por inserir esta linha para evitar leitura ilegal
    nodo = NULL;
}