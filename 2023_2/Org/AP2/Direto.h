#ifndef DIRETO_H
#define DIRETO_H
#include <stdbool.h>

typedef struct LinhaCacheDireto
{
    int tag;
    // 9 posi��es para o caractere '\0'
    char dados[4][9];
    // para fins de implementa��o, as posi��es do cache ser�o em ordem crescente, diferente do mostrado em slide
} LinhaCacheDireto;

int mapeamentoDireto(int tag);
void liberarCacheDireto(LinhaCacheDireto **cache, int tam);
void carregarCacheDireto(int *instrucao, int bloco, LinhaCacheDireto **cache, char (*memPrincipal)[9]);
bool procurarCacheDireto(int *instrucao, int bloco, LinhaCacheDireto **cache);
int *processarInstrucaoDireto(const char *instrucao);
LinhaCacheDireto **inicializaCacheDireto(int tam);
int menuDireto();

#endif