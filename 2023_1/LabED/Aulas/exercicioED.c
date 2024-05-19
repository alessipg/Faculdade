#include <stdlib.h>
#include <stdio.h>
struct TNo
{
  int chave;
  struct TNo *prox;
};

typedef struct TNo TNo;

/*
 * Abaixo temos protótipos de funções cujos códigos
 * comentados encontram-se após a função main
 */
void travessiaEmListas(TNo *prim);
unsigned int contaNosLista(TNo *prim);
TNo* buscaLista(TNo *prim, int k);
TNo* pesquisaPrim(TNo *prim, int k);
void checaLista(TNo *prim);
void printPrim(TNo *primeiro);

/*
 * Abaixo temos protótipos de funções que
 * você deverá desenvolver como exercício
 */


//TNo *insereVazia(TNo **prim, int k);

/*
 * Recebe o ponteiro de ponteiro para uma lista
 * e um valor k. Note que a lista aqui será passada
 * por referência e não por valor.
 * Insira dinamicamente um novo nó na lista quer ela esteja
 * vazia, quer não esteja. O novo nó inserido dinamicamente
 * deverá ser apontado pela a variável prim da main. Caso já
 * exista um nó um apontado por tal variável, o novo nó deverá
 * apontar para este nó pré-existente.
 * Devolva o endereço do novo nó alocado ou NULL em caso
 * de falta de espaço
 */
//TNo *insereInicio(TNo **prim, int k);

/*
 * Recebe uma lista qualquer e verifica se ela é unitária.
 * Se for, libera a região de memória do seu único nó. 
 * Caso contrário, não faça nada.
 * Não esqueça de atualizar a variável prim da main para NULL
 */
//void removeUnitaria(TNo **prim);
void removeUnitaria(TNo **prim)
{
  if((*prim)->prox == NULL)
    free(*prim);
  else
    printf("Lista vazia\n");
}

/*
 * Recebe uma lista qualquer e libera a região de memória do
 * primeiro nó caso exista (o primeiro nó é aquela apontado
 * pela variável prim da main).
 * Note que a variável prim da main deverá
 * apontar para proximó nó ou NULL caso não este não exista.
 */
//void removePrim(TNo **prim);


int main()
{
  /*
   * Uma lista é uma sequência de zero ou mais nós
   * acessíveis a partir de um ponteiro.
   * Se a lista estiver vazia, esse ponteiro
   * terá valor igual a NULL.
   * Toda vez que quisermos fazer qualquer operação
   * na lista, passaremos como entrada o ponteiro
   * para o 1o nó da lista. Essa passagem pode ser
   * a) por valor: em geral, quando não precisamos alterar o  *    encadeamento da lista, passamos o ponteiro para o   
   *    primeiro por valor;
   * b) por referência: geralmente, passamos a lista 
 *     por referência (isto é, passamos o endereço *  
        de  memória onde reside o ponteiro para o 
       primeiro nó) quando é preciso alterar a conexão entre os nós.
*/
  TNo *prim = NULL; //listas nascem vazias, sem nos!

 /* remova esse comentário após implementar a função insereVazia.
  TNo *teste = insereVazia(&prim, 10);
  if (teste !=  NULL)
    printf("Inseriu numa lista vazia!\n");
*/
  printPrim(prim); // exemplo de passagem por valor;
}



/*
 * Algoritmo que imprime o campo chave de todos os nós
 * de uma lista. A lista é passada por valor.
*/
void travessiaEmListas(TNo *prim)
{
  while (prim!= NULL)
  {
    printf("%d", prim->chave);
    prim = prim->prox;
  }
}

//outro exemplo de código que 
//se baseia no esqueleto básico para travessia em lista
//o código abaixo conta o total de nós de uma lista dada.
unsigned int contaNosLista(TNo *prim)
{
  int cont = 0;
   while (prim != NULL)
   {
      cont++;
      prim = prim -> prox;
   }
  return cont;
}

/*
 * Recebe uma lista e um parametro de pesquisa k
 * Devolve um ponteiro p tal que p->chave == k
 * ou NULL caso tal condição seja impossível de satisfazer
*/
TNo* buscaLista(TNo *prim, int k)
{
  while (prim != NULL)
  {
    if (prim->chave == k)
      return prim;

    prim = prim->prox;
  }
}

/*
 * Escreva a função pesquisaPrim.
 * Entrada: uma lista e um valor inteiro k
 * Saida: Ponteiro para o primeiro nó se o campo chave
 *        deste nó for igual a k, ou seja, 
 *        se prim->chave == k. 
 *         Devolva NULL caso a lista seja vazia ou
 *         prim->chave != k
 */
TNo* pesquisaPrim(TNo *prim, int k)
{
  //sempre checamos se é vazia primeiro!
  if (prim == NULL)
  {
     printf("A lista está vazia!\n");
     return NULL;
  }
  if (prim->chave == k)
   {
     printf("O k informado é igual ao campo chave do 1o\n");
     return prim;
  }
 else return NULL;
}
/*
 * Apresente um procedimento que recebe uma lista
 * de entrada e imprime na tela a condição da lista
 * que pode ser Vazia, Unitária ou Com mais de 1 nó.
*/
void checaLista(TNo *prim)
{
  if (prim == NULL) //if (!prim)
  {
    printf("A lista dada é vazia!\n");
    return;
  }
//  else
  if (prim->prox == NULL)
    printf("A lista é unitária!\n");
  else
    printf("A lista tem mais de um nó!\n");
}


/* Procedimento que imprime apenas o primeiro nó de uma
 * lista dada se este nó existir. Caso não exista,
 * informe na tela
 */
void printPrim(TNo *primeiro)
{
 if (primeiro == NULL)
   printf("A lista está vazia!\n");
 else  
  printf("O valor do campo chave do 1o nó é %d\n", primeiro->chave);
}

/*
 * Recebe o ponteiro de ponteiro para uma lista
 * e um valor k. Note que a lista aqui será passada
 * por referência e não por valor (veja exemplo de invocação
 * na main).
 * Insira dinamicamente um novo nó na lista SOMENTE
 * se ela estiver vazia. Ou seja, se a lista estiver vazia, 
 * você deve alocar dinamicamente um novo nó e deve fazer
 * a variável prim da main apontar para ele. Devolva o endereço
 * do novo nó inserido.  Caso a lista
 * não esteja vazia ou o malloc devolva NULL, termine a
 * função com return NULL.
 * Devolve o endereço do nó alocado.
 * Esse exercício não tem qualquer valor prático mas sim
 * pedagógico pois nos "aquecerá" para fazer a função 
 * insereInicio.
 */
TNo *insereVazia(TNo **prim, int k){
    if(*prim == NULL){
        TNo *novo = malloc(sizeof(TNo));
        novo->chave = k;
        novo->prox = NULL;
        return novo;
    }
}

/*
 * Recebe o ponteiro de ponteiro para uma lista
 * e um valor k. Note que a lista aqui será passada
 * por referência e não por valor.
 * Insira dinamicamente um novo nó na lista quer ela esteja
 * vazia, quer não esteja. O novo nó inserido dinamicamente
 * deverá ser apontado pela a variável prim da main. Caso já
 * exista um nó um apontado por tal variável, o novo nó deverá
 * apontar para este nó pré-existente.
 * Devolva o endereço do novo nó alocado ou NULL em caso
 * de falta de espaço
 */
TNo *insereInicio(TNo **prim, int k){
    TNo *novo = malloc(sizeof(TNo));
    novo->chave = k;
    novo->prox = *prim;
    *prim = novo;
    return novo;
}











