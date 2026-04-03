#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int info;
  struct Node *next;
} Node;

// typedef struct Node {
//   int info;
//   struct Node *next;
//   void (*startPush) (int, Node **);
//   void (*endPush) (int, Node **);
//   Node *(*getElementByInfo) (int, Node *);
//   void (*updateElement) (int, int, Node *);
//   void (*deleteElement) (int, Node **);
// } Node;

void endPush(int info, Node **begin) {
  Node *n = malloc(sizeof(Node));
  n->info = info;
  n->next = NULL;

  if (*begin == NULL) {
    *begin = n;
    return;
  }

  Node *last = *begin;
  while (last->next != NULL) last = last->next;
  last->next = n;
}

void startPush(int info, Node **begin) {
  Node *n = malloc(sizeof(Node));
  n->info = info;
  n->next = *begin;
  *begin = n;
}

// Node *getElementByInfo(int info, Node *begin) {
//   Node *n = begin; 
//   while (n != NULL) {
//     if (n->info == info) return n;
//     n = n->next;
//   }

//   return NULL;
// }

// void updateElement(int newInfo, int infoToUpdate, Node *begin) {  
//   Node *n = getElementByInfo(infoToUpdate, begin); 
//   if (n != NULL) n->info = newInfo;
// }

// void deleteElement(int info, Node **begin) {
//   if (*begin == NULL) return;

//   Node *n = *begin;
//   if (n->info == info) {
//     Node *e = *begin;
//     *begin = n->next;
//     free(e);
//     return;
//   }

//   while (n != NULL) {
//     if (n->next->info == info) {
//       Node *e = n->next;
//       n->next = e->next;
//       free(e);
//       return;
//     }
//     n = n->next;
//   }
// }

// Node *createLinkedList() {
//   Node *p = NULL;
// }

int main(void) {
  // Node *p = createLinkedList();
  Node *begin = NULL;
  // int element, newElement;

  // p->endPush(1, &p);
  // p->endPush(2, &p);
  // p->endPush(3, &p);
  // p->endPush(4, &p);

  startPush(1, &begin);
  startPush(2, &begin);
  startPush(3, &begin);
  startPush(4, &begin);

  // printf("Insira um elemento para deletar da lista: ");
  // scanf("%d", &element);

  // Node *foundElement = getElementByInfo(element, p);

  // if (foundElement != NULL) printf("Info: %d\n", getElementByInfo(element, p)->info);
  // else printf("Não foi possível achar esse elemento.");

  // printf("Insira um elemento para alterar: ");
  // scanf("%d", &element);

  // printf("Insira o novo valor: ");
  // scanf("%d", &newElement);

  // updateElement(newElement, element, p);

  // deleteElement(element, &begin);

  for (Node *n = begin; n != NULL; n = n->next) {
    printf("%d ", n->info);
  }
}