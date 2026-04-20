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
int getHighestValue(Node *begin) {
  int highier = begin->info;

  for (Node *n = begin; n != NULL; n = n->next) {
    if (n->info > highier) highier = n->info;
  }

  return highier;
}

// 10
int getLowestValue(Node *begin) {
  int lower = begin->info;

  for (Node *n = begin; n != NULL; n = n->next) {
    if (n->info < lower) lower = n->info;
  }

  return lower;
}


// 11
void frontPop(Node **begin) {
  if (*begin == NULL) return;
  Node *deleted = *begin;
  *begin = deleted->next; 
  free(deleted);
}

// 12
void backPop(Node **begin) {
  if (*begin == NULL) return;
  Node *brief = *begin;

  if (brief->next == NULL) {
    free(brief);
    *begin = NULL;
    return;
  }

  while (brief->next->next != NULL) brief = brief->next;
  free(brief->next);
  brief->next = NULL;
}

// 13
void removeItem(Node **begin, int item) {
  if (*begin == NULL) return;  
  Node *n = *begin;

  if (n->info == item) {
    Node *deleted = n;
    *begin = n->next;
    free(deleted);
    return;
  }

  while (n->next != NULL) {
    if (n->next->info == item) {
      Node *deleted = n->next;
      n->next = deleted->next;
      free(deleted);
      return;
    }

    n = n->next;
  }
}

// 14
void removeAllElements(Node **begin) {
  while (*begin != NULL) {
    frontPop(begin);
  }
}

// 15
void removeDuplicates(Node **begin) {
  Node *n = *begin;

  while (n != NULL) {
    Node *m = n;

    while (m->next != NULL) {
      if (n->info == m->next->info) {
        removeItem(&m->next, n->info);
      } else {
        m = m->next;
      }
    }

    n = n->next;
  }
}

// 16
void reverseList(Node **begin) {
  Node *current = *begin;
  Node *next = current->next;
  Node *last = NULL;

  while (current != NULL) {
    next = current->next;
    current->next = last;
    last = current;
    current = next;
  }

  *begin = last;
}

// 17
void joinLists(Node **begin1, Node **begin2) {
  if (*begin1 == NULL) {
    *begin1 = *begin2;
    return;
  }

  Node *last = *begin1;
  while (last->next != NULL) last = last->next;
  last->next = *begin2;
}

// 18
void splitListsByPairOrOdd(Node **begin1, Node **begin2) {
  Node *pair = NULL;
  Node *odd = NULL;

  for (Node *n = *begin1; n != NULL; n = n->next) {
    if (n->info % 2 == 0) backPush(&pair, n->info);
    else backPush(&odd, n->info);
  }

  for (Node *n = *begin2; n != NULL; n = n->next) {
    if (n->info % 2 == 0) backPush(&pair, n->info);
    else backPush(&odd, n->info);
  }

  removeAllElements(begin1);
  removeAllElements(begin2);

  *begin1 = pair;
  *begin2 = odd;
}

int main(void) {
  // Node *begin;
  // initList(&begin);

  // if (isListEmpty(begin)) printf("Lista vazia\n");

  // frontPush(&begin, 1);
  // frontPush(&begin, 2);
  // frontPush(&begin, 3);

  // printListElements(begin);

  // backPush(&begin, 4);

  // printf("\nTamanho da lista: %d", listLength(begin));

  // int element;
  // printf("\nInsira um elemento para saber se ele está na lista: ");
  // scanf("%d", &element);

  // if (isValueOnList(begin, element)) printf("\nO valor %d existe", element);
  // else printf("O valor %d não existe", element);

  // printf("\nO maior valor da lista é: %d", getHighestValue(begin));
  // printf("\nO menor valor da lista é: %d\n", getLowestValue(begin));

  // frontPop(&begin);
  // printListElements(begin);

  // printf("\n");

  // backPop(&begin);
  // printListElements(begin);
  
  // printf("\n");

  // backPush(&begin, 10);
  // backPush(&begin, 20);
  // printListElements(begin);

  // printf("\n");

  // removeItem(&begin, 20);
  // removeItem(&begin, 10);
  // removeItem(&begin, 2);
  // printListElements(begin);

  // printf("\n");

  // backPush(&begin, 10);
  // backPush(&begin, 20);
  // backPush(&begin, 30);
  // printListElements(begin);

  // printf("\n");

  // removeAllElements(&begin);
  // printListElements(begin);

  // printf("\n");

  // backPush(&begin, 10);
  // backPush(&begin, 10);
  // backPush(&begin, 20);
  // backPush(&begin, 20);
  // removeDuplicates(&begin);
  // printListElements(begin);
  // removeAllElements(&begin);

  // printf("\n");
  
  // backPush(&begin, 10);
  // backPush(&begin, 20);
  // backPush(&begin, 30);
  // backPush(&begin, 40);
  // reverseList(&begin);
  // printListElements(begin);
  
  Node *begin1, *begin2;
  initList(&begin1);
  initList(&begin2);

  backPush(&begin1, 1);
  backPush(&begin1, 2);
  backPush(&begin1, 3);
  backPush(&begin2, 4);
  backPush(&begin2, 5);
  backPush(&begin2, 6);

  // joinLists(&begin1, &begin2);

  // printListElements(begin1);  

  splitListsByPairOrOdd(&begin1, &begin2);

  printf("PARES:\n");
  printListElements(begin1);

  printf("\n");

  printf("ÍMPARES:\n");
  printListElements(begin2);
}