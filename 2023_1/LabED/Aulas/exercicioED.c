#include <stdlib.h>
#include <stdio.h>
struct TNo
{
  int chave;
  struct TNo *prox;
};

typedef struct TNo TNo;

/*
 * Abaixo temos prot�tipos de fun��es cujos c�digos
 * comentados encontram-se ap�s a fun��o main
 */
void travessiaEmListas(TNo *prim);
unsigned int contaNosLista(TNo *prim);
TNo* buscaLista(TNo *prim, int k);
TNo* pesquisaPrim(TNo *prim, int k);
void checaLista(TNo *prim);
void printPrim(TNo *primeiro);

/*
 * Abaixo temos prot�tipos de fun��es que
 * voc� dever� desenvolver como exerc�cio
 */


//TNo *insereVazia(TNo **prim, int k);

/*
 * Recebe o ponteiro de ponteiro para uma lista
 * e um valor k. Note que a lista aqui ser� passada
 * por refer�ncia e n�o por valor.
 * Insira dinamicamente um novo n� na lista quer ela esteja
 * vazia, quer n�o esteja. O novo n� inserido dinamicamente
 * dever� ser apontado pela a vari�vel prim da main. Caso j�
 * exista um n� um apontado por tal vari�vel, o novo n� dever�
 * apontar para este n� pr�-existente.
 * Devolva o endere�o do novo n� alocado ou NULL em caso
 * de falta de espa�o
 */
//TNo *insereInicio(TNo **prim, int k);

/*
 * Recebe uma lista qualquer e verifica se ela � unit�ria.
 * Se for, libera a regi�o de mem�ria do seu �nico n�. 
 * Caso contr�rio, n�o fa�a nada.
 * N�o esque�a de atualizar a vari�vel prim da main para NULL
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
 * Recebe uma lista qualquer e libera a regi�o de mem�ria do
 * primeiro n� caso exista (o primeiro n� � aquela apontado
 * pela vari�vel prim da main).
 * Note que a vari�vel prim da main dever�
 * apontar para proxim� n� ou NULL caso n�o este n�o exista.
 */
//void removePrim(TNo **prim);


int main()
{
  /*
   * Uma lista � uma sequ�ncia de zero ou mais n�s
   * acess�veis a partir de um ponteiro.
   * Se a lista estiver vazia, esse ponteiro
   * ter� valor igual a NULL.
   * Toda vez que quisermos fazer qualquer opera��o
   * na lista, passaremos como entrada o ponteiro
   * para o 1o n� da lista. Essa passagem pode ser
   * a) por valor: em geral, quando n�o precisamos alterar o  *    encadeamento da lista, passamos o ponteiro para o   
   *    primeiro por valor;
   * b) por refer�ncia: geralmente, passamos a lista 
 *     por refer�ncia (isto �, passamos o endere�o *  
        de  mem�ria onde reside o ponteiro para o 
       primeiro n�) quando � preciso alterar a conex�o entre os n�s.
*/
  TNo *prim = NULL; //listas nascem vazias, sem nos!

 /* remova esse coment�rio ap�s implementar a fun��o insereVazia.
  TNo *teste = insereVazia(&prim, 10);
  if (teste !=  NULL)
    printf("Inseriu numa lista vazia!\n");
*/
  printPrim(prim); // exemplo de passagem por valor;
}



/*
 * Algoritmo que imprime o campo chave de todos os n�s
 * de uma lista. A lista � passada por valor.
*/
void travessiaEmListas(TNo *prim)
{
  while (prim!= NULL)
  {
    printf("%d", prim->chave);
    prim = prim->prox;
  }
}

//outro exemplo de c�digo que 
//se baseia no esqueleto b�sico para travessia em lista
//o c�digo abaixo conta o total de n�s de uma lista dada.
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
 * ou NULL caso tal condi��o seja imposs�vel de satisfazer
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
 * Escreva a fun��o pesquisaPrim.
 * Entrada: uma lista e um valor inteiro k
 * Saida: Ponteiro para o primeiro n� se o campo chave
 *        deste n� for igual a k, ou seja, 
 *        se prim->chave == k. 
 *         Devolva NULL caso a lista seja vazia ou
 *         prim->chave != k
 */
TNo* pesquisaPrim(TNo *prim, int k)
{
  //sempre checamos se � vazia primeiro!
  if (prim == NULL)
  {
     printf("A lista est� vazia!\n");
     return NULL;
  }
  if (prim->chave == k)
   {
     printf("O k informado � igual ao campo chave do 1o\n");
     return prim;
  }
 else return NULL;
}
/*
 * Apresente um procedimento que recebe uma lista
 * de entrada e imprime na tela a condi��o da lista
 * que pode ser Vazia, Unit�ria ou Com mais de 1 n�.
*/
void checaLista(TNo *prim)
{
  if (prim == NULL) //if (!prim)
  {
    printf("A lista dada � vazia!\n");
    return;
  }
//  else
  if (prim->prox == NULL)
    printf("A lista � unit�ria!\n");
  else
    printf("A lista tem mais de um n�!\n");
}


/* Procedimento que imprime apenas o primeiro n� de uma
 * lista dada se este n� existir. Caso n�o exista,
 * informe na tela
 */
void printPrim(TNo *primeiro)
{
 if (primeiro == NULL)
   printf("A lista est� vazia!\n");
 else  
  printf("O valor do campo chave do 1o n� � %d\n", primeiro->chave);
}

/*
 * Recebe o ponteiro de ponteiro para uma lista
 * e um valor k. Note que a lista aqui ser� passada
 * por refer�ncia e n�o por valor (veja exemplo de invoca��o
 * na main).
 * Insira dinamicamente um novo n� na lista SOMENTE
 * se ela estiver vazia. Ou seja, se a lista estiver vazia, 
 * voc� deve alocar dinamicamente um novo n� e deve fazer
 * a vari�vel prim da main apontar para ele. Devolva o endere�o
 * do novo n� inserido.  Caso a lista
 * n�o esteja vazia ou o malloc devolva NULL, termine a
 * fun��o com return NULL.
 * Devolve o endere�o do n� alocado.
 * Esse exerc�cio n�o tem qualquer valor pr�tico mas sim
 * pedag�gico pois nos "aquecer�" para fazer a fun��o 
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
 * e um valor k. Note que a lista aqui ser� passada
 * por refer�ncia e n�o por valor.
 * Insira dinamicamente um novo n� na lista quer ela esteja
 * vazia, quer n�o esteja. O novo n� inserido dinamicamente
 * dever� ser apontado pela a vari�vel prim da main. Caso j�
 * exista um n� um apontado por tal vari�vel, o novo n� dever�
 * apontar para este n� pr�-existente.
 * Devolva o endere�o do novo n� alocado ou NULL em caso
 * de falta de espa�o
 */
TNo *insereInicio(TNo **prim, int k){
    TNo *novo = malloc(sizeof(TNo));
    novo->chave = k;
    novo->prox = *prim;
    *prim = novo;
    return novo;
}











