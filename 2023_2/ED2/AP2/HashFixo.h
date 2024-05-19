#ifndef HASHFIXO_H
#define HASHFIXO_H
#include <stdbool.h>

typedef struct Nodo
{
    struct Nodo *prox;
    int chave;
    int qtdColisao;//apenas informativo de quantas chaves s�o mapeadas nesse hash
} Nodo;

typedef struct Tabela
{
    Nodo **nodo;
    int qtdChaves;
    int comparacoes;
} Tabela;

/*
 * Fun��o para criar uma tabela de 100 posi��es.
 * Retorno: endere�o da tabela criada.
*/
Tabela *criarTabela();
/*
 * Fun��o para mapear uma chave na tabela hash.
 * Par�metro: tamanho - quantidade de posi��es existentes na tabela.
 * Par�metro: chave - chave de busca a ser inserida.
 * Retorno: inteiro correspondente a posi��o mapeada da chave a ser inserida.
*/
int hash(int tamanho, int chave);
/*
 * Fun��o para verificar a exist�ncia de uma chave na tabela.
 * Par�metro: tabela - endere�o da tabela a ser utilizada.
 * Par�metro: chave - chave de busca desejada.
 * Retorno: true caso a chave exista na tabela, false caso a chave n�o exista na tabela.
*/
bool buscarChave(Tabela *tabela, int chave);
/*
 * Fun��o para inserir uma chave na tabela.
 * Par�metro: tabela - endere�o da tabela a ser utilizada.
 * Par�metro: chave - chave de busca a inserir.
*/
void inserirTabela(Tabela *tabela, int chave);
/*
 * Fun��o para destruir e desalocar a tabela.
 * Par�metro: tabela - ponteiro para o endere�o da tabela.
*/
void destruirTabela(Tabela *tabela);
/*
 * Fun��o para destruir e desalocar os nodos utilizados no tratamento de colis�o.
 * Par�metro: nodo - nodo alocado na tabela.
*/
void destruirNodos(Nodo *nodo);
/*
 * Fun��o para ler e processar os arquivos. Tamb�m contabiliza o tempo de execu��o de cada arquivo.
 * Par�metro: nomeArquivo - nome do arquivo a ser lido.
*/
void lerArquivos(const char *nomeArquivo);

#endif