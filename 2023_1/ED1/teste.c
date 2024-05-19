#include <stdio.h>

void imprime(long int n)
{
    if (n <= 0)
        return;
    if (n == 1)
    {
        printf("%ld\n", n);
        return;
    }
    printf("%ld\n", n);
    imprime(n - 1);
}


int main()
{
    imprime(1000000000);
}