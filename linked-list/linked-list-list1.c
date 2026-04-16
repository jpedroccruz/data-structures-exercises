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
void frontPush(Node **begin, int info) {
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
void backPush(Node **begin, int item) {
  Node *n = malloc(sizeof(Node));
  n->info = item;
  n->next = NULL;

  if (*begin == NULL) {
    *begin = n;
    return;
  }

  Node *last = *begin;
  while (last->next != NULL) last = last->next;
  last->next = n; 
}

// 7
int listLength(Node *begin) {
  int length = 0;
  for (Node *n = begin; n != NULL; n = n->next) length++;
  return length;
}

// 8
int isValueOnList(Node *begin, int element) {
  for (Node *n = begin; n != NULL; n = n->next) 
    if (n->info == element) return 1;

  return 0;
}

// 9
int getHighierValue(Node *begin) {
  int highier = begin->info;

  for (Node *n = begin; n != NULL; n = n->next) {
    if (n->info > highier) highier = n->info;
  }

  return highier;
}

int main(void) {
  Node *begin;
  initList(&begin);

  if (isListEmpty(begin)) printf("Lista vazia\n");

  frontPush(&begin, 1);
  frontPush(&begin, 2);
  frontPush(&begin, 3);

  printListElements(begin);

  backPush(&begin, 4);

  printf("\nTamanho da lista: %d", listLength(begin));

  int element;
  printf("\nInsira um elemento para saber se ele está na lista: ");
  scanf("%d", &element);

  if (isValueOnList(begin, element)) printf("\nO valor %d existe", element);
  else printf("O valor %d não existe", element);

  printf("\nO maior valor da lista é: %d", getHighierValue(begin));
}