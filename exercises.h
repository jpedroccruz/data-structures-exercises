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
  printf("Cidade natal: Cachoeiro de Itapemirim");
}

void exe2() {
  printf("Nome: João Pedro\n");
  printf("Idade: 19 anos\n");
  printf("Altura: 1,61m");
}

void exe3() {
  float number = 75.763289;

  printf("Número com 1 casa decimal: %.1f\n", number);
  printf("Número com 2 casas decimais: %.2f\n", number);
  printf("Número com 5 casas decimais: %.5f", number);
}


void exe4() {
  float height;

  printf("Insira sua altura: ");
  scanf("%f", &height);

  clear();

  printf("Sua altura é: %.2fm", height);
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