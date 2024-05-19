#ifndef OPERACAO_ENTRADA_SAIDA
#define OPERACAO_ENTRADA_SAIDA

#include "Nodo.h"

/*
 * Fun��o para converter uma �rvore bin�ria em um arquivo .dot.
 * Um arquivo .dot � capaz de descrever a topologia de �rvores e grafos.
 * Para mais informa��es acesse: https://www.graphviz.org/
 
 * Par�metro: raiz - ponteiro para o nodo que representa a raiz da �rvore.
*/
void gerarDotFile(Nodo* raiz);

#endif