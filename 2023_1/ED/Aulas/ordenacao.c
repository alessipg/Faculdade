#include <stdio.h>

void selecao(int v[], int ini, int fim){
    if(ini > fim) return;
    for(int i = ini; i < fim; i++){
        if(v[i] < v[ini]){ 
        int aux = v[ini];
        v[ini] = v[i];
        v[i] = aux;
        }
    }
    for(int i = 0; i < fim; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void ordenacaoPorSelecao(int v[], int ini, int fim){
    if(ini >= fim)  return;
    for(int i = 0; i < fim; i++){
    selecao(v, ini+i, fim);
    }
}

int main (){
    int v[60] = {17, 42, 9, 25, 56, 83, 31, 77, 63, 5, 17, 42, 9, 25, 56, 83, 31, 77, 63, 5, 72, 38, 91, 14, 68, 29, 52, 46, 11, 88, 33, 70, 22, 99, 44, 27, 61, 80, 36, 73, 20, 95, 66, 13, 55, 39, 84, 71, 48, 16, 79, 35, 60, 87, 23, 51, 76, 10, 67, 18
};
    ordenacaoPorSelecao(v,0,60);
    
}