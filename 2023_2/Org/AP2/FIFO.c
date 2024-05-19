#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FIFO.h"


void liberarCacheFIFO(LinhaCacheFIFO *cache, int tam)
{
    LinhaCacheFIFO *temp = cache->prox;
    for (int i = 0; i < tam; i++)
    {
        LinhaCacheFIFO *proxTemp = temp->prox;
        free(temp);
        temp = proxTemp;
    }
    free(cache);
}


void carregarCacheFIFO(int *instrucao, CacheFIFO *cache, char (*memPrincipal)[9])
{
    printf("Dado nao encontrado, carregando bloco %d em cache.\n", instrucao[0]);
    LinhaCacheFIFO *aux = cache->cabeca->prox;
    while (aux->prox != cache->cabeca->prox)
    {
        if (aux->tag == -1)
        {
            aux->tag = instrucao[0];
            for (int i = 0; i < 4; i++)
            {
                strcpy(aux->dados[i], memPrincipal[(instrucao[0] * 4) + i]);
            }
            return;
        }
        aux = aux->prox;
    }

    // Se chegou aqui, significa que a cache está cheia
    // Move a cabeça da lista circular uma posição para frente
    cache->cabeca = cache->cabeca->prox;
    // Atualiza o bloco na nova posição da cabeça
    aux->tag = instrucao[0];
    for (int i = 0; i < 4; i++)
    {
        strcpy(aux->dados[i], memPrincipal[(instrucao[0] * 4) + i]);
    }
}

bool procurarCacheFIFO(int *instrucao, CacheFIFO *cache)
{
    LinhaCacheFIFO *aux = cache->cabeca->prox;
    while (aux->prox != cache->cabeca->prox)
    {

        if (instrucao[0] == aux->tag)
        {
            printf("Localizado o dado %s em cache.\n", aux->dados[instrucao[1]]);
            return true;
        }
        aux = aux->prox;
    }
    return false;
}

int *processarInstrucaoFIFO(const char *instrucao)
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
LinhaCacheFIFO *alocarLinhaFIFO()
{
    LinhaCacheFIFO *cache = malloc(sizeof(LinhaCacheFIFO));
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
CacheFIFO *inicializaCacheFIFO(int tam)
{
    if (tam <= 0)
        return NULL;

    CacheFIFO *cache = malloc(sizeof(CacheFIFO));
    if (cache == NULL)
        return NULL;

    // Inicializa a cache com a primeira linha
    cache->cabeca = alocarLinhaFIFO();
    if (cache->cabeca == NULL)
        return NULL;
    // Adiciona as linhas restantes na cache
    LinhaCacheFIFO *atual = cache->cabeca;
    for (int i = 1; i < tam; i++)
    {
        atual->prox = alocarLinhaFIFO();
        if (atual->prox == NULL)
        {
            // Se falhar ao alocar, libera as linhas alocadas até agora
            while (cache->cabeca != NULL)
            {
                LinhaCacheFIFO *temp = cache->cabeca;
                cache->cabeca = cache->cabeca->prox;
                free(temp);
            }
            free(cache);
            return NULL;
        }
        atual = atual->prox;
    }
    atual->prox = cache->cabeca; // Torna a lista circular
    cache->l0 = cache->cabeca->prox;

    return cache;
}

int menuFIFO()
{
    int cacheMiss = 0;
    int cacheHit = 0;
    CacheFIFO *cache = inicializaCacheFIFO(4);
    char memPrincipal[256][9];
    char(*instrucoes)[9];
    int *instrucaoAtual;
    LinhaCacheFIFO *aux = cache->cabeca;
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
    } while (aux != cache->cabeca);

    FILE *memoria;
    memoria = fopen("memPrincipal.txt", "r");

    if (memoria == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Ler as palavras do arquivo e armazenar no vetor
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

    // Percorre o arquivo para contabilizar a quantidade de instrucoes
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
    fclose(instrucao);

    int prova = 0;
    for (int i = 0; i < contadorInstrucoes; i++)
    {
        instrucaoAtual = processarInstrucaoFIFO(instrucoes[i]);
        if (procurarCacheFIFO(instrucaoAtual, cache))
        {
            cacheHit++;
        }
        else
        {
            carregarCacheFIFO(instrucaoAtual, cache, memPrincipal);
            cacheMiss++;
        }
        LinhaCacheFIFO *aux = cache->l0;
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
        } while (aux != cache->l0);
        printf("Cache Miss = %d || Cache Hit = %d\n", cacheMiss, cacheHit);
    }
    free(instrucaoAtual);
    liberarCacheFIFO(cache->cabeca, 4);
    free(cache);
    free(instrucoes);
    return 0;
}
