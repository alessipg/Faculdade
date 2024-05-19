#include <stdio.h>
#include <stdlib.h>

int main(){


    /*1)
    *a)true
    *b)true
    *c)3630
    *d)505
    *e)10
    * 
     */
    //3
    /*
    int n;
    scanf("%d",&n);
    int *v = malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d",(v+i));
    }

    for(int i = n-1; i >= 0; i--){
        printf("%d ",*(v+i));
    }
    */

    //4
    /*
    char string[10] = "Teste";
    int k = 0;
    while(*(string+k) != '\0'){
        k++;
    }
    printf("%c ",*(string+(k-1)));
    */

    int *v1 = malloc(4*sizeof(int));
    int vet[4] = {11,13,45,7};
    for(int i = 0; i < 4; i++)
        v1[i] = vet[i];
    int v2[6] = {24,4,16,81,10,12};

    int *v3 = realloc(v1, 10*sizeof(int));
    for(int i = 0; i < 10; i++){
        printf(" %d %d\n",i,v3[i]);
    }
    for(int i = 4, j = 0; i < 10;i++,j++){
        v3[i] = v2[j];
    }

    for(int i = 0; i < 10; i++){
        printf("%d\n",v3[i]);
    }







}