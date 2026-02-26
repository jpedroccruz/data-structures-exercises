#include <stdio.h>

void main() {
  int matrix[5][2], array[10], i, j;

  for (i = 0; i < 5; i++) {
    for (j = 0; j < 2; j++) {
      printf("Insira um número para a posição [%d][%d]: ", i, j);
      scanf("%d", &matrix[i][j]);
      printf("\n");
    }
  }
  
  int k = 0;

  for (i = 0; i < 5; i++) {
    for (j = 0; j < 2; j++) {
      array[k] = matrix[i][j];
      k++; 
    }
  }

  printf("Vetor preenchido: ");

  for (i = 0; i < 10; i++) {
    printf("%d ", array[i]);
  }
}