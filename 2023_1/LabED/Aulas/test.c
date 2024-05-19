#include <stdio.h>
#include <stdlib.h>



void altera(int *p);

int main (){
    unsigned char a[184];

    for(int i = 0; i < 184; i++){
        a[i] = 23;
    }
    int j=1;
    for(int i = 0; i < 184; i++){
        i+=2;
        printf("%d teste posicao %d eh %d\n",j, i, a[i]);
        j++;
    }
}
