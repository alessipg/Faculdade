/*
 * Aqui colocamos as defini��es
 * ex. TADs do projeto
 * prot�tipos de fun��es
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
  * deduzir quais fun��es ser�o utilizadas e criar uma lista
  * para cada fun��o, tentar descobrir quais informa��es a fun��o precisa para realizar sua tarefa
  * 
  * ap�s, cada dev ter� uma c�pia da .h
  * 
  * para compilar: gcc main.c bib.c 
  * 
  */