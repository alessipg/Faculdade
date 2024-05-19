#include <stdio.h>
#include "AVL.h"
#include "OpES.h"

int main(){

    Nodo* raiz = criarAVL();

    // Inserindo nodos..

    raiz = inserirChave(raiz, 25);
    raiz = inserirChave(raiz, 18);
    raiz = inserirChave(raiz, 5);
    // raiz = inserirChave(raiz, 22);
    // raiz = inserirChave(raiz, 40);
    // raiz = inserirChave(raiz, 28);
    // raiz = inserirChave(raiz, 45);

    // Percorrendo os nodos da �rvore ...

    printf("�rvore em pr�-ordem: ");
    exibirPreOrdem(raiz);
    printf("\n");

    printf("�rvore BST em ordem: ");
    exibirEmOrdem(raiz);
    printf("\n");

    printf("�rvore BST em p�s-ordem: ");
    exibirPosOrdem(raiz);
    printf("\n");

    // Exibindo inform��es gerais dos nodos ...

    printf("\n");
    exibirInfNodos(raiz);

    // Gerando o arquivo .dot usado pelo visualizador Graphviz ...

    gerarDotFile(raiz);
    printf("\nO arquivo \'arvore.dot\' foi gerado na raiz do diret�rio do projeto\n");

    // Destruindo a �rvore ...
    destruirAVL(raiz);

    return 0;
}