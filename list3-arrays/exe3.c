#include <stdio.h>
#include <stdlib.h>

int veryfiId(int id, int *array, int n) {
  for (int i = 0; i < n; i++) if (id == array[i]) return 1;

  return 0;
}

void main() {
  int n, aux_var, i;

  printf("Insira a quantidade de alunos que vão ser inseridos: ");
  scanf("%d", &n);

  int *array = calloc(sizeof (int), n);

  for (i = 0; i < n; i++) {
    do {
      printf("Insira o número de matrícula do aluno %d: ", i + 1);
      scanf("%d", &aux_var);
    } while (veryfiId(aux_var, array, n) == 1);

    array[i] = aux_var;
  }
}