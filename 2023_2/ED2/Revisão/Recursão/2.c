#include <stdio.h>

int fatorial(int x){
    if(x == 0 || x == 1) 
        return 1;
    return x*(fatorial(x-1));
}

int main(){
    int x;
    scanf("%d",&x);
    int r = fatorial(x);
    printf("%d\n",r );
}