#include <stdio.h>

int soma(int m, int n){
    if(m == n)
        return m;    
    return m+soma(m+1,n);    

}

int main(){
    int n,m;
    scanf("%d",&m);
    scanf("%d",&n);
    if(m>n){
        int aux = m;
        m=n;
        n=aux;
    }
    printf("%d",soma(m,n));

}