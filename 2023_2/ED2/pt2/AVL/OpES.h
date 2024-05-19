#ifndef OPERACAO_ENTRADA_SAIDA
#define OPERACAO_ENTRADA_SAIDA

#include "Nodo.h"

/*
 * Função para converter uma árvore binária em um arquivo .dot.
 * Um arquivo .dot é capaz de descrever a topologia de árvores e grafos.
 * Para mais informações acesse: https://www.graphviz.org/
 
 * Parâmetro: raiz - ponteiro para o nodo que representa a raiz da árvore.
*/
void gerarDotFile(Nodo* raiz);

#endif