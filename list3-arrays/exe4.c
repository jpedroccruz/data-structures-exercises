#include <stdio.h>

void main() {
  int array[100], i = 0, aux_var;

  while (i < 100) {
    printf("Insira um número inteiro (999 para parar): ");
    scanf("%d", &aux_var);

    if (aux_var == 999) break;

    array[i] = aux_var;
    i++;
  }

  printf("Array na ordem reversa: ");

  for (--i; i >= 0; i--) {
    printf("%d ", array[i]);
  }
}