#include <stdio.h>
//Aluno: Gabriel Alessi Posonski RA: 2259583
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

int main(){
    int n;
    printf("Insira valor natural para n: ");
    scanf("%d", &n);
    printf("Resultado: %lld\n", fatorialRec(n));
    /*
    *O compilador apresenta warning ao imprimir um long long int. Usei esse tipo pois como o resultado
    *dos fatoriais é exponencial, achei melhor abranger uma gama maior de resultados. Não sei porque o compilador
    *achou conflito com %lld.
    */
   return 0;
}