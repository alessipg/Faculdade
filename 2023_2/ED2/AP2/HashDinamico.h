#ifndef HASHDINAMICO_H
#define HASHDINAMICO_H
#include <stdbool.h>

typedef struct Hash
{
    int chave;
    char status;
} Hash;

typedef struct Tabela
{
    Hash **hash;
    int qtdChaves;
    int tamanho;
    int comparacoes;
} Tabela;
/*
 * Fun��o para criar uma tabela.
 * Par�metro: tamanho - quantidade de posi��es desejadas na tabela.
 * Retorno: endere�o da tabela criada.
*/
Tabela *criarTabela(int tamanho);
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
 * Fun��o para redimensionar a tabela quando o fator carga atinge 0.7.
 * Par�metro: tabela - ponteiro para ponteiro do endere�o da tabela.
*/
void redimensionar(Tabela **tabela);
/*
 * Fun��o para destruir e desalocar a tabela.
 * Par�metro: tabela - ponteiro para o endere�o da tabela.
*/
void destruirTabela(Tabela *tabela);
/*
 * Fun��o para ler e processar os arquivos. Tamb�m contabiliza o tempo de execu��o de cada arquivo.
 * Par�metro: nomeArquivo - nome do arquivo a ser lido.
*/
void lerArquivos(const char *nomeArquivo);
#endif