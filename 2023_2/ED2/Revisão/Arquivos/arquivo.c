#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char operacao;
    int numero;

    // Abre o arquivo para leitura
    file = fopen("in.txt", "r");

    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Lê e processa cada linha do arquivo
    while (fscanf(file, " %c %d", &operacao, &numero) == 2) {
        if (operacao == 'i') {
            printf("Número inserido: %d\n", numero);
        } else if (operacao == 'r') {
            printf("Número removido: %d\n", numero);
        } else {
            printf("Operação desconhecida: %c\n", operacao);
        }
    }

    // Fecha o arquivo
    fclose(file);

    return 0;
}
