#include <stdio.h>

void paresIntervaloRec(int n)
{
    if (n == 0)
        printf("%d ", n);
    else
    {
        paresIntervaloRec(n - 1);
        if (n % 2 == 0)
            printf("%d ", n);
    }
}

int main(){
    int n;
    printf("Insira valor natural para n: ");
    scanf("%d", &n);
    printf("Resultado:\n");
    paresIntervaloRec(n);
    return 0;
}