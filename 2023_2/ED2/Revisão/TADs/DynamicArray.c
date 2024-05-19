#include <stdlib.h>
#include <stdio.h>
#include "DynamicArray.h"

DynamicArray *criarArray()
{
    DynamicArray *array = malloc(sizeof(DynamicArray));
    if (!array)
    {
        printf("Erro! Memoria insuficiente\n");
        return NULL;
    }
    array->alunos = malloc(sizeof(Aluno));
    if (!array->alunos)
    {
        printf("Erro! Memoria insuficiente\n");
        return NULL;
    }
    array->alunos = NULL;
    array->capacidade = 1;
    array->i = 0;
    return array;
}

void insereAluno(DynamicArray *array, Aluno *aluno)
{
    if(array->alunos+array->i !=  NULL){
        dobraArray(array);
    }
        array->alunos = aluno;
        array->i++;
    

}
DynamicArray *dobraArray(DynamicArray *array)
{
    array->alunos = realloc(array->alunos, (sizeof(Aluno) * array->capacidade) * 2);
    array->capacidade *= 2;
    while(1);
}
