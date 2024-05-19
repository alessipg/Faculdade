#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LRU.h"

void liberarCacheLRU(CacheLRU *cache, int tam)
{
    LinhaCacheLRU *temp = cache->topo;
    for (int i = 0; i < tam; i++)
    {
        LinhaCacheLRU *proxTemp = temp->prox;
        free(temp);
        temp = proxTemp;
    }
    free(cache);
}


void carregarCacheLRU(int *instrucao, CacheLRU *cache, char (*memPrincipal)[9])
{
    printf("Dado nao encontrado, carregando bloco %d em cache.\n", instrucao[0]);
    LinhaCacheLRU *aux = cache->topo;
    LinhaCacheLRU *ant = cache->topo;
    while (aux != NULL)
    {
        if (aux->tag == -1)
        {
            aux->tag = instrucao[0];
            for (int i = 0; i < 4; i++)
            {
                strcpy(aux->dados[i], memPrincipal[(instrucao[0] * 4) + i]);
            }
            if (aux != cache->topo)
            {
                ant->prox = aux->prox;
                aux->prox = cache->topo;
                cache->topo = aux;
            }
            return;
        }
        // condição para o caso onde o cache está cheio, finaliza o laço com aux=ultima linha e ant = penultima linha
        if (aux->prox == NULL)
        {
            break;
        }
        ant = aux;
        aux = aux->prox;
    }

    // Se chegou aqui, significa que a cache está cheia
    aux->prox = cache->topo;
    cache->topo = aux;
    cache->base = ant;
    ant->prox = NULL;
    aux->tag = instrucao[0];
    for (int i = 0; i < 4; i++)
    {
        strcpy(aux->dados[i], memPrincipal[(instrucao[0] * 4) + i]);
    }
}

bool procurarCacheLRU(int *instrucao, CacheLRU *cache)
{
    LinhaCacheLRU *aux = cache->topo;
    LinhaCacheLRU *ant = cache->topo;
    while (aux != NULL && aux->tag != -1)
    {
        if (instrucao[0] == aux->tag)
        {
            printf("Localizado o dado %s em cache.\n", aux->dados[instrucao[1]]);
            // verifica se a linha atual já está no topo da pilha, logo não há a necessidade de realocação de posição
            if (aux != cache->topo)
            {
                ant->prox = aux->prox;
                aux->prox = cache->topo;
                cache->topo = aux;
            }
            return true;
        }
        ant = aux;
        aux = aux->prox;
    }
    return false;
}

int *processarInstrucaoLRU(const char *instrucao)
{
    char tagString[5];
    char palavraString[3];

    strncpy(tagString, instrucao, 6);
    strncpy(palavraString, instrucao + 6, 2);

    int tag = strtol(tagString, NULL, 2);
    int palavra = strtol(palavraString, NULL, 2);
    int *instrucaoProcessada = malloc(sizeof(int) * 2);
    if (instrucaoProcessada == NULL)
        return NULL;
    instrucaoProcessada[0] = tag;
    instrucaoProcessada[1] = palavra;
    return instrucaoProcessada;
}
LinhaCacheLRU *alocarLinhaLRU()
{
    LinhaCacheLRU *cache = malloc(sizeof(LinhaCacheLRU));
    if (cache == NULL)
        return NULL;
    cache->prox = cache;
    cache->tag = -1;
    for (int j = 0; j < 4; j++)
    {
        for (int k = 0; k < 8; k++)
        {
            cache->dados[j][k] = '-';
        }
        cache->dados[j][8] = '\0';
    }
    return cache;
}
CacheLRU *inicializaCacheLRU(int tam)
{
    if (tam <= 0)
        return NULL;

    CacheLRU *cache = malloc(sizeof(CacheLRU));
    if (cache == NULL)
        return NULL;

    // Inicializa a cache com a primeira linha
    cache->topo = alocarLinhaLRU();
    if (cache->topo == NULL)
    {
        free(cache);
        return NULL;
    }

    LinhaCacheLRU *atual = cache->topo;
    // Adiciona as linhas restantes na cache
    for (int i = 1; i < tam; i++)
    {
        atual->prox = alocarLinhaLRU();
        if (atual->prox == NULL)
        {
            // Se falhar ao alocar, libera as linhas alocadas até agora
            while (cache->topo != NULL)
            {
                LinhaCacheLRU *temp = cache->topo;
                cache->topo = cache->topo->prox;
                free(temp);
            }
            free(cache);
            return NULL;
        }
        atual = atual->prox;
    }
    cache->base = atual;
    atual->prox = NULL;

    return cache;
}


int menuLRU()
{
    int cacheMiss = 0;
    int cacheHit = 0;
    CacheLRU *cache = inicializaCacheLRU(4);
    char memPrincipal[256][9];
    char(*instrucoes)[9];
    int *instrucaoAtual;
    LinhaCacheLRU *aux = cache->topo;
    int i = 0;
    do
    {
        printf("======Cache L%d======\n", i);
        printf("Tag = %d\n", aux->tag);
        for (int j = 0; j < 4; j++)
        {
            printf("P%d = %s\n", j, aux->dados[j]);
        }
        aux = aux->prox;
        i++;
    } while (aux != NULL);

    FILE *memoria;
    memoria = fopen("memPrincipal.txt", "r");

    if (memoria == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    for (int i = 0; i < 256; i++)
    {
        if (fgets(memPrincipal[i], 9, memoria) == NULL)
        {
            break;
        }
        memPrincipal[i][strcspn(memPrincipal[i], "\n")] = '\0';

        // Consumir o caractere de nova linha
        fgetc(memoria);
    }
    fclose(memoria);
    FILE *instrucao;
    instrucao = fopen("instrucoes.txt", "r");

    if (instrucao == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    int contadorInstrucoes = 1;
    char caractere;

    // Percorre o arquivo caractere por caractere
    while ((caractere = fgetc(instrucao)) != EOF)
    {
        // Se o caractere atual for uma quebra de linha, incrementa o contador de linhas
        if (caractere == '\n')
        {
            contadorInstrucoes++;
        }
    }

    // Aloca a quantidade necessária para armazenar as instruções
    instrucoes = malloc(sizeof(char[9]) * contadorInstrucoes);
    if (instrucoes == NULL)
    {
        return -1;
    }

    fseek(instrucao, 0, SEEK_SET);

    for (int i = 0; i < contadorInstrucoes; i++)
    {
        if (fgets(instrucoes[i], 9, instrucao) == NULL)
        {
            break;
        }
        instrucoes[i][strcspn(instrucoes[i], "\n")] = '\0';

        // Consumir o caractere de nova linha
        fgetc(instrucao);
    }

    fclose(instrucao);
    for (int i = 0; i < contadorInstrucoes; i++)
    {
        instrucaoAtual = processarInstrucaoLRU(instrucoes[i]);
        if (procurarCacheLRU(instrucaoAtual, cache))
        {
            cacheHit++;
        }
        else
        {

            carregarCacheLRU(instrucaoAtual, cache, memPrincipal);
            cacheMiss++;
        }
        LinhaCacheLRU *aux = cache->topo;
        int i = 0;
        do
        {
            printf("======Cache L%d======\n", i);
            printf("Tag = %d\n", aux->tag);
            for (int j = 0; j < 4; j++)
            {
                printf("P%d = %s\n", j, aux->dados[j]);
            }
            aux = aux->prox;
            i++;
        } while (aux != NULL);

        printf("Cache Miss = %d || Cache Hit = %d\n", cacheMiss, cacheHit);
    }
    free(instrucoes);
    free(instrucaoAtual);
    liberarCacheLRU(cache, 4);
    
    return 0;
}
