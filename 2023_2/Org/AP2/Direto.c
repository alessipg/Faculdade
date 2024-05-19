#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Direto.h"
// Obs: o programa não funciona corretamente se o bloco instruções possuir uma linha em branco
// mesmo que no final do arquivo.

int mapeamentoDireto(int tag)
{
    return tag % 4;
}

void liberarCacheDireto(LinhaCacheDireto **cache, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        free(cache[i]);
    }
    free(cache);
}

void carregarCacheDireto(int *instrucao, int bloco, LinhaCacheDireto **cache, char (*memPrincipal)[9])
{
    int tag = mapeamentoDireto(bloco);
    cache[tag]->tag = instrucao[0];
    printf("Dado nao encontrado, carregando bloco %d em cache.\n", bloco);
    for (int i = 0; i < 4; i++)
    {
        strcpy(cache[tag]->dados[i], memPrincipal[(bloco * 4) + i]);
    }
}
bool procurarCacheDireto(int *instrucao, int bloco, LinhaCacheDireto **cache)
{
    int tag = mapeamentoDireto(bloco);
    if (instrucao[0] == cache[tag]->tag)
    {
        printf("Localizado o dado %s em cache.\n", cache[tag]->dados[instrucao[2]]);
        return true;
    }
    else
    {
        return false;
    }
}

int *processarInstrucaoDireto(const char *instrucao)
{
    char tagString[5];
    char linhaString[3];
    char palavraString[3];

    strncpy(tagString, instrucao, 4);
    strncpy(linhaString, instrucao + 4, 2);
    strncpy(palavraString, instrucao + 6, 2);

    int tag = strtol(tagString, NULL, 2);
    int linha = strtol(linhaString, NULL, 2);
    int palavra = strtol(palavraString, NULL, 2);
    int *instrucaoProcessada = malloc(sizeof(int) * 3);
    if (instrucaoProcessada == NULL)
        return NULL;
    instrucaoProcessada[0] = tag;
    instrucaoProcessada[1] = linha;
    instrucaoProcessada[2] = palavra;
    return instrucaoProcessada;
}
LinhaCacheDireto **inicializaCacheDireto(int tam)
{
    LinhaCacheDireto **cache = malloc(sizeof(LinhaCacheDireto *) * tam);
    if (cache == NULL)
        return NULL;

    for (int i = 0; i < tam; i++)
    {
        cache[i] = malloc(sizeof(LinhaCacheDireto));
        if (cache[i] == NULL)
        {
            // Tratar falha na alocação de memória, se necessário
            // Por exemplo, você pode liberar a memória alocada até agora e retornar NULL.
            for (int j = 0; j < i; j++)
                free(cache[j]);
            free(cache);
            return NULL;
        }

        cache[i]->tag = -1;
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                cache[i]->dados[j][k] = '-';
            }
            cache[i]->dados[j][8] = '\0';
        }
    }
    return cache;
}

int menuDireto()
{
    int cacheMiss = 0;
    int cacheHit = 0;
    LinhaCacheDireto **cache = inicializaCacheDireto(4);
    char memPrincipal[256][9];
    char(*instrucoes)[9];
    int *instrucaoAtual;
    char instrucaoBin[7];
    int bloco;
    for (int i = 0; i < 4; i++)
    {
        printf("======Cache L%d======\n", i);
        printf("Tag = %d\n", cache[i]->tag);
        for (int j = 0; j < 4; j++)
        {
            printf("P%d = %s\n", j, cache[i]->dados[j]);
        }
    }

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
            fprintf(stderr, "Erro ao ler do arquivo\n");
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
            fprintf(stderr, "Erro ao ler do arquivo\n");
            break;
        }
        instrucoes[i][strcspn(instrucoes[i], "\n")] = '\0';

        // Consumir o caractere de nova linha
        fgetc(instrucao);
    }

    fclose(instrucao);

    for (int i = 0; i < contadorInstrucoes; i++)
    {
        instrucaoAtual = processarInstrucaoDireto(instrucoes[i]);
        strncpy(instrucaoBin, instrucoes[i], 6);
        bloco = strtol(instrucaoBin, NULL, 2);
        if (procurarCacheDireto(instrucaoAtual, bloco, cache))
        {
            cacheHit++;
        }
        else
        {
            carregarCacheDireto(instrucaoAtual, bloco, cache, memPrincipal);
            cacheMiss++;
        }
        for (int i = 0; i < 4; i++)
        {
            printf("======Cache L%d======\n", i);
            printf("Tag = %d\n", cache[i]->tag);
            for (int j = 0; j < 4; j++)
            {
                printf("P%d = %s\n", j, cache[i]->dados[j]);
            }
        }
        printf("Cache Miss = %d || Cache Hit = %d\n", cacheMiss, cacheHit);
    }
    liberarCacheDireto(cache, 4);
    free(instrucoes);
    free(instrucaoAtual);
    return 0;
}
