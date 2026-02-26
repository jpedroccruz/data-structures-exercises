#include <stdio.h>

void main() {
  int array[10];

  int i = 0;

  for (; i < 10; i++) {
    printf("Insira um número: ");
    scanf("%d", &array[i]);
    printf("\n");
  }
  
  printf("Array na ordem reversa: ");

  for (i = 9; i >= 0; i--) {
    printf("%d ", array[i]);
  }
}