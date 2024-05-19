/*
 * Aqui colocamos as definições
 * ex. TADs do projeto
 * protótipos de funções
 * 
 */
typedef struct TNoEnderecos{
    unsigned char end;
    struct TNoEnderecos *prox;
}TNoEnderecos;
typedef struct TRico{
    int qtdBitcoins;
    TNoEnderecos *prim;

}TRico;

TRico *acharmaior(unsigned char c, int ini, int fim);
//dicas para o projeto
 /*
  * deduzir quais funções serão utilizadas e criar uma lista
  * para cada função, tentar descobrir quais informações a função precisa para realizar sua tarefa
  * 
  * após, cada dev terá uma cópia da .h
  * 
  * para compilar: gcc main.c bib.c 
  * 
  */