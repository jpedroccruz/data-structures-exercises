#include <stdio.h>
#include <stdlib.h>

// 1
typedef struct Node {
  int value;
  struct Node *next;
} Node;

// 3
void initQueue(Node **begin, Node **end) {
  *begin = NULL;
  *end = NULL;
}

// 4
int isQueueEmpty(Node *begin) {
  if (begin == NULL) return 1;
  return 0;
}

int main() {
  //2
  Node *begin;
  Node *end;

  initQueue(&begin, &end);

  if (isQueueEmpty(begin)) printf("A fila está vazia.");
}