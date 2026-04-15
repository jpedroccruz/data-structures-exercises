#include <stdio.h>
#include <stdlib.h>

// FILO - First In Last Out

typedef struct Node {
  int item;
  struct Node *next;
  struct Node *prev;
} Node;

// void push(Node **begin, int item) {
//   Node *n = malloc(sizeof(Node));
//   n->item = item;
//   n->next = *begin;
//   *begin = n;
// }

// void pop(Node **begin) {
//   if (*begin == NULL) return;
//   Node *deleted = *begin;
//   *begin = (*begin)->next;
//   free(deleted);
// }

// void print(Node *begin) {
//   for (Node *n = begin; n != NULL; n = n->next) {
//     printf("Item: %d\n", n->item); 
//   }
// } 

void push(Node **begin, Node **end, int item) {
  Node *n = malloc(sizeof(Node));
  n->item = item;
  n->next = NULL;
  n->prev = *end;

  if (*begin == NULL) {
    *begin = n;
    *end = n;
    return;
  }

  (*end)->next = n;
  *end = n;
}

void pop(Node **begin, Node **end) {
  if (*end == NULL) return;
  Node *deleted = *end;
  *end = (*end)->prev;
  free(deleted);
  if (*end == NULL) *begin = NULL;
}

void print(Node *end) {
  for (Node *n = end; n != NULL; n = n->prev) {
    printf("Item: %d\n", n->item); 
  }
} 

int main(void) {
  Node *begin = NULL;
  Node *end = NULL;

  // push(&begin, 1);
  // push(&begin, 2);
  // push(&begin, 3);

  // printf("Primeira impressão: \n");
  // print(begin);

  // pop(&begin);

  // printf("\nSegunda impressão: \n");
  // print(begin);

  // pop(&begin);

  // printf("\nTerceira impressão: \n");
  // print(begin);

  // pop(&begin);

  // printf("\nQuarta impressão: \n");
  // push(&begin, 10);
  // print(begin);

  push(&begin, &end, 1);
  push(&begin, &end, 2);
  push(&begin, &end, 3);

  printf("Primeira impressão: \n");
  print(end);

  pop(&begin, &end);

  printf("\nSegunda impressão: \n");
  print(end);

  pop(&begin, &end);

  printf("\nTerceira impressão: \n");
  print(end);

  pop(&begin, &end);

  printf("\nQuarta impressão: \n");
  push(&begin, &end, 10);
  print(end);
}