#include <stdlib.h>
#include <stdio.h>
#include "Aluno.h"

Aluno *criarAluno(){
    Aluno *aluno = malloc(sizeof(Aluno));
    if(aluno){
        aluno->ra = 0;
        aluno->nota = 0.0;
    }
    return aluno;

}

void destruirAluno(Aluno *aluno){
    free(aluno);
    aluno = NULL;
}

void definirRa(Aluno *aluno, int ra){
    aluno->ra = ra;
}

void definirNota(Aluno *aluno, float nota){
    aluno->nota = nota;
}

void exibirRa(Aluno *aluno){
    printf("ra: %d\n", aluno->ra);
}

void exibirNota(Aluno *aluno){
    printf("nota: %f\n", aluno->nota);
}