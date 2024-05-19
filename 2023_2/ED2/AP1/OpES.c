#include <stdio.h>
#include "OpES.h"

int id = 0;     // Identificador �nico do nodo. Mesmo que dois nodos tenham a mesma chave, seus identificadores s�o exclusivos.

/*
 * FUN��O PRIVADA
 * 
 * Fun��o para escrever o arquivo.dot a partir da topologia da �rvore.
 * Par�metro: file - ponteiro para o arquivo em disco usado para armazenar a �rvore.
 * Par�metro: raiz - ponteiro para o nodo que representa a raiz da �rvore.
 * Retorno: identificador do filho da esquerda ou da direita.
*/
int escreverDot(FILE *file, Nodo* raiz) {    
    if (raiz == NULL){
        return id;
    }
    
    int nodoId = ++id;
    fprintf(file, "\t%d [label=\"%d\"];\n",nodoId, raiz->chave);

    int esqId = escreverDot(file, raiz->esquerda);
    int dirId = escreverDot(file, raiz->direita);
    
    if (nodoId != esqId){
        fprintf(file, "\t%d -> %d;\n", nodoId, esqId);
    }
    
    if (nodoId != dirId){
        fprintf(file, "\t%d -> %d;\n", nodoId, dirId);
    }

    return nodoId;
}

void gerarDotFile(Nodo* raiz){
    FILE *file = fopen("arvore.dot", "w");
    
    if (file != NULL){
        fprintf(file, "digraph arvoreBB{\n");
        escreverDot(file, raiz);
        fprintf(file, "}\n");
        fclose(file);
    }
    else{   
        printf("erro ao criar o arquivo dot\n");
    }
}