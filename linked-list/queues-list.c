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

// 5
void enqueue(Node **begin, Node **end, int value) {
  Node *newNode = malloc(sizeof(Node));
  newNode->value = value;
  newNode->next = NULL;
  
  if (*begin == NULL) {
    *begin = newNode;
    *end = newNode;
    return;
  }

  (*end)->next = newNode;
  *end = newNode;
}

// 6
void dequeue(Node **begin) {
  if (*begin == NULL) return;
  Node *deleted = *begin;
  *begin = deleted->next;
  free(deleted);
}

int main() {
  // 2
  Node *begin;
  Node *end;

  initQueue(&begin, &end);

  enqueue(&begin, &end, 1);
  enqueue(&begin, &end, 2);
  dequeue(&begin);

  // if (!isQueueEmpty(begin)) printf("A fila não está vazia.");
}