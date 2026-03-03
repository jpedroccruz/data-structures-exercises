#include <stdio.h>
#include <stdlib.h>

void main() {
  int array[10], i, oddNumbersSum = 0;
  
  for (i = 0; i < 10; i++) {
    printf("Insira um número inteiro: ");
    scanf("%d", &array[i]);

    system("clear");
  }

  for (i = 0; i < 10; i++) {
    if (array[i] % 2 != 0) oddNumbersSum += array[i];
  }

  printf("A soma de todos os números ímpares do vetor é: %d", oddNumbersSum);
}