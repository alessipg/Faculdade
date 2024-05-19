#include <stdio.h>
struct TNo
{
    int chave;
    struct TNo *prox;
};
typedef struct TNo TNo;
/*fun��o que imprime apenas o primeiro n� de uma lista dada
 *caso exista, sen�o informe na tela.
 */
void printPrim(TNo *primeiro)
{
    if (primeiro == NULL)
        printf("A lista esta vazia!\n");
    else
        printf("O valor do campo chave do 1o no e: %d\n", primeiro->chave);
}
/*Fa�a uma fun��o que recebe uma lista de entrada. Ela deve checar se est�
 *vazia, se � unit�ria ou se possui v�rios elementos.
 */
void checarLista(TNo *primeiro)
{
    if (primeiro == NULL)
    {
        printf("A lista esta vazia!\n");
        return; // return evita o uso do else if
    }
    if (primeiro->prox == NULL)
        printf("A lista e unitaria!\n");
    else
        printf("A lista e multipla\n");
}

/*Fa�a uma fun��o chamda pesquisaPrim
 *Entrada: uma lista e um valor inteiro k;
 *Saida: Ponteiro para o primeiro n� se o campo chave deste n� for igual a k, ou seja, se prim->chave == k;
 *Devolva null se lista vazia;
 */

TNo *pesquisaPrim(TNo *primeiro, int k)
{
    if (primeiro == NULL)
    {
        printf("A lista esta vazia!\n");
        return NULL;
    }
    if (primeiro->chave == k)
    {
        printf("O valor do campo chave do 1o no � igual a k");
        return primeiro;
    }
    else
        printf("O valor do campo chave nao eh igual a k");
}
/*
 *Algoritmo que ilustra como se passar por todos os
 *elementos de uma lista passada por valor.
 */
void travessiaEmListas(TNo *primeiro)
{
    while (primeiro != NULL)
    {

        printf("%d", primeiro->chave);
        primeiro = primeiro->prox;
    }
    return;
}
/*
 *Recebe uma lista e um parametro de pesquisa K.
 *Saida: devolve um ponteiro p tal que p->chave == k;
 *ou NULL se a condi��o n�o for satisfeita.
 */
TNo *acharK(TNo *primeiro, int k)
{

    while (primeiro != NULL)
    {
        if (primeiro->chave == k)
        {
            printf("Valor k no no end: %p\n", primeiro);
            return primeiro;
        }
            primeiro = primeiro->prox;
    }
}
//devolver quantidades de nos com chave ==k
TNo *inserir(TNo *primeiro, int k)
{
    TNo *novo = (TNo *)malloc(sizeof(TNo));
    novo->chave = k;
    primeiro->prox = novo;
    return novo;
}
int main()
{
    /*
     *Uma lista � uma sequencia de 0 ou mais n�s acess�veis
     *a partir de um ponteiro.
     *Se a lista estiver vazia, esse ponteiro ter� valor = NULL;
     *Toda vez que quisermos fazer qualquer opera��o na lista, passaremos
     *como entrada o ponteiro para o 1o n� da lista. Essa passagem pode ser
     *a) por valor: em geral, quando n�o precisamos alterar o encadeamento da lista,
     *   passamos o ponteiro para primeiro por valor.
     *b) por referencia: geralmente passamos a lista por referencia(isto �, passamos o endere�o
     *   de memoria onde reside o ponteiro para o primeiro n�), quando � preciso alterar a conex�o
     *   entre os n�s.
     *
     */

    TNo *prim = NULL; // listas nascem vazias, sem nos;
    printPrim(prim);  // exemplo de passagem por valor;
    checarLista(prim);
    pesquisaPrim(prim, 3); // present
    prim = inserir(prim, 2);
    printPrim(prim);
    acharK(prim, 2);
}