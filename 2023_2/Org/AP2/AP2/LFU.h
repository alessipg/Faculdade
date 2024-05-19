#ifndef LFU_H
#define LFU_H


typedef struct LinhaCacheLFU
{
    int tag;
    int contador;

    // 9 posi��es para o caractere '\0'
    char dados[4][9];
    // para fins de implementa��o, as posi��es do cache ser�o em ordem crescente, diferente do mostrado em slide
    struct LinhaCacheLFU *prox;
} LinhaCacheLFU;
typedef struct CacheLFU
{
    LinhaCacheLFU *inicio;
} CacheLFU;

void liberarCacheLFU(CacheLFU *cache, int tam);
void carregarCacheLFU(int *instrucao, CacheLFU *cache, char (*memPrincipal)[9]);
bool procurarCacheLFU(int *instrucao, CacheLFU *cache);
int *processarInstrucaoLFU(const char *instrucao);
LinhaCacheLFU *alocarLinhaLFU();
CacheLFU *inicializaCacheLFU(int tam);
int menuLFU();
#endif