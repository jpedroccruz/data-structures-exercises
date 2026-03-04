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

// 12
void exe16() {
  float num1, num2;

  printf("Insira um número: ");
  scanf("%f", &num1);

  printf("Insira outro número: ");
  scanf("%f", &num2);

  clear();

  if (num1 > num2) printf("O número maior é o %.2f", num1);
  else if (num2 > num1) printf("O número maior é o %.2f", num2);
  else printf("Os números são iguais");
}

// 13
void exe17() {
  float numbers[3], higher;

  printf("Insira um número: ");
  scanf("%f", &numbers[0]);

  printf("Insira outro número: ");
  scanf("%f", &numbers[1]);

  printf("Insira outro número: ");
  scanf("%f", &numbers[2]);

  clear();

  higher = numbers[0];
  for (int i = 1; i < 3; i++) {
    if (numbers[i] > higher) higher = numbers[i];
  }

  printf("O maior número é o %.2f", higher);
}

// 14
void exe18() {
  float numbers[4], higher, lower;
  int i, positive = 0, negative = 0;

  for (i = 0; i < 4; i++) {
    printf("Insira um número: ");
    scanf("%f", &numbers[i]);

    if (numbers[i] > 0) positive++;
    else if (numbers[i] < 0) negative++;

    printf("\n");
  }

  clear();

  higher = numbers[0];
  lower = numbers[0];

  for (int i = 1; i < 3; i++) {
    if (numbers[i] > higher) higher = numbers[i];
    else if (numbers[i] < lower) lower = numbers[i]; 
  }

  printf("O maior número é o %.2f\n", higher);
  printf("O menor número é o %.2f\n", lower);
  printf("Quantidade de números positivos: %d\n", positive);
  printf("Quantidade de números negativos: %d", negative);
}

// 15
void exe19() {
  int A, B, C, aux_var;
  
  printf("Insira um valor para A: ");
  scanf("%d", &A);

  printf("Insira um valor para B: ");
  scanf("%d", &B);

  printf("Insira um valor para C: ");
  scanf("%d", &C);

  clear();

  if (A > B) {
    aux_var = A;
    A = B;
    B = aux_var;
  }   

  if (B > C) {
    aux_var = B;
    B = C;
    C = aux_var;
  }

  if (A > B) {
    aux_var = A;
    A = B;
    B = aux_var;
  }   

  printf("A = %d, B = %d, C = %d", A, B, C);
}

// 16
void exe20() {
  int x, y;

  printf("Insira o valor de X: ");
  scanf("%d", &x);

  printf("Insira o valor de Y: ");
  scanf("%d", &y);

  clear();

  if (x > 0 && y > 0) printf("Quadrante 1");
  else if (x < 0 && y > 0) printf("Quadrante 2");
  else if (x < 0 && y < 0) printf("Quadrante 3");
  else if (x > 0 && y < 0) printf("Quadrante 4");
  else printf("Não está em nenhum quadrante específico.");
}

// 17
void exe21() {
  float distance, litres, consume;

  printf("Insira a distância (em km): ");
  scanf("%f", &distance);

  printf("Insira a quantidade de litros de gasolina consumidos: ");
  scanf("%f", &litres);

  consume = distance/litres;

  clear();

  if (consume < 8) printf("Venda o carro!");
  else if (consume >= 8 && consume <= 14) printf("Econômico!");
  else printf("Super econômico");
}

// 18
void exe22() {
  int age;

  printf("Insira sua idade: ");
  scanf("%d", &age);

  clear();

  if (age >= 5 && age <=10) printf("INFANTIL");
  else if (age >= 11 && age <= 15) printf("JUVENIL");
  else if (age >= 16 && age <= 20) printf("JÚNIOR");
  else if (age >= 21 && age <= 25) printf("PROFISSIONAL");
}

// 19
void exe23() {
  float grade;
  int fouls;

  printf("Insira sua nota: ");
  scanf("%f", &grade);

  printf("Quantas faltas você possui? ");
  scanf("%d", &fouls);

  clear();

  printf("Sua nota é: ");

  if (grade >= 9 && grade <= 10) {
    if (fouls > 20) printf("B");
    else printf("A");
  } else if (grade >= 7.5 && grade < 9) {
    if (fouls > 20) printf("C");
    else printf("B");
  } else if (grade >= 5 && grade < 7.5) {
    if (fouls > 20) printf("D");
    else printf("C");
  } else if (grade >= 4 && grade < 5) {
    if (fouls > 20) printf("E");
    else printf("D");
  } else if (grade >= 0 && grade < 4) {
    if (fouls > 20) printf("E");
    else printf("E");
  }
}

void exe24() {
  int age, timeWorked;

  printf("Insira a sua idade: ");
  scanf("%d", &age);

  printf("Insira quanto tempo de serviço você tem: ");
  scanf("%d", &timeWorked);

  if (age >= 65 || timeWorked >= 30 || (age >= 60 && timeWorked >= 25)) printf("Pode aposentar");
  else printf("Não pode aposentar");
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

    case 16:
      exe16();
      break;

    case 17:
      exe17();
      break;

    case 18:
      exe18();
      break;

    case 19:
      exe19();
      break;

    case 20:
      exe20();
      break;

    case 21:
      exe21();
      break;

    case 22:
      exe22();
      break;

    case 23:
      exe23();
      break;

    case 24:
      exe24();
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