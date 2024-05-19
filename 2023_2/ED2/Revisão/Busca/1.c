#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int i, cont = 0;
    srand(time(NULL));

    for(i = 0; i < 10; i++){
        printf("%d ", 1 + rand() % 5000);
        
    }
}