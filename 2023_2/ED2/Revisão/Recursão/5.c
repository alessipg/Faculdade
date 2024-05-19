#include <stdio.h>


void inverte(int *v, int ini, int fim){
    if(ini>fim)
        return;
    int aux = v[ini];
    v[ini] = v[fim];
    v[fim] = aux;
    inverte(v, ini+1, fim-1);
}

int main(){
    int v[5]={0,1,2,3,4};

    inverte(v, 0, 4);
    for(int i=0; i<5; i++){
        printf("%d ", v[i]);
    }
}