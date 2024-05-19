/*
 *Lista com struct separada para lista e para nó
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct TNo{
    int chave;
    struct TNo *prox;

}TNo;

typedef struct TipoLista{
    unsigned int qtdNos;
    unsigned int valorMedioChave;
    TNo *prim;
    //TNo *ult;
    TNo *menor;//ponteiro para no com menor chave
    TNo *maior;//ponteiro para no com maior chave
}TipoLista;


TipoLista *criaLista(){
    TipoLista *l = malloc(sizeof(TipoLista));
    if(!l) return NULL;
    //lista nasce vazia
    l->qtdNos = 0;
    l->valorMedioChave = 0;
    l->prim = NULL;
    l->menor = NULL;
    l->maior = NULL;
    return l;
}
TipoLista criaLista2(){
    TipoLista l;

    l.qtdNos = 0;
    l.valorMedioChave = 0;
    l.prim = NULL;
    l.menor = NULL;
    l.maior = NULL;
    return l;
}
//procedimento de inserção no inicio da lista
//entrada variavel tipolista

insereInicio(TipoLista l){
    
}
int main(){
    TipoLista *l = criaLista();
    TipoLista l2 = criaLista2();
    //insereInicio()
    return 0;
}