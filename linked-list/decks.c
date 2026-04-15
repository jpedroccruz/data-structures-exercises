#include <stdio.h>
#include <stdlib.h>

// FIFO + FILO = DECKS (Double-Ended Queues)

typedef struct Node {
  int item;
  struct Node *next;
} Node;

void frontPush(Node **begin, int item) {
  Node *n = malloc(sizeof(Node));
  n->item = item;
  n->next = *begin;
  *begin = n;
}

void backPush(Node **begin, int item) {
  Node *n = malloc(sizeof(Node));
  n->item = item;
  n->next = NULL;
  
  if (*begin == NULL) {
    *begin = n;
    return;
  }

  Node *last = *begin;
  while (last->next != NULL) last = last->next;
  last->next = n;
}

void frontPop(Node **begin) {
  if (*begin == NULL) return;
  Node *deleted = *begin;
  *begin = (*begin)->next;
  free(deleted);
}

void backPop(Node **begin) {
  if (*begin == NULL) return;
  Node *penult = *begin;
  
  if (penult->next == NULL) {
    *begin = NULL;
    return;
  }

  while (penult->next->next != NULL) penult = penult->next;
  Node *deleted = penult->next;
  penult->next = NULL;
  free(deleted);
}

void print(Node *begin) {
  for (Node *n = begin; n != NULL; n = n->next) {
    printf("Item: %d\n", n->item); 
  }
} 

int main(void) {
  Node *begin = NULL;
  
  printf("Inserir 1 no final: \n");
  backPush(&begin, 1);
  printf("Inserir 2 no final: \n");
  backPush(&begin, 2);

  printf("Inserir 3 no começo: \n");
  frontPush(&begin, 3);
  printf("Inserir 4 no começo: \n");
  frontPush(&begin, 4);

  printf("\n");

  print(begin);

  printf("\n");

  printf("Excluir no final: \n");
  backPop(&begin);
  print(begin);

  printf("Excluir no começo: \n");
  frontPop(&begin);
  print(begin);

  printf("Excluir no final: \n");
  backPop(&begin);
  print(begin);

  printf("Excluir no começo: \n");
  frontPop(&begin);
  print(begin);
}