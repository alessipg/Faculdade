/*
 *Estratégias de implementação de listas
 *  a) Temos apenas uma struct (TAD) e um ponteiro para struct que representa
 *  a lista inteira.
 *  Esse ponteiro pode ser nulo em caso de listas vazias.
 *  
 *  b)lista com cabeça: convencionar que sempre existirá um nó especial na lista,
 *  chamado cabeça. Assim, o nascimento de uma lista não resulta da simples declaração
 *  de um ponteiro inicializado com NULL, mas com a alocação deste nó especial.
 *  Neste caso, a lista é passada para uma função através do ponteiro para o nó cabeça.
 *  Uma lista com cabeça estará vazia se o campo prox do nó cabeça for NULL.
 *  
 *  c)Separamos a struct da estrutura da struct do nó.
 *  Semelhantemente a lista com cabeça, precisamos de uma função para inicializar a lista que deve
 *  ser a primeira a ser chamada.
 */
//exemplo de lista com cabeça
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
 * e devolve enderco deste novo nó ou NULL em caso de falha
 * na alocação.
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
    //se a lista atual já tem um nó, tende inserir no 
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
     *Por convenção, numa lista com cabeça, precisamos de uma função de inicialização da lista que, nada mais é
     * do que uma função que aloca o nó cabeça. Essa função deve ser sempre a primeira a ser chamada.
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
            printf("Vixe! Sem memória!\n");
    }
    printLista(cabeca->prox);
    printReverso(cabeca->prox);
    desalocaListaCabeca(cabeca);
    cabeca = NULL;
}
