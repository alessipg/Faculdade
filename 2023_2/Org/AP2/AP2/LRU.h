#ifndef LRU_H
#define LRU_H

typedef struct LinhaCacheLRU
{
    int tag;
    // 9 posi��es para o caractere '\0'
    char dados[4][9];
    // para fins de implementa��o, as posi��es do cache ser�o em ordem crescente, diferente do mostrado em slide
    struct LinhaCacheLRU *prox;
} LinhaCacheLRU;
typedef struct CacheLRU
{
    LinhaCacheLRU *topo;
    LinhaCacheLRU *base;
} CacheLRU;

void liberarCacheLRU(CacheLRU *cache, int tam);
void carregarCacheLRU(int *instrucao, CacheLRU *cache, char (*memPrincipal)[9]);
bool procurarCacheLRU(int *instrucao, CacheLRU *cache);
int *processarInstrucaoLRU(const char *instrucao);
LinhaCacheLRU *alocarLinhaLRU();
CacheLRU *inicializaCacheLRU(int tam);
int menuLRU();
#endif