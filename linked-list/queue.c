#include <stdio.h>
#include <stdlib.h>

// FIFO - First In First Out

typedef struct Node {
  int item;
  struct Node *next;
  struct Node *prev;
} Node;

void enqueue(Node **begin, Node **end, int item) {
  Node *n = malloc(sizeof(Node));
  n->item = item;
  n->prev = *end;
  n->next = NULL;
  
  if (*begin == NULL) {
    *begin = n;
    *end = n;
    return;
  }

  (*end)->next = n;
  *end = n;
}

void dequeue(Node **begin) {
  if (*begin == NULL) return;
  Node *deleted = *begin;
  *begin = (*begin)->next;
  free(deleted);
}

void print(Node *begin) {
  for (Node *n = begin; n != NULL; n = n->next) {
    printf("Item: %d\n", n->item); 
  }
} 

int main(void) {
  Node *begin = NULL;
  Node *end = NULL;

  enqueue(&begin, &end, 1);
  enqueue(&begin, &end, 2);
  enqueue(&begin, &end, 3);

  printf("Primeira impressão: \n");
  print(begin);

  dequeue(&begin);

  printf("\nSegunda impressão: \n");
  print(begin);

  dequeue(&begin);

  printf("\nTerceira impressão: \n");
  print(begin);

  dequeue(&begin);

  printf("\nQuarta impressão: \n");
  enqueue(&begin, &end, 10);
  print(begin);
}