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

    // Percorrendo os nodos da árvore ...

    printf("Árvore em pré-ordem: ");
    exibirPreOrdem(raiz);
    printf("\n");

    printf("Árvore BST em ordem: ");
    exibirEmOrdem(raiz);
    printf("\n");

    printf("Árvore BST em pós-ordem: ");
    exibirPosOrdem(raiz);
    printf("\n");

    // Exibindo informções gerais dos nodos ...

    printf("\n");
    exibirInfNodos(raiz);

    // Gerando o arquivo .dot usado pelo visualizador Graphviz ...

    gerarDotFile(raiz);
    printf("\nO arquivo \'arvore.dot\' foi gerado na raiz do diretório do projeto\n");

    // Destruindo a árvore ...
    destruirAVL(raiz);

    return 0;
}