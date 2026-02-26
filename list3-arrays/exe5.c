#include <stdio.h>

void main() {
  int matrix[3][3] = {
    { 1, 2, 3 },
    { 4, 5, 6 },
    { 7, 8, 9 }
  };

  printf("Matriz: \n");

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }

    printf("\n");
  }

  printf("\nDiagonal principal ao contrário: \n");

  for (int i = 2; i >= 0; i--) {
    for (int j = 2; j >= 0; j--) {
      if (i == j) {
        printf("%d ", matrix[i][j]);
      }
    }
  }
}