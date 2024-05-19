#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *proximo;
}No;

typedef struct Lista
{
    No *inicio;
    int tam;
}Lista;

void inserirInicio(Lista *lista, int valor){
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tam++;

}
int main (){
    Lista lista;
    lista.tam = 0;
    lista.inicio = NULL;
    int option;
    printf("1 - Inserir Inicio\n2 - Inserir Final\n3 - Imprimir\n4 - Sair\n");
    scanf("%d", &option);
    switch(option){
        case 1:
            inserirInicio(&lista, 10);
            break;
        case 2:
            inserirInicio(&lista, 20);
            break;
        case 3:
            imprimir(&lista);
            break;
        case 4:
            break;
    }


}