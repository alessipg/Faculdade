/*
 * Nome: Gabriel Alessi Posonski
 * RA: 2259583
 */

#include <stdio.h>
#include <stdlib.h>
long long int fatorialRec(int n)
{
    long long int fat;
    if (n <= 1)
        return 1;
    if (n == 2)
        return 2;
    fat = n * fatorialRec(n - 1);
    return fat;
}

int fibonacciRec(int n)
{
    if (n <= 1)
        return 0;
    if (n < 3)
        return 1;
    return fibonacciRec(n - 1) + fibonacciRec(n - 2);
}

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

void imparesRec(int n)
{
    if (n == 1)
        printf("%d ", n);
    else
    {
        if (n % 2 == 1)
            printf("%d ", n);
        imparesRec(n - 1);
    }
}

int somaImparesRec(int n)
{
    if (n == 1)
        return 1;
    if (n % 2 == 1)
        return n + somaImparesRec(n - 1);
    else
        return somaImparesRec(n - 1);
}

int prodParesRec(int n)
{
    if (n == 2)
        return 2;
    if (n % 2 == 0)
        return n * prodParesRec(n - 1);
    else
        return prodParesRec(n - 1);
}

void vetorPrimeiroRec(int vet[], int i, int j)
{
    if (i < 0)
        return;
    vetorPrimeiroRec(vet, i - 1, j);
    if (i < j)
        printf("%d ", vet[i]);
}

int vetorUltimoRec(int vet[], int i, int j)
{
    if (i < 0)
        return;
    if (i < j)
        printf("%d ", vet[i]);
    vetorUltimoRec(vet, i - 1, j);
}
int main()
{

    int opcao = 0;
    int n;
    int i = 5; // crei uma variável para exemplificar que a função funcionaria com arrays de qualquer tamanho.

    int vet[5] = {3, 9, 4, 7, 2}; // achei mais prático já deixar declarado um vetor com números aleatórios
    do
    {

        printf("Selecione a funcao desejada: \n");
        printf("1) Calcular fatorial\n");
        printf("2) n-esimo numero de de Fibonacci\n");
        printf("3) Numeros pares no intervalo [0,n]\n");
        printf("4) Numeros impares no intervalo [n,0]\n");
        printf("5) Soma de numeros impares no intervalo [0,n]\n");
        printf("6) Produto dos numeros pares no intervalo [1,n]\n");
        printf("7) Imprimir elementos de um vetor do primeiro ao ultimo\n");
        printf("8) Imprimir elementos de um vetor do ultimo ao primeiro\n");
        printf("9) Sair\n");

        scanf("%d", &opcao);
        switch (opcao)
        {
        /*
         *não foquei em evitar o erro do usuário caso ele não siga as instruções, porém fiz algumas manobras
         *no código que podem funcionar, como por exemplo se ele inserir um número inteiro.
         */
        case 1:

            /*
             *O compilador apresenta warning ao imprimir um long long int. Usei esse tipo pois como o resultado
             *dos fatoriais é exponencial, achei melhor abranger uma gama maior de resultados. Não sei porque o compilador
             *achou conflito com lld.
             */
            printf("Insira valor natural para n: ");
            scanf("%d", &n);
            printf("Resultado: %lld\n", fatorialRec(n));
            break;

        case 2:
            printf("Insira valor natural para n: ");
            scanf("%d", &n);
            printf("Resultado: %d\n", fibonacciRec(n));
            break;
        case 3:
            printf("Insira valor natural para n: ");
            scanf("%d", &n);
            printf("Resultado:\n");
            paresIntervaloRec(n);
            printf("\n");
            break;
        case 4:
            printf("Insira valor natural para n: ");
            scanf("%d", &n);
            printf("Resultado:\n");
            imparesRec(n);
            printf("\n");
            break;
        case 5:
            printf("Insira valor natural para n: ");
            scanf("%d", &n);
            printf("Resultado: %d\n", somaImparesRec(n));
            break;
        case 6:
            printf("Insira valor natural para n: ");
            scanf("%d", &n);
            printf("Resultado: %d\n", prodParesRec(n));
            break;
        case 7:
            vetorPrimeiroRec(vet, i, i);
            printf("\n");
            break;
        case 8:
            vetorUltimoRec(vet, i, i);
            printf("\n");
            break;
        case 9:
            break;
        default:
            break;
        }

    } while (opcao != 9);

    return 0;
}