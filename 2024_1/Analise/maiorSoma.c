#include <stdio.h>
#include <stdlib.h>

typedef struct Result
{
    int ini;
    int fim;
    int soma;
} Result;

Result *somar2(int lucros[], int ini, int fim, int soma1)
{
    if (ini == fim)
    {
        //printf("entrou %d %d\n", lucros[ini], lucros[fim]);
        Result *result = malloc(sizeof(Result));
        result->ini = ini;
        result->fim = ini;
        result->soma = lucros[ini];
        return result;
    }
    Result *result = somar2(lucros, ini + 1, fim, soma1);
    //printf("saiu da recursao %d %d %d\n", result->ini, result->fim, result->soma);
    int somaTemp = 0;
    for (int i = fim; i >= ini; i--)
    {
        somaTemp += lucros[i];
        printf("%d ",lucros[i]);
        // printf("%d %d %d\n", somaTemp, result->soma, i);
        if (somaTemp + soma1 > result->soma)
        {
            result->soma = somaTemp;
            // printf("soma %d %d\n", somaTemp, result->soma);
            result->ini = i;
        }
    }
    printf("\n");
    //printf("saiu da funcao %d %d %d\n", result->ini, result->fim, result->soma);
    return result;
}

Result *somar(int lucros[], int ini, int fim)
{
    if (ini == fim)
    {
        Result *result = malloc(sizeof(Result));
        result->ini = ini;
        result->fim = ini;
        result->soma = lucros[ini];
        return result;
    }

    Result *result = somar(lucros, ini, fim - 1);
    Result *result2 = somar2(lucros,result->fim+1,fim, result->soma);
    /*if (lucros[fim] > result->soma)
        {
            result->soma = lucros[fim];
            result->ini = fim;
            result->fim = fim;
        }    
    else if (lucros[fim] + result->soma > result->soma)
    {
        result->soma += lucros[fim];
        result->fim = fim;
    }
    return result;*/
    //printf("%d %d\n", result->soma, result2->soma);
    int soma = result->soma + result2->soma;
    //printf("%d\n", soma);
    //printf("%d %d // %d %d",result->ini, result->fim, result2->ini, result2->fim);
    if (result->fim + 1 == result2->ini && soma > result->soma && soma > result2->soma)
    {
        result->fim = result2->fim;
        result->soma += result2->soma;
        return result;
    }
    if (result->soma > result2->soma){
        //printf("soma 1\n");
        return result;
    }
    else{
        //printf("soma 1\n");
        return result2;
    }
}

int main()
{
    //int lucros[11] = {300, -200, -10, 30, 4, -30, 31, -3, 1, 15, 10};
    int lucros[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Result *res = somar(lucros, 0, 8);
    printf("Intervalo [%d, %d]: Soma = %d\n", res->ini, res->fim, res->soma);
    free(res);
    return 0;
}
