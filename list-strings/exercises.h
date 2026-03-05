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

int minha_strcmp(char str1[], char str2[]) {
  int i = 0;

  while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0') {
    i++;
  }

  return str1[i] - str2[i];
}

// 5
void exe1() {
  char word1[30], word2[30];

  printf("Insira uma palavra: ");
  scanf(" %29[^\n]", word1);

  printf("Insira outra palavra: ");
  scanf(" %29[^\n]", word2);

  clear();

  if (minha_strcmp(word1, word2) == 0) printf("As palavras iguais");
  else if (minha_strcmp(word1, word2) > 0) printf("A palavra %s é lexicograficamente 'maior' que a palavra %s", word1, word2);
  else printf("A palavra %s é lexicograficamente 'maior' que a palavra %s", word2, word1);
}

// 6
void exe2() {
  char str[50];
  int i = 0, j = 0;

  printf("Insira uma frase qualquer: ");
  scanf(" %49[^\n]", str);

  while (str[i] != '\0') {
    if (str[i] == ' ' && str[i + 1] == ' ') i++;
    else {
      str[j] = str[i];
      i++;
      j++;
    }
  }

  str[j] = '\0';

  printf("String formatada: %s", str);
}

// 8
void exe3() {
  char str[50];

  printf("Insira uma frase separando as palavras por vírgula (,): ");
  scanf(" %49[^\n]", str);

  clear();

  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == ',') printf("\n");
    else printf("%c", str[i]);
  }
}

// 9
void exe4() {
  
}

// 10
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