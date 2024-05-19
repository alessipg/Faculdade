//Exemplo de uso da funcao SHA256 da biblioteca Open SSL
// Este código requer a instalação do pacote libssl-dev 
// Para compilar este código use gcc hash.c -lcrypto

#include "openssl/crypto.h" //arquivo de definição necessário para SHA256_DIGEST_LENGTH
#include "openssl/sha.h" //arquivo de definição necessário função SHA256
#include <string.h>

void printHash(unsigned char hash[], int length)
{
  int i;
  for(i=0;i<length;++i)
    printf("%02x", hash[i]);

  printf("\n");
}
 

int main(int argc, char *argv[])
{
 
  unsigned char letra1 = 53;
  unsigned char letra2 = '5';
  unsigned char codigo1[SHA256_DIGEST_LENGTH];
  unsigned char codigo2[SHA256_DIGEST_LENGTH];

  //calculando hash do dado contido em letra1
  SHA256((unsigned char *) &letra1, sizeof(letra1), codigo1);
  printf("O hash do valor inteiro 5 de 1 byte é\n");
  printHash(codigo1, SHA256_DIGEST_LENGTH);

  //calculando hash do dado contido em letra1
  SHA256((unsigned char *) &letra2, sizeof(letra2), codigo2);
  printf("O hash do caracter ASCII 5 %d de 1 byte é\n",letra2);
  printHash(codigo2, SHA256_DIGEST_LENGTH);


  int valor;
  printf("Informe o valor inteiro cujo hash deseja calcular\n");
   scanf("%d", &valor);//le white spaces

  unsigned char hash[SHA256_DIGEST_LENGTH];//vetor que armazenará o resultado do hash. Tamanho definidio pela libssl 

  //A funcao SHA256 requer tres parametros
  //1. o ponteiro para um vetor de unsigned char contendo o dado cujo hash você deseja calcular
  //2. o tamanho em bytes do dado cujo hash você deseja calcular
  //3. o ponteiro para um vetor de unsigned char que armazenará o resultado do hash calculado.
  SHA256((unsigned char *)&valor, sizeof(valor), hash);
  printHash(hash, SHA256_DIGEST_LENGTH);
  return 0;
}





