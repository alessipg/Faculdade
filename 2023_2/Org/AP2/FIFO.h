#ifndef FIFO_H
#define FIFO_H

typedef struct LinhaCacheFIFO
{
    int tag;
    // 9 posi��es para o caractere '\0'
    char dados[4][9];
    // para fins de implementa��o, as posi��es do cache ser�o em ordem crescente, diferente do mostrado em slide
    struct LinhaCacheFIFO *prox;
} LinhaCacheFIFO;
typedef struct CacheFIFO
{
    LinhaCacheFIFO *cabeca;
    LinhaCacheFIFO *l0;
} CacheFIFO;


void liberarCacheFIFO(LinhaCacheFIFO *cache, int tam);
void carregarCacheFIFO(int *instrucao, CacheFIFO *cache, char (*memPrincipal)[9]);
bool procurarCacheFIFO(int *instrucao, CacheFIFO *cache);
int *processarInstrucaoFIFO(const char *instrucao);
LinhaCacheFIFO *alocarLinhaFIFO();
CacheFIFO *inicializaCacheFIFO(int tam);
int menuFIFO();

#endif