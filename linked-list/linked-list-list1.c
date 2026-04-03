#include <stdio.h>
#include <stdlib.h>

// 1
typedef struct Node {
  int info;
  struct Node *next;
} Node;

// 2
void initList(Node **begin) {
  *begin = NULL;
}

// 3
int isListEmpty(Node *begin) {
  if (begin == NULL) return 1;
  return 0;
}

// 4
void addElementInList(Node **begin, int info) {
  Node *n = malloc(sizeof(Node));
  n->info = info;
  n->next = *begin;
  *begin = n;
}

// 5
void printListElements(Node *begin) {
  if (isListEmpty(begin)) {
    printf("Não existe elementos na lista.");
    return;
  }

  printf("Elementos: ");
  for (Node *n = begin; n != NULL; n = n->next) {
    printf("%d", n->info);
    if (n->next != NULL) printf("%c", ',');
  }
}

// 6
int listLength(Node *begin) {
  int length = 0;
  for (Node *n = begin; n != NULL; n = n->next) length++;
  return length;
}

// 7
int isValueOnList(Node *begin, int element) {
  for (Node *n = begin; n != NULL; n = n->next) 
    if (n->info == element) return 1;

  return 0;
}

int main(void) {
  Node *begin;
  initList(&begin);

  if (isListEmpty(begin)) printf("Lista vazia\n");

  addElementInList(&begin, 1);
  addElementInList(&begin, 2);
  addElementInList(&begin, 3);

  printListElements(begin);

  printf("\nTamanho da lista: %d", listLength(begin));

  int element;
  printf("\nInsira um elemento para saber se ele está na lista: ");
  scanf("%d", &element);

  if (isValueOnList(begin, element)) printf("\nO valor %d existe", element);
  else printf("O valor %d não existe", element);
}