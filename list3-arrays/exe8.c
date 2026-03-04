#include <stdio.h>

int isPrime(int num) {
  for (int i = num - 1; i >= 2; i--) { 
    if (num % i == 0) return 0;
  }

  return 1;
}

void main() {
  int num = 5000, array[10], i = 0;

  while (i < 10) {
    if (isPrime(num)) {
      array[i] = num;
      i++;
    } 

    num++;
  }

  printf("Lista dos 20 primeiros números primos começando pelo 5000: ");

  for (i = 0; i < 10; i++) {
    printf("%d ", array[i]);
  }
}