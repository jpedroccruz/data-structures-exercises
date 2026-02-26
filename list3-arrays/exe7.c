#include <stdio.h>

void main() {
  int fristGrades[100], secondGrades[100], mediumGrades[100], i = 0;
  
  while (1) {
    printf("Insira a nota da primeira prova (-1 para parar): ");
    scanf("%d", &fristGrades[i]);

    if (fristGrades[i] == -1) break; 

    printf("Insira a nota da segunda prova: ");
    scanf("%d", &secondGrades[i]);

    mediumGrades[i] = (fristGrades[i] + secondGrades[i]) / 2;

    if (mediumGrades[i] >= 6) printf("APROVADO!\n");
    else printf("REPROVADO!\n");

    i++;
  }
}