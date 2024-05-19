#ifndef DYNAMICARRAY_H_INCLUDED
#define DYNAMICARRAY_H_INCLUDED

#include "Aluno.h"

typedef struct{
    Aluno* alunos;
    int capacidade;
    int i;
}DynamicArray;

#endif