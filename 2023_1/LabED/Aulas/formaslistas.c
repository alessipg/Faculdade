/*
 *Estrat�gias de implementa��o de listas
 *  a) Temos apenas uma struct (TAD) e um ponteiro para struct que representa
 *  a lista inteira.
 *  Esse ponteiro pode ser nulo em caso de listas vazias.
 *  
 *  b)lista com cabe�a: convencionar que sempre existir� um n� especial na lista,
 *  chamado cabe�a. Assim, o nascimento de uma lista n�o resulta da simples declara��o
 *  de um ponteiro inicializado com NULL, mas com a aloca��o deste n� especial.
 *  Neste caso, a lista � passada para uma fun��o atrav�s do ponteiro para o n� cabe�a.
 *  Uma lista com cabe�a estar� vazia se o campo prox do n� cabe�a for NULL.
 *  
 *  c)Separamos a struct da estrutura da struct do n�.
 *  Semelhantemente a lista com cabe�a, precisamos de uma fun��o para inicializar a lista que deve
 *  ser a primeira a ser chamada.
 */
//exemplo de lista com cabe�a
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct TNo{
    int chave;
    struct TNo *prox;

}TNo;

TNo *inicializaLista(){
    TNo *cabeca=malloc(sizeof(TNo));
    if (cabeca == NULL) return NULL;
    cabeca->prox = NULL;
    cabeca->chave = -1;
    return cabeca;
}

/*
 * Insere um novo no de chave igual a k no fim de uma lista 
 * e devolve enderco deste novo n� ou NULL em caso de falha
 * na aloca��o.
 * ENTRADA: Ponteiro de Ponteiro para a lista e k
 * 
 */
TNo *insereFim(TNo **prim, int k){
    if(*prim == NULL)
    {
        *prim = malloc(sizeof(TNo));
        if(*prim == NULL) return NULL;
        (*prim)->prox = NULL;
        (*prim)->chave = k;
        return *prim;
    }
    //se a lista atual j� tem um n�, tende inserir no 
    //fim da lista menor que esta contida na lista maior.
    return insereFim(&((*prim)->prox),k);
}

void printLista(TNo *prim){
    while (prim != NULL){
        printf("%d\n", prim->chave);
        prim = prim->prox;
    }
}

void printReverso(TNo *prim){
    if(prim == NULL)
        return;
    printReverso(prim->prox);
    printf("%d\n", prim->chave);
}
void removeTudo(TNo **prim){
if(*prim == NULL) return;
removeTudo(&((*prim)->prox));
free(*prim);
*prim = NULL;
}
void desalocaListaCabeca(TNo *cabeca){
        assert(cabeca);
        if(cabeca->prox == NULL) free(cabeca);
        else{
            removeTudo(&(cabeca->prox));
        }

}
int main (){
    /*
     *Por conven��o, numa lista com cabe�a, precisamos de uma fun��o de inicializa��o da lista que, nada mais �
     * do que uma fun��o que aloca o n� cabe�a. Essa fun��o deve ser sempre a primeira a ser chamada.
     * 
     */
    TNo *cabeca = inicializaLista();
    int i;
    TNo *check;
    for(i = 0; i<10;++i){
        check = insereFim(&(cabeca->prox), i);
        if (check)
            printf("Inseriu %d em %p\n", i, check);
        else 
            printf("Vixe! Sem mem�ria!\n");
    }
    printLista(cabeca->prox);
    printReverso(cabeca->prox);
    desalocaListaCabeca(cabeca);
    cabeca = NULL;
}
