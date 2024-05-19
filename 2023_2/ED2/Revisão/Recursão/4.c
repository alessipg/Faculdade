#include <stdio.h>

int busca(int *v, int ini, int fim, int x){
    if(ini>fim)
        return -1;
    if(v[ini] == x)
        return ini;
    return busca(v, ini+1, fim, x);
}

int main(){
    int v[5]={13,52,23,9,1};

    int x;
    scanf("%d",&x);
    printf("%d",busca(v,0,4,x));

    
}