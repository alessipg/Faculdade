#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LFU.h"


void liberarCacheLFU(CacheLFU *cache, int tam)
{
    LinhaCacheLFU *temp = cache->inicio;
    for (int i = 0; i < tam; i++)
    {
        LinhaCacheLFU *proxTemp = temp->prox;
        free(temp);
        temp = proxTemp;
    }
    free(cache);
}

void carregarCacheLFU(int *instrucao, CacheLFU *cache, char (*memPrincipal)[9])
{
    printf("Dado nao encontrado, carregando bloco %d em cache.\n", instrucao[0]);
    LinhaCacheLFU *aux = cache->inicio;
    LinhaCacheLFU *menor = cache->inicio;
    // Localiza o menor contador
    int menorOcorrencia = aux->contador;
    while (aux != NULL)
    {
        if (aux->contador < menorOcorrencia)
        {
            menorOcorrencia = aux->contador;
        }
        aux = aux->prox;
    }
    aux = cache->inicio;
    while (aux != NULL)
    {
        if (aux->contador == menorOcorrencia)
        {
            aux->tag = instrucao[0];
            aux->contador = 1;
            for (int i = 0; i < 4; i++)
            {
                strcpy(aux->dados[i], memPrincipal[(instrucao[0] * 4) + i]);
            }

            return;
        }
        aux = aux->prox;
    }
}

bool procurarCacheLFU(int *instrucao, CacheLFU *cache)
{
    LinhaCacheLFU *aux = cache->inicio;
    while (aux != NULL && aux->tag != -1)
    {
        if (instrucao[0] == aux->tag)
        {
            printf("Localizado o dado %s em cache.\n", aux->dados[instrucao[1]]);
            aux->contador++;
            return true;
        }
        aux = aux->prox;
    }
    return false;
}

int *processarInstrucaoLFU(const char *instrucao)
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
LinhaCacheLFU *alocarLinhaLFU()
{
    LinhaCacheLFU *cache = malloc(sizeof(LinhaCacheLFU));
    if (cache == NULL)
        return NULL;
    cache->prox = cache;
    cache->tag = -1;
    cache->contador = 0;
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
CacheLFU *inicializaCacheLFU(int tam)
{
    if (tam <= 0)
        return NULL;

    CacheLFU *cache = malloc(sizeof(CacheLFU));
    if (cache == NULL)
        return NULL;

    // Inicializa a cache com a primeira linha
    cache->inicio = alocarLinhaLFU();
    if (cache->inicio == NULL)
    {
        free(cache);
        return NULL;
    }
    LinhaCacheLFU *atual = cache->inicio;
    // Adiciona as linhas restantes na cache
    for (int i = 1; i < tam; i++)
    {
        atual->prox = alocarLinhaLFU();
        if (atual->prox == NULL)
        {
            // Se falhar ao alocar, libera as linhas alocadas até agora
            while (cache->inicio != NULL)
            {
                LinhaCacheLFU *temp = cache->inicio;
                cache->inicio = cache->inicio->prox;
                free(temp);
            }
            free(cache);
            return NULL;
        }
        atual = atual->prox;
    }
    atual->prox = NULL;

    return cache;
}

int menuLFU()
{
    int cacheMiss = 0;
    int cacheHit = 0;
    CacheLFU *cache = inicializaCacheLFU(4);
    char memPrincipal[256][9];
    char(*instrucoes)[9];
    int *instrucaoAtual;
    LinhaCacheLFU *aux = cache->inicio;
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

    // fecha o arquivo
    fclose(instrucao);
    for (int i = 0; i < contadorInstrucoes; i++)
    {
        instrucaoAtual = processarInstrucaoLFU(instrucoes[i]);
        if (procurarCacheLFU(instrucaoAtual, cache))
        {
            cacheHit++;
        }
        else
        {

            carregarCacheLFU(instrucaoAtual, cache, memPrincipal);
            cacheMiss++;
        }
        LinhaCacheLFU *aux = cache->inicio;
        int i = 0;
        do
        {
            printf("======Cache L%d======\n", i);
            printf("Contador = %d\n", aux->contador);
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
    // Desalocar a memória alocada dinamicamente para cache
    free(instrucoes);
    free(instrucaoAtual);
    liberarCacheLFU(cache, 4);
    return 0;
}
