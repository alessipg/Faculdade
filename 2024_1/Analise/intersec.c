#include <stdio.h>
#include <stdlib.h>

float *intersec(float coord[][4], int ini, int fim)
{
    //algoritmo feito para tratar apenas coordenadas positivas
    float *result = malloc(sizeof(float) * 4);
    if (ini == fim)
    {
        result[0] = coord[ini][0];
        result[1] = coord[ini][1];
        result[2] = coord[ini][2];
        result[3] = coord[ini][3];
        return result;
    }
    int meio = (ini + fim) / 2;
    float *esq = intersec(coord, ini, meio);
    float *dir = intersec(coord, meio + 1, fim);
    //verifica se alguma das interseções é nula, descartando-a
    if (esq[0] == -1)
    {
        return dir;
    }
    if (dir[0] == -1)
    {
        return esq;
    }
    //verifica se há interseção
    if (dir[0] > esq[2] || dir[2] < esq[0] || dir[3] > esq[1] || dir[1] < esq[3])
    {
        result[0] = -1;
        result[1] = -1;
        result[2] = -1;
        result[3] = -1;
        free(esq);
        free(dir);
        return result;
    }
    printf("%.1f %.1f %.1f %.1f\n",esq[0], esq[1], esq[2],esq[3]);
    printf("%.1f %.1f %.1f %.1f\n", dir[0], dir[1], dir[2], dir[3]);
    //define as novas coordenadas 
    if (esq[0] > dir[0])
    {
        result[0] = esq[0];
    }
    else
    {
        result[0] = dir[0];
    }
    if (esq[1] < dir[1])
    {
        result[1] = esq[1];
    }
    else
    {
        result[1] = dir[1];
    }
    if (esq[2] < dir[2])
    {
        result[2] = esq[2];
    }
    else
    {
        result[2] = dir[2];
    }
    if (esq[3] > dir[3])
    {
        result[3] = esq[3];
    }
    else
    {
        result[3] = dir[3];
    }
    if(result[0]==result[2]|| result[1]==result[3]){
        result[0] = -1;
        result[1] = -1;
        result[2] = -1;
        result[3] = -1;
        free(esq);
        free(dir);
        return result;
    }
    free(esq);
    free(dir);
    return result;
}

void main()
{
    float coord[3][4] = {{2,5,8,1}, {7,4,10,2}, {8,3,10,0.5}};
    float *res = intersec(coord, 1, 2);
    printf("Resultado: (%.1f,%.1f,%.1f,%.1f)\n", res[0], res[1], res[2], res[3]);
}