#ifndef EXERCISES_H
#define EXERCISES_H

#include <stdio.h>
#include <stdlib.h>

void pause() {
  getchar();
  printf("\n\nPrecione uma tecla para continuar...");
  getchar();
}

void clear() {
  system("clear");
}

void exe1() {
  
}

void exe2() {
  
}

void exe3() {
  
}

void exe4() {
  
}

void exe5() {
  
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