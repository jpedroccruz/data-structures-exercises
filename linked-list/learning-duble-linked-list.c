#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int info;
  struct Node *prev;
  struct Node *next;
} Node;

void pushToEnd(int info, Node **begin, Node **end) {
  Node *n = malloc(sizeof(Node));
  n->info = info;
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

void pushToBegin(int info, Node **begin, Node **end) {
  Node *n = malloc(sizeof(Node));
  n->info = info;
  n->next = *begin;
  n->prev = NULL;
  
  if (*begin == NULL) {
    pushToEnd(info, begin, end);
    return;
  }
  
  (*begin)->prev = n;
  *begin = n;
}

int main(void) {
  Node *begin = NULL;
  Node *end = NULL;

  pushToBegin(1, &begin, &end);
  pushToBegin(2, &begin, &end);
  pushToBegin(3, &begin, &end);
  
  printf("Normal: \n");
  for (Node *n = begin; n != NULL; n = n->next) {
    printf("%d ", n->info);
  }

  printf("\n\nReverse: \n");

  for (Node *n = end; n != NULL; n = n->prev) {
    printf("%d ", n->info);
  }

  return 0;
} 