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
  printf("Cidade natal: Cachoeiro de Itapemirim");
  pause();
}

void exe2() {
  printf("Nome: João Pedro\n");
  printf("Idade: 19 anos\n");
  printf("Altura: 1,61m");
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

    case 2:
      exe2();
      break;

    default:
      printf("Opção inválida!");
      pause();
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
      printf("[ %d ] EXERCÍCIO %d\n", i, i);
    }

    printf("\n-------------------------------------------------------------\n");

    printf("|> Insira o número de um exercícios (0 para sair): ");
    scanf("%d", &option);

    exercices(option);
  } while (option != 0); 
}

#endif