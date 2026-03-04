#include <stdio.h>

int isPrime(int num) {
  if (num % 2 == 0) return 0;

  for (int i = num - 1; i >= 3; i -= 2) if (num % i == 0) return 0;

  return 1;
}

void main() {
  int num = 5000, array[20], i = 0;

  while (i < 20) {
    if (isPrime(num)) array[i++] = num;

    num++;
  }

  printf("Lista dos 20 primeiros números primos começando pelo 5000: ");

  for (i = 0; i < 20; i++) {
    printf("%d ", array[i]);
  }
  
  printf("\n");
}