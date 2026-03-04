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
  printf("Altura: 1,61 m");
}

void exe3() {
  float number = 75.763289;

  printf("Número com 1 casa decimal: %.1f\n", number);
  printf("Número com 2 casas decimais: %.2f\n", number);
  printf("Número com 5 casas decimais: %.5f", number);
}


void exe4() {
  float height;

  printf("Insira sua altura (em m): ");
  scanf("%f", &height);

  clear();

  printf("Sua altura é: %.2f m", height);
}

void exe5() {
  float weight[3];

  printf("Insira o seu peso (em kg): ");
  scanf("%f", &weight[0]);

  printf("Insira o peso da pessoa 1 (em kg): ");
  scanf("%f", &weight[1]);

  printf("Insira o peso da pessoa 2 (em kg): ");
  scanf("%f", &weight[2]);

  clear();

  printf("Seu peso: %.2f kg\n", weight[0]);
  printf("Peso da pessoa 1: %.2f kg\n", weight[1]);
  printf("Peso da pessoa 2: %.2f kg", weight[2]);
}

void exe6() {
  float radius;

  printf("Insira o raio do círculo para saber a área: ");
  scanf("%f", &radius);

  clear();

  printf("Área do círculo: %.2f", 3.14 * (radius * radius));
}

void exe7() {
  float reals, dollarPrice;

  printf("Insira uma quantidade em reais para saber a correspondência em dólar: ");
  scanf("%f", &reals);

  printf("Insira a cotação atual do dólar: ");
  scanf("%f", &dollarPrice);

  clear();

  printf("R$ %.2f -> US$ %.2f", reals, reals / dollarPrice);
}

void exe8() {
  float total;

  printf("Insira o valor total: $ ");
  scanf("%f", &total);

  clear();

  printf("Total a pagar com desconto de 10%: $ %.2f\n", total * 0.9);
  printf("Valor de cada parcela em 3x sem juros: $ %.2f\n", total / 3);
  printf("Valor da comissão (se a compra for a vista): $ %.2f\n", (total * 0.9) * 0.05);
  printf("Valor da comissão (se a compra for parcelada): $ %.2f\n", total * 0.05);
}

// 8.5
void exe9() {
  int A, B, aux_var;

  printf("Insira um valor para A: ");
  scanf("%d", &A);

  printf("Insira um valor para B: ");
  scanf("%d", &B);

  aux_var = A;
  A = B;
  B = aux_var;

  clear();

  printf("Valor de A: %d\n", A);
  printf("Valor de B: %d", B);
}

// 8.6
void exe10() {
  int num, digits[4];

  printf("Insira um número inteiro: ");
  scanf("%d", &num);

  digits[0] = num / 1000;
  digits[1] = (num % 1000) / 100;
  digits[2] = (num % 100) / 10;
  digits[3] = num % 10;

  for (int i = 0; i < 4; i++) printf("\n%d", digits[i]);
}

// 8.7
void exe11() {
  int seconds, minutes, hours;

  printf("Insira uma quantidade de segundos: ");
  scanf("%d", &seconds);

  minutes = seconds / 60;
  seconds -= 60 * minutes;

  hours = minutes / 60;
  minutes -= 60 * hours;

  clear();

  printf("%02d:%02d:%02d", hours, minutes, seconds);
}

// 8.8
void exe12() {
  float award, bets[3], totalBet, proportionalValue;
  int i;

  printf("Insira o valor do prêmio: ");
  scanf("%f", &award);

  clear();

  for (i = 0; i < 3; i++) {
    printf("Insira quanto o amigo %d apostou: ", i + 1);
    scanf("%f", &bets[i]);

    totalBet += bets[i];

    printf("\n");
  }

  clear();

  for (i = 0; i < 3; i++) {
    proportionalValue = award * (bets[i] / totalBet);

    printf("O amigo %d ganhou: %.2f\n", i + 1, proportionalValue);
  }
}

// 9
void exe13() {
  float num1, num2;

  printf("Insira um número: ");
  scanf("%f", &num1);
  
  printf("Insira outro número: ");
  scanf("%f", &num2);
  
  clear();

  if (num2 == 0) {
    printf("ERRO: Divisão por 0");
    return;
  }

  printf("%.1f / %.1f = %.1f", num1, num2, num1 / num2);
}

// 10
void exe14() {
  float num1, num2;

  printf("Insira um número: ");
  scanf("%f", &num1);
  
  printf("Insira outro número: ");
  scanf("%f", &num2);

  clear();

  if (num1 > 0 && num2 > 0) printf("Valores são válidos");
  else printf("Valores inválidos");
}

// 11
void exe15() {
  float radius;

  printf("Insira o raio do círculo para saber a área: ");
  scanf("%f", &radius);

  clear();

  if (radius < 0) {
    printf("ERRO: Raio negativo");
    return;
  }

  printf("Área do círculo: %.2f", 3.14 * (radius * radius));
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

    case 7:
      exe7();
      break;

    case 8:
      exe8();
      break;

    case 9:
      exe9();
      break;

    case 10:
      exe10();
      break;

    case 11:
      exe11();
      break;

    case 12:
      exe12();
      break;

    case 13:
      exe13();
      break;

    case 14:
      exe14();
      break;

    case 15:
      exe15();
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