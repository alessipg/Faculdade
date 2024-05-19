#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "HashFixo.h"

Tabela *criarTabela()
{
    Tabela *tabela = malloc(sizeof(Tabela));
    if (tabela == NULL)
    {
        return NULL;
    }
    tabela->nodo = malloc(sizeof(Nodo *) * 100);
    tabela->qtdChaves = 0;
    tabela->comparacoes = 0;

    // Aloca e inicializa os ponteiros para Hash
    for (int i = 0; i < 100; i++)
    {
        tabela->nodo[i] = NULL;
    }

    return tabela;
}

int hash(int tamanho, int chave)
{
    return chave % tamanho;
}

bool buscarChave(Tabela *tabela, int chave)
{
    int indice = hash(100, chave);
    Nodo *aux = tabela->nodo[indice];

    while (aux != NULL)
    {
        tabela->comparacoes++;
        if (aux->chave == chave)
        {
            return true;
        }
        aux = aux->prox;
    }
    //aqui ocorrerá uma iteração para:
    //1) caso a chave não exista, colidirá com um nodo nulo e portanto terá feito uma comparação
    //2) caso aux encontre nulo e portanto sairá do loop, mesmo tendo feito uma comparação
    tabela->comparacoes++;
    free(aux);
    return false;

}

void inserirTabela(Tabela *tabela, int chave)
{
    Nodo *novo = malloc(sizeof(Nodo));
    if(novo == NULL){
        return;
    }
    novo->chave = chave;
    novo->prox = NULL;

    int indice = hash(100, chave);
    if (tabela->nodo[indice] == NULL) {
    novo->qtdColisao = 0;
    tabela->nodo[indice] = novo;
} else {
    novo->prox = tabela->nodo[indice];
    tabela->nodo[indice] = novo;
    tabela->nodo[indice]->qtdColisao++;  // Incrementa apenas em caso de colisão
}

    tabela->qtdChaves++; // Aumenta a contagem de chaves na tabela
}

void destruirTabela(Tabela *tabela){
    for (int i = 0; i < 100; i++)
    {          
        destruirNodos(tabela->nodo[i]);
    }
    free(tabela->nodo);
    free(tabela);
}

void destruirNodos(Nodo *nodo){
    if(nodo == NULL){
        return;
    }
    if(nodo->prox == NULL){
        free(nodo);
    }else
    {
        destruirNodos(nodo->prox);
    }
}
void lerArquivos(const char *nomeArquivo){
    Tabela *tabela = criarTabela();
    time_t c1, c2;
    bool flag = true;
    FILE *in = fopen(nomeArquivo, "r");
    char operador;
    int chave;

    if (in == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return;
    }

    while (fscanf(in, " %c %d", &operador, &chave) == 2)
    {
        if (operador == 'i')
        {
            inserirTabela(tabela, chave);
        }
        else if (operador == 'b')
        {
            //condição para checar quando ocorre a primeira busca e inicializa o contador
            if(flag){
                c1 = clock();
                flag = false;
            }
            buscarChave(tabela, chave);
        }
        else
        {
            printf("Erro: operacao invalida");
        }
    }
    c2 = clock();
    printf("Tempo de busca em segundos: %lf\n",((c2-c1))/(double)CLOCKS_PER_SEC);
    fclose(in);
    printf("Comparacoes: %d\n", tabela->comparacoes);
    
    destruirTabela(tabela);
}