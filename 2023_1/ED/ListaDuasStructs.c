#include <stdio.h>
#include <stdlib.h>

typedef struct TNo{
    int chave;
    struct TNo *prox;

}TNo;

typedef struct Lista{
    unsigned int qtdNos;
    TNo *prim;
    TNo *menor;
    TNo *maior;
    TNo *ult;
}Lista;


Lista *criaLista(){
    Lista *l = malloc(sizeof(Lista));
    if(!l) return NULL;
    //lista nasce vazia
    l->qtdNos = 0;
    l->prim = NULL;
    l->menor = NULL;
    l->maior = NULL;
    l->ult = NULL;
    return l;
}
Lista criaLista2(){
    Lista l;

    l.qtdNos = 0;
    l.prim = NULL;
    l.menor = NULL;
    l.maior = NULL;
    return l;
}
//procedimento de inserção no inicio da lista
//entrada variavel tipolista

void insereInicio(Lista *l, int k){
    TNo *novo = malloc(sizeof(TNo));
    if(!novo) return;
    novo->chave = k;
    //verifica se já possui algum nó alocado
    if(!l->maior) l->maior = novo;
    if(!l->menor) l->menor = novo;
    //atribui os nos se a condição for satisfeita
    if(k < l->menor->chave) l->menor = novo;
    if (k > l->maior->chave) l->maior = novo;
    novo->prox = l->prim;
    
    //checa se a lista é vazia, caso sim, o atual nó é o ultimo
    if(l->prim == NULL) l->ult = novo;
    l->prim = novo;
    l->qtdNos++;
    

}

void insereFim(Lista *l, int k){
    TNo *aux, *novo = malloc(sizeof(TNo));
    novo->chave = k;
    novo->prox = NULL;
    aux = l->prim;
    while(aux != NULL){
        aux->prox = novo;
        aux = aux->prox;
    }
    
}
void printLista(Lista *lista){
    TNo *aux = lista->prim;
    while(aux != NULL){
        printf("%d \n", aux->chave);
        aux = aux->prox;
    }
    return;
}


int main(){
    Lista *l = criaLista();
    if(l) printf("Lista criada!\n");
    //Lista l2 = criaLista2();
    for(int i = 0; i <10; i++)
    insereInicio(l, i);
    insereInicio(l,-7);
    insereInicio(l, 35);
    printLista(l);
    
    printf("Menor eh %d\n",l->menor->chave);
    printf("Maior eh %d\n",l->maior->chave);
    printf("Lista tem %d elementos\n",l->qtdNos);
    printf("Ultimo elemento da lista eh %d\n",l->ult->chave);


    
    return 0;
}