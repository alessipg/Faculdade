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
 * Função para criar uma tabela.
 * Parâmetro: tamanho - quantidade de posições desejadas na tabela.
 * Retorno: endereço da tabela criada.
*/
Tabela *criarTabela(int tamanho);
/*
 * Função para mapear uma chave na tabela hash.
 * Parâmetro: tamanho - quantidade de posições existentes na tabela.
 * Parâmetro: chave - chave de busca a ser inserida.
 * Retorno: inteiro correspondente a posição mapeada da chave a ser inserida.
*/
int hash(int tamanho, int chave);
/*
 * Função para verificar a existência de uma chave na tabela.
 * Parâmetro: tabela - endereço da tabela a ser utilizada.
 * Parâmetro: chave - chave de busca desejada.
 * Retorno: true caso a chave exista na tabela, false caso a chave não exista na tabela.
*/
bool buscarChave(Tabela *tabela, int chave);
/*
 * Função para inserir uma chave na tabela.
 * Parâmetro: tabela - endereço da tabela a ser utilizada.
 * Parâmetro: chave - chave de busca a inserir.
*/
void inserirTabela(Tabela *tabela, int chave);
/*
 * Função para redimensionar a tabela quando o fator carga atinge 0.7.
 * Parâmetro: tabela - ponteiro para ponteiro do endereço da tabela.
*/
void redimensionar(Tabela **tabela);
/*
 * Função para destruir e desalocar a tabela.
 * Parâmetro: tabela - ponteiro para o endereço da tabela.
*/
void destruirTabela(Tabela *tabela);
/*
 * Função para ler e processar os arquivos. Também contabiliza o tempo de execução de cada arquivo.
 * Parâmetro: nomeArquivo - nome do arquivo a ser lido.
*/
void lerArquivos(const char *nomeArquivo);
#endif