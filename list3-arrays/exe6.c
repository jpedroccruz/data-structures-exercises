#include <stdio.h>

void main() {
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, ids[3];

  printf("BUSCAR MATRÍCULAS: \n");
  for (int i = 0; i < 3; i++) {
    printf("Insira uma matrícula: ");
    scanf("%d", &ids[i]);
  }

  printf("\n");

  for (int i = 0; i < 10; i++) {
    if (ids[0] == array[i]) printf("A matricula %d está no vertor.\n", ids[0]);
    else if (ids[1] == array[i]) printf("A matricula %d está no vertor.\n", ids[1]);
    else if (ids[2] == array[i]) printf("A matricula %d está no vertor.\n", ids[2]);
  }
}