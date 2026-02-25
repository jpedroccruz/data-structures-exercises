#ifndef EXERCISES_H
#define EXERCISES_H

#include <stdio.h>
#include <stdlib.h>

void pause() {
  getchar();
  printf("\n\nPrecione uma tecla para continuar...");
  getchar();
}

void exe1() {
  printf("Hello World!");
  pause();
}

void exercices(int option) {
  system("clear");

  switch (option) {
    case 0:
      break;

    case 1:
      exe1();
      break;

    default:
      printf("Opção inválida!");
      break;
  }
}

void menu(int qtdExercises) {
  int option;

  do {
    system("clear");

    printf("========== EXERCÍCIOS LISTA 1 - ESTRUTURA DE DADOS ==========\n\n");
    printf("[ 0 ] SAIR\n");

    for (int i = 1; i <= qtdExercises; i++) {
      printf("[ %d ] EXERCÍCIO %d\n");
    }

    printf("\n-------------------------------------------------------------\n");

    printf("|> Insira o número de um exercícios (0 para sair): ");
    scanf("%d", &option);

    exercices(option);
  } while (option != 0); 
}

#endif