#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"
#include "DynamicArray.h"

int main(){
    Aluno *a1 = criarAluno();
    definirNota(a1, 8.7);        
    definirRa(a1, 1204251);
    
    DynamicArray *array = criarArray();
    printf("%d %p", array->alunos, array->alunos);
    
    insereAluno(array, a1);
    
    Aluno *a2 = criarAluno();
    definirNota(a2, 6);
    definirRa(a2, 2260000); 

    insereAluno(array, a2);
    if(a1 != NULL){
        printf("exibindo dados do aluno 1:\n");



        exibirNota(a1);
        exibirRa(a1);

        destruirAluno(a1);
    }
    else{
        printf("Erro: memoria insuficiente\n");
        exit(1);
    }
    if(a2 != NULL){
        printf("exibindo dados do aluno 2:\n");



        exibirNota(a2);
        exibirRa(a2);

        destruirAluno(a2);
    }
    else{
        printf("Erro: memoria insuficiente\n");
        exit(1);
    }
    return 0;
}