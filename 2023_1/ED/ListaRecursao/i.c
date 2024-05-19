#include <stdio.h>

int acharNumero(int v[], int esquerda, int direita, int x){

    if(esquerda == direita-1)
        return direita;
    int meio = (direita+ esquerda)/2;
    if(v[meio] < x)
        return acharNumero(v, meio, direita, x);
    else
        return acharNumero(v, esquerda, meio, x);
}

int 
buscaBinaria (int x, int n, int v[]) { 
   int e = -1, d = n; // atenção!
   while (e < d-1) {  
      int m = (e + d)/2;
      if (v[m] < x) e = m;
      else d = m; 
   }
   return d;
}
int main (){
    int v[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int x = 12;
    printf("%d",acharNumero(v, 0, 15, x));

}