#include <stdio.h>
#include <stdlib.h>

void main() {
  int n;

  printf("Insira o tamanho do array: ");
  scanf("%d", &n);

  int *array = calloc(sizeof (int), n);

  int i = 0;

  for (; i < n; i++) {
    printf("Insira um número: ");
    scanf("%d", &array[i]);
    printf("\n");
  }
  
  printf("Array na ordem reversa: ");

  for (i = n - 1; i >= 0; i--) {
    printf("%d ", array[i]);
  }
}