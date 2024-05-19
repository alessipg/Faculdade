/*
 * Nome: Gabriel Alessi Posonski
 * RA: 2259583
 * Atividade Prática 1 - ED2
 * Utilizado o código disponibilizado, alterado apenas a função destruirNodo();
 * Instruções: primeiramente, é necessário possuir um arquivo in.txt no diretório do programa, este deve conter
 * o seguinte formato: 
 * i 10
 * i 20
 * i 30
 * r 20
 * 
 * onde i são números a serem inseridos na árvore e r números a serem removidos. Caso deseje excluir um número inexistente
 * na árvore, a árvore inteira se tornará nula.
 * Para compilar, utilizar:
 * gcc ArvoreBB.c Nodo.c OpES.c main.c -o exe
 * ./exe
 * 
 * 
 * Obs: Função de existeChave(retorno true ou false) localizada em ArvoreBB.c
 */

#include <stdio.h>
#include "ArvoreBB.h"
#include "OpES.h"

/*
 * Funçao para imprimir o arquivo de saida
 * Parâmetro: raiz - nodo raiz da arvore a ser impressa
 * Parâmetro: out - arquivo de saida
 * Obs: optei por deixar a funcao aqui por se tratar de somente 1 função
 * necessaria para manipular os arquivos.
 */
void escreverArquivo(Nodo *raiz, FILE *out)
{
    if (raiz != NULL)
    {
        escreverArquivo(raiz->esquerda, out);
        fprintf(out, "%d\n", raiz->chave);
        escreverArquivo(raiz->direita, out);
    }
}

int main()
{
    Nodo *raiz = criarAVL();
    FILE *in = fopen("in.txt", "r");
    char operador;
    int chave;

    if (in == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    while (fscanf(in, " %c %d", &operador, &chave) == 2)
    {
        if (operador == 'i')
        {
            raiz = inserirChave(raiz, chave);
        }
        else if (operador == 'r')
        {
            raiz = removerChave(raiz, chave);
        }
        else
        {
            printf("Erro: operacao invalida");
        }
    }
    fclose(in);
    FILE *out = fopen("out.txt", "w");
    escreverArquivo(raiz, out);
    printf("Arquivo gerado com sucesso\n");
    fclose(out);

    destruirAVL(raiz);

}