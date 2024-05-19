#include <stdio.h>
struct TNo
{
    int chave;
    struct TNo *prox;
};
typedef struct TNo TNo;
/*função que imprime apenas o primeiro nó de uma lista dada
 *caso exista, senão informe na tela.
 */
void printPrim(TNo *primeiro)
{
    if (primeiro == NULL)
        printf("A lista esta vazia!\n");
    else
        printf("O valor do campo chave do 1o no e: %d\n", primeiro->chave);
}
/*Faça uma função que recebe uma lista de entrada. Ela deve checar se está
 *vazia, se é unitária ou se possui vários elementos.
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

/*Faça uma função chamda pesquisaPrim
 *Entrada: uma lista e um valor inteiro k;
 *Saida: Ponteiro para o primeiro nó se o campo chave deste nó for igual a k, ou seja, se prim->chave == k;
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
        printf("O valor do campo chave do 1o no é igual a k");
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
 *ou NULL se a condição não for satisfeita.
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
     *Uma lista é uma sequencia de 0 ou mais nós acessíveis
     *a partir de um ponteiro.
     *Se a lista estiver vazia, esse ponteiro terá valor = NULL;
     *Toda vez que quisermos fazer qualquer operação na lista, passaremos
     *como entrada o ponteiro para o 1o nó da lista. Essa passagem pode ser
     *a) por valor: em geral, quando não precisamos alterar o encadeamento da lista,
     *   passamos o ponteiro para primeiro por valor.
     *b) por referencia: geralmente passamos a lista por referencia(isto é, passamos o endereço
     *   de memoria onde reside o ponteiro para o primeiro nó), quando é preciso alterar a conexão
     *   entre os nós.
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