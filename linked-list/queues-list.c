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

int main() {
  //2
  Node *begin;
  Node *end;

  initQueue(&begin, &end);
}