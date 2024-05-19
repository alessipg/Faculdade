#include <stdio.h>

int fibonacciRec(int n)
{
    if (n <= 1)
        return 0;
    if (n < 3)
        return 1;
    return fibonacciRec(n - 1) + fibonacciRec(n - 2);
}

int main (){
    int n;
    printf("Insira valor natural para n: ");
    scanf("%d", &n);
    printf("Resultado: %d\n", fibonacciRec(n));
    return 0;
}