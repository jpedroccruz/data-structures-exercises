#include <stdio.h>

int veryfiId(int id, int *array) {
  for (int i = 0; i < 10; i++) if (id == array[i]) return 1;

  return 0;
}

void main() {
  int array[10], aux_var, i;

  for (i = 0; i < 10; i++) {
    do {
      printf("Insira o número de matrícula do aluno %d: ", i + 1);
      scanf("%d", &aux_var);
    } while (veryfiId(aux_var, array) == 1);

    array[i] = aux_var;
  }
}