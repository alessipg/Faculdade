#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "HashDinamico.h"

Tabela *criarTabela(int tamanho)
{
    Tabela *tabela = malloc(sizeof(Tabela));
    if (tabela == NULL)
    {
        return NULL;
    }
    tabela->tamanho = tamanho;
    tabela->hash = malloc(sizeof(Hash *) * tamanho);
    tabela->qtdChaves = 0;
    tabela->comparacoes = 0;

    // Aloca e inicializa os ponteiros para Hash
    for (int i = 0; i < tamanho; i++)
    {
        tabela->hash[i] = malloc(sizeof(Hash));
        if (tabela->hash[i] == NULL)
        {
            // Tratamento de erro, libera a memória alocada anteriormente
            for (int j = 0; j < i; j++)
            {
                free(tabela->hash[j]);
            }
            free(tabela->hash);
            free(tabela);
            return NULL;
        }
        tabela->hash[i]->status = 'L';
    }

    return tabela;
}

int hash(int tamanho, int chave)
{
    return chave % tamanho;
}

bool buscarChave(Tabela *tabela, int chave)
{
    int indice = hash(tabela->tamanho, chave);
    int i = 0;
    do
    {
        tabela->comparacoes++;
        int pos = hash(tabela->tamanho, indice + i); // Calcula a próxima posição usando sondagem linear
        if (tabela->hash[pos]->status == 'O')
        {
            if (tabela->hash[pos]->chave == chave)
            {
                return true;
            }
        }
        else
            break;//se status != O, significa que a chave não existe
        i++;
    } while (i < tabela->tamanho);
    return false;
}

void inserirTabela(Tabela *tabela, int chave)
{
    int indice = hash(tabela->tamanho, chave);
    int i = 0;
    float carga;

    carga = (float)(tabela->qtdChaves + 1) / tabela->tamanho; // Calcula a nova carga após a inserção
    // Achei melhor colocar o comparativo da carga antes afim de poupar uma inserção que não será utilizada.
    if (carga > 0.7)
    {
        redimensionar(&tabela);
    }

    do
    {
        int pos = hash(tabela->tamanho, indice + i); // Calcula a próxima posição usando sondagem linear
        if (tabela->hash[pos]->status == 'L' || tabela->hash[pos]->status == 'R')
        {
            tabela->hash[pos]->chave = chave;
            tabela->qtdChaves++;
            tabela->hash[pos]->status = 'O';
            return;
        }
        i++;
    } while (i < tabela->tamanho);
}

void redimensionar(Tabela **tabela)
{
    Tabela *nova = criarTabela((*tabela)->tamanho * 2);
    for (int i = 0; i < (*tabela)->tamanho; i++)
    {
        if ((*tabela)->hash[i]->status == 'O')
        {
            inserirTabela(nova, (*tabela)->hash[i]->chave);
        }
    }
    free((*tabela)->hash);
    (*tabela)->hash = nova->hash;
    (*tabela)->tamanho = nova->tamanho;
    free(nova);
}

void destruirTabela(Tabela *tabela){
    for (int i = 0; i < tabela->tamanho; i++)
    {
        free(tabela->hash[i]);
    }
    free(tabela->hash);
    free(tabela);
}

void lerArquivos(const char *nomeArquivo){
    Tabela *tabela = criarTabela(100); // Inicializa com tamanho 1
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