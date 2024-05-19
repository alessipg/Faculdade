#ifndef HASHFIXO_H
#define HASHFIXO_H
#include <stdbool.h>

typedef struct Nodo
{
    struct Nodo *prox;
    int chave;
    int qtdColisao;//apenas informativo de quantas chaves são mapeadas nesse hash
} Nodo;

typedef struct Tabela
{
    Nodo **nodo;
    int qtdChaves;
    int comparacoes;
} Tabela;

/*
 * Função para criar uma tabela de 100 posições.
 * Retorno: endereço da tabela criada.
*/
Tabela *criarTabela();
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
 * Função para destruir e desalocar a tabela.
 * Parâmetro: tabela - ponteiro para o endereço da tabela.
*/
void destruirTabela(Tabela *tabela);
/*
 * Função para destruir e desalocar os nodos utilizados no tratamento de colisão.
 * Parâmetro: nodo - nodo alocado na tabela.
*/
void destruirNodos(Nodo *nodo);
/*
 * Função para ler e processar os arquivos. Também contabiliza o tempo de execução de cada arquivo.
 * Parâmetro: nomeArquivo - nome do arquivo a ser lido.
*/
void lerArquivos(const char *nomeArquivo);

#endif