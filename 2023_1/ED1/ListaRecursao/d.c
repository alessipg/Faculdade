#include <stdio.h>

void imparesRec(int n)
{
    if (n == 1)
        printf("%d ", n);
    else
    {
        if (n % 2 == 1)
            printf("%d ", n);//entendi no enunciado que a impressão seria do último ao primeiro.
        imparesRec(n - 1);
    }
}

int main (){
    int n;
    printf("Insira valor natural para n: ");
    scanf("%d", &n);
    printf("Resultado:\n");
    imparesRec(n);
    printf("\n");
    return 0;
}