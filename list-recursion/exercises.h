#ifndef EXERCISES_H
#define EXERCISES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pause() {
  getchar();
  printf("\n\nPrecione uma tecla para continuar...");
  getchar();
}

void clear() {
  system("clear");
}

// 9
void exe1_recursive(int num) {
  if (num == 0) return;

  int lastDigit = num % 10; 
  printf("%d", lastDigit);

  exe1_recursive(num / 10);
}

void exe1() {
  int num;

  printf("Insira um número: ");
  scanf("%d", &num);

  clear();

  printf("O número %d ao contrário fica: ", num);
  exe1_recursive(num);
}

// 16
int exe2_recursive(int matrix[][2], int i, int j) {
  if (i == 2) return 0;
  if (j == 2) return exe2_recursive(matrix, i + 1, 0);

  return matrix[i][j] + exe2_recursive(matrix, i, j + 1);
}

void exe2() {
  int matrix[2][2], i, j;

  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      printf("Insira um valor para [%d][%d]: ", i, j);
      scanf("%d", &matrix[i][j]);
    }
  }

  clear();

  printf("A soma dos elementos da matriz é: %d", exe2_recursive(matrix, 0, 0));
}

// 17
void exe3() {
 
}

// 23
void exe4() {

}

// 26
void exe5() {

}

// 40
void exe6() {

}

void exercices(int option) {
  clear();

  switch (option) {
    case 0:
      printf("Você saiu do programa.");
      break;

    case 1:
      exe1();
      break;

    case 2:
      exe2();
      break;

    case 3:
      exe3();
      break;

    case 4:
      exe4();
      break;
    
    case 5:
      exe5();
      break;

    case 6:
      exe6();
      break;

    default:
      printf("Opção inválida!");
      break;
  }

  pause();
}

void menu(int qtdExercises) {
  int option;

  do {
    clear();

    printf("========== EXERCÍCIOS LISTA DE STRINGS - ESTRUTURA DE DADOS ==========\n\n");
    printf("[ 0 ] SAIR\n");

    for (int i = 1; i <= qtdExercises; i++) {
      printf("[ %d ] EXERCÍCIO %d\n", i, i);
    }

    printf("\n-------------------------------------------------------------------\n");

    printf("|> Insira o número de um exercícios (0 para sair): ");
    scanf("%d", &option);

    exercices(option);
  } while (option != 0); 
}

#endif