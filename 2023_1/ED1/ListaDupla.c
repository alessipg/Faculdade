#include <stdio.h>
#include <stdlib.h>
//Nós agora terão campo prox e campo anterior (preview)
//preview do primeiro nó sempre aponta para null, assim como o prox do ultimo aponta para Null;

typedef struct No {
    int chave;
    struct No *prox;
    struct No *ant;
}No;

typedef struct {
    No *inicio;
}Lista;

Lista *inicializarLista(){
    Lista *lista = malloc(sizeof(Lista));
    if(!lista) return NULL;
    lista->inicio = NULL;
    return lista;
}

void insereInicio(Lista *lista, int k){
    No *novo = malloc(sizeof(No));
    if(!novo) return;
    novo->chave = k;
    if(!lista->inicio){//verifica se a lista é unitária
    novo->ant = NULL;
    novo->prox = NULL;
    lista->inicio = novo;
    }
    else{
        novo->prox = lista->inicio;
        lista->inicio->ant = novo;
        lista->inicio = novo;
    }
}

void printLista(Lista *lista){
    No *aux = lista->inicio;
    while(aux != NULL){
        printf("%d ", aux->chave);
                aux = aux->prox;
    }
    printf("\n");
    free(aux);
    aux = NULL;
}

void printListaTras(Lista *lista){
    No *aux = lista->inicio;
    if (aux == NULL)return;
    if(aux->prox == NULL){
        printf("%d ", aux->chave);
        return;
    }
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    while(aux != NULL){
        printf("%d ", aux->chave);
        aux = aux->ant;
    }
    free(aux);
    aux = NULL;
}

void desaloca(Lista *lista){
    No *novo = lista->inicio;
    if (novo == NULL) return;
    if (novo->prox == NULL){
        free(novo);
        novo = NULL;
        return;
    }
    while (novo->prox != NULL){
        novo = novo->prox;
    }
    while (novo != NULL){
        No *ant = novo->ant;
        free(novo);
        novo = ant;
    }
    
    lista->inicio = NULL;
}
int main (){

    Lista *lista = inicializarLista();
    if (lista) printf("Lista criada!\n");
    insereInicio(lista, 3);
    insereInicio(lista, 2);
    insereInicio(lista, 1);
    printLista(lista);
    printListaTras(lista);
    desaloca(lista);
    if(!lista->inicio) printf("Lista vazia!\n");
}

/*#include <stdio.h>
#include <stdlib.h>
//Nós agora terão campo prox e campo anterior (preview)
//preview do primeiro nó sempre aponta para null, assim como o prox do ultimo aponta para Null;

typedef struct No {
    int chave;
    struct No *prox;
    struct No *ant;
}No;

typedef struct {
    No *inicio;
}Lista;

Lista *inicializarLista(){
    Lista *lista = malloc(sizeof(Lista));
    if(!lista) return NULL;
    lista->inicio = NULL;
    return lista;
}

void insereInicio(Lista *lista, int k){
    No *novo = malloc(sizeof(No));
    if(!novo) return;
    novo->chave = k;
    if(!lista->inicio){//verifica se a lista é unitária
    novo->ant = NULL;
    novo->prox = NULL;
    lista->inicio = novo;
    }
    else{
        novo->prox = lista->inicio;
        lista->inicio->ant = novo;
        lista->inicio = novo;
    }
}

void printLista(Lista *lista){
    No *aux = lista->inicio;
    while(aux != NULL){
        printf("%d ", aux->chave);
                aux = aux->prox;
    }
    printf("\n");
    free(aux);
    aux = NULL;
}

void printListaTras(Lista *lista){
    No *aux = lista->inicio;
    if (aux == NULL)return;
    if(aux->prox == NULL){
        printf("%d ", aux->chave);
        return;
    }
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    while(aux != NULL){
        printf("%d ", aux->chave);
        aux = aux->ant;
    }
    free(aux);
    aux = NULL;
}

void desaloca(Lista *lista){
    No *temp = NULL,*aux = lista->inicio;
    if (aux == NULL)return;
    while(aux->prox != NULL){
            aux = aux->prox;
        }
    while(aux != NULL){
        temp = aux;
        aux = aux->ant;
        free(temp);
        temp = NULL;
    }

}
int main (){

    Lista *lista = inicializarLista();
    if (lista) printf("Lista criada!\n");
    insereInicio(lista, 3);
    insereInicio(lista, 2);
    insereInicio(lista, 1);
    printLista(lista);
    printListaTras(lista);
    desaloca(lista);
    if(!lista->inicio) printf("Lista vazia!\n");
    printLista(lista);
}*/