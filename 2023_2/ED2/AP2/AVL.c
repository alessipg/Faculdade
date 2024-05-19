#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct No
{
    int chave;
    int alturaDireita;  // Altura a direita para calculo do fator de balanceamento (FB)
    int alturaEsquerda; // Altura a esquerda para calculo do fator de balanceamento (FB)
    struct No *direita;
    struct No *esquerda;
} Nodo;

Nodo *criarNodo(int chave);
Nodo *inserir(Nodo *arvore, int chave);
int buscar(Nodo *arvore, int chave, int *comparacoes);
int maximo(int a, int b);
int calcularAltura(Nodo *nodo);
int fatorBalanceamento(Nodo *nodo);
Nodo *rotacaoDireita(Nodo *y);
Nodo *rotacaoEsquerda(Nodo *x);

int main()
{
    Nodo *arvore = NULL;
    int valor;
    char tipo;
    int comparacoes = 0;
    clock_t inicio, fim;
    double tempo_execucao;

    FILE *entrada, *entrada1, *entrada2;

    entrada = fopen("in1.txt", "r");
    entrada1 = fopen("in2.txt", "r");
    entrada2 = fopen("in3.txt", "r");

    if (entrada == NULL || entrada1 == NULL || entrada2 == NULL)
    {
        printf("Erro ao abrir os arquivos.\n");
        system("pause");
        return 0;
    }

    printf("--------AVL--------\n");

    // Medindo o tempo de execução para a primeira entrada
    inicio = clock();
    while (fscanf(entrada, "%c %d", &tipo, &valor) != EOF)
    {
        if (tipo == 'i')
        {
            arvore = inserir(arvore, valor);
        }
        else if (tipo == 'b')
        {
            int resultado = buscar(arvore, valor, &comparacoes);
            
            if (resultado == 0)
            {
                printf("Chave nao encontrada.\n");
            }
    
        }
    }
    fim = clock();
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao (in1.txt): %.3f segundos\n", tempo_execucao);
    printf("Total de comparacoes: %d\n", comparacoes); // Imprimindo o total de comparações
    fclose(entrada);

    // Repetindo o processo para a segunda entrada
    arvore = NULL;
    comparacoes = 0;
    inicio = clock();
    while (fscanf(entrada1, "%c %d", &tipo, &valor) != EOF)
    {
        if (tipo == 'i')
        {
            arvore = inserir(arvore, valor);
        }
        else if (tipo == 'b')
        {
            int resultado = buscar(arvore, valor, &comparacoes);
            if (resultado == 0)
            {
                printf("Chave nao encontrada.\n");
            }
            
        }
    }
    fim = clock();
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao (in2.txt): %.3f segundos\n", tempo_execucao);
    printf("Total de comparacoes: %d\n", comparacoes);
    fclose(entrada1);

    // Repetindo o processo para a terceira entrada
    arvore = NULL;
    comparacoes = 0;
    inicio = clock();
    while (fscanf(entrada2, "%c %d", &tipo, &valor) != EOF)
    {
        if (tipo == 'i')
        {
            arvore = inserir(arvore, valor);
        }
        else if (tipo == 'b')
        {
            int resultado = buscar(arvore, valor, &comparacoes);
            if (resultado == 0)
            {
                printf("Chave nao encontrada.\n");
            }
        }
    }
    fim = clock();
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao (in3.txt): %.3f segundos\n", tempo_execucao);
    printf("Total de comparacoes: %d\n", comparacoes); // Imprimindo o total de comparações
    fclose(entrada2);

    return 0;
}

Nodo *criarNodo(int chave)
{
    Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
    nodo->chave = chave;
    nodo->alturaDireita = 0;
    nodo->alturaEsquerda = 0;
    nodo->esquerda = NULL;
    nodo->direita = NULL;
    return nodo;
}

int calcularAltura(Nodo *nodo)
{
    if (nodo == NULL)
    {
        return 0;
    }
    return 1 + maximo(calcularAltura(nodo->esquerda), calcularAltura(nodo->direita));
}

int maximo(int a, int b)
{
    return (a > b) ? a : b;
}

int fatorBalanceamento(Nodo *nodo)
{
    if (nodo == NULL)
    {
        return 0;
    }
    return calcularAltura(nodo->esquerda) - calcularAltura(nodo->direita);
}

Nodo *rotacaoDireita(Nodo *y)
{
    Nodo *x = y->esquerda;
    Nodo *T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    y->alturaEsquerda = maximo(calcularAltura(y->esquerda), calcularAltura(y->direita)) + 1;
    x->alturaDireita = maximo(calcularAltura(x->esquerda), calcularAltura(x->direita)) + 1;

    return x;
}

Nodo *rotacaoEsquerda(Nodo *x)
{
    Nodo *y = x->direita;
    Nodo *T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    x->alturaDireita = maximo(calcularAltura(x->esquerda), calcularAltura(x->direita)) + 1;
    y->alturaEsquerda = maximo(calcularAltura(y->esquerda), calcularAltura(y->direita)) + 1;

    return y;
}

Nodo *inserir(Nodo *arvore, int chave)
{
    if (arvore == NULL)
        return criarNodo(chave);

    if (chave < arvore->chave)
        arvore->esquerda = inserir(arvore->esquerda, chave);
    else if (chave > arvore->chave)
        arvore->direita = inserir(arvore->direita, chave);
    else
        return arvore;

    arvore->alturaEsquerda = calcularAltura(arvore->esquerda);
    arvore->alturaDireita = calcularAltura(arvore->direita);

    int fb = fatorBalanceamento(arvore);

    if (fb > 1 && chave < arvore->esquerda->chave)
        return rotacaoDireita(arvore);
    if (fb < -1 && chave > arvore->direita->chave)
        return rotacaoEsquerda(arvore);
    if (fb > 1 && chave > arvore->esquerda->chave)
    {
        arvore->esquerda = rotacaoEsquerda(arvore->esquerda);
        return rotacaoDireita(arvore);
    }
    if (fb < -1 && chave < arvore->direita->chave)
    {
        arvore->direita = rotacaoDireita(arvore->direita);
        return rotacaoEsquerda(arvore);
    }

    return arvore;
}


int buscar(Nodo *arvore, int chave, int *comparacoes)
{
    if (arvore == NULL)
    {
        (*comparacoes)++;
        return 0;
    }

    if (chave == arvore->chave)
    {
        (*comparacoes)++;
        return chave;
    }

    if (chave < arvore->chave)
    {
        (*comparacoes)++;
        return buscar(arvore->esquerda, chave, comparacoes);
    }
    else
    {
        (*comparacoes)++;
        return buscar(arvore->direita, chave, comparacoes);
    }
}
