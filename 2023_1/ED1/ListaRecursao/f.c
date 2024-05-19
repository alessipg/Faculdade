#include <stdio.h>

int prodParesRec(int n)
{
    if (n == 2)
        return 2;
    if (n % 2 == 0)
        return n * prodParesRec(n - 1);
    else
        return prodParesRec(n - 1);
}
int main(){
    int n;
    printf("Insira valor natural para n: ");
    scanf("%d", &n);
    printf("Resultado: %d\n", prodParesRec(n));
    return 0;
}