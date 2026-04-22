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

// 7
int peak(Node *begin) {
  return begin->value;
}

// 8
void printListElements(Node *begin) {
  if (isQueueEmpty(begin)) {
    printf("Não existe elementos na lista.");
    return;
  }

  printf("Elementos: ");
  for (Node *node = begin; node != NULL; node = node->next) {
    printf("%d", node->value);
    if (node->next != NULL) printf(",");
  }
}

// 9
int listLength(Node *begin) {
  if (begin == NULL) return 0;
  return 1 + listLength(begin->next);
}

// 10
Node *getNodeByValue(Node *begin, int value) {
  for (Node *node = begin; node != NULL; node = node->next)
    if (node->value == value)
      return node;

  return NULL;
}

// 11
int getPairsQuantity(Node *begin) {
  if (begin == NULL) return 0;
  return (begin->value % 2 == 0 ? 1 : 0) + getPairsQuantity(begin->next);
}

// 12
void clearList(Node **begin) {
  while (*begin != NULL) {
    Node *temp = *begin;
    *begin = (*begin)->next;
    free(temp);
  }
}

int main() {
  // 2
  Node *begin;
  Node *end;

  initQueue(&begin, &end);

  enqueue(&begin, &end, 1);
  enqueue(&begin, &end, 2);
  enqueue(&begin, &end, 3);
  enqueue(&begin, &end, 4);
  dequeue(&begin);

  clearList(&begin);

  printListElements(begin);
  printf("Quantidade de elementos pares: %d", getPairsQuantity(begin));
  // if (getNodeByValue(begin, 6) == NULL) printf("O valor 6 não está na lista");
  // printf("Tamanho da lista: %d", listLength(begin));
  //printf("\nPrimeiro elemento: %d", peak(begin));

  // if (!isQueueEmpty(begin)) printf("A fila não está vazia.");
}