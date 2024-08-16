#include <stdio.h>
#include <stdlib.h>

typedef struct Result
{
    int ini;
    int fim;
    int soma;
} Result;
Result *somarEsq(int lucros[], int ini, int fim)
{
    Result *result = malloc(sizeof(Result));
    result->ini = fim;
    result->fim = fim;
    result->soma = lucros[fim];
    if (ini < fim)
    {
        int soma = lucros[fim];
        for (int i = fim - 1; i >= ini; i--)
        {
            soma += lucros[i];
            if (soma > result->soma)
            {
                result->ini = i;
                result->soma = soma;
            }
        }
    }
    return result;
}
Result *somarDir(int lucros[], int ini, int fim)
{
    Result *result = malloc(sizeof(Result));
    result->ini = ini;
    result->fim = ini;
    result->soma = lucros[ini];
    if (ini < fim)
    {
        int soma = lucros[ini];
        for (int i = ini + 1; i <= fim; i++)
        {
            soma += lucros[i];
            if (soma > result->soma)
            {
                result->fim = i;
                result->soma = soma;
            }
        }
    }
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
    int meio = (ini + fim) / 2;
    Result *esq = somar(lucros, ini, meio);
    Result *dir = somar(lucros, meio + 1, fim);
    Result *intersecEsq = somarEsq(lucros, ini, meio);
    Result *intersecDir = somarDir(lucros, meio + 1, fim);
    int intersec = intersecDir->soma + intersecEsq->soma;
    if (intersec > dir->soma && intersec > esq->soma)
    {
        intersecEsq->fim = intersecDir->fim;
        intersecEsq->soma = intersec;
        return intersecEsq;
    }
    if (esq->soma > dir->soma)
        return esq;
    else
        return dir;
}
int main()
{
    // int lucros[11] = {-5, -10, 15, 12, 4, -30, 31, -3, 1, 15, 10};
    int lucros[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Result *res = somar(lucros, 0, 8);
    printf("Intervalo [%d, %d]: Soma = %d\n", res->ini, res->fim, res->soma);
    free(res);
    return 0;
}