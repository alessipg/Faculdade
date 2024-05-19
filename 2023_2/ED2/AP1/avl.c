#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int chave;               // Chave que identifica o nodo.
    
    struct No* direita;      // Ponteiro para o filho da direita.
    struct No* esquerda;     // Ponteiro para o filho da esquerda.
} Nodo;