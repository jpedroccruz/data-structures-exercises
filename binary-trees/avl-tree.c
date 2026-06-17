#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *left;
  struct Node *right;
} Node;


void simpleLeftRotation(Node **n) {
  Node *nr = (*n)->right;
  Node *nrl = nr->left;

  nr->left = *n;
  (*n)->right = nrl;

  *n = nr;
}

void simpleRightRotation(Node **n) {
  Node *nl = (*n)->left;
  Node *nlr = nl->right;

  nl->right = *n;
  (*n)->left = nlr;

  *n = nl;
}

int getTreeHeight(Node *tree) {
  if (tree == NULL) return -1;
  int leftheigth = getTreeHeight(tree->left);
  int rightHeight = getTreeHeight(tree->right);
  return (leftheigth > rightHeight ? leftheigth : rightHeight) + 1;
}

void printTree(Node *tree, int level) {
  if (tree == NULL) {
    return;
  }
  
  // pré ordem
  // em ordem
  // pós ordem
  
  printTree(tree->left, level + 1);
  for (int i = level * 5; i >= 0; i--) printf(" ");
  printf("%d\n", tree->value);
  printTree(tree->right, level + 1);
}

Node *createNode(int value) {
  Node *new_node = malloc(sizeof(Node));
  
  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;
  
  return new_node;
}

int getBalanceScore(Node *root) {
  if (root == NULL) return -1;

  return getTreeHeight(root->left) - getTreeHeight(root->right); 
}

void insertElement(Node **root, int value) {
  if (*root == NULL) {
    *root = createNode(value);
    return;
  }

  if (value < (*root)->value) insertElement(&(*root)->left, value);
  else insertElement(&(*root)->right, value);

  int balanceScore = getBalanceScore(*root);

  // simple rotation
  // if (balanceScore < -1 && (*root)->right->value < value) simpleLeftRotation(root);
  // else if (balanceScore > 1 && (*root)->left->value > value) simpleRightRotation(root);

  // double rotation
  if (balanceScore < -1) { // left
    if ((*root)->right->value > value) simpleRightRotation(&(*root)->right);
    simpleLeftRotation(root);
  } else if (balanceScore > 1) { // right
    if ((*root)->right->value < value) simpleLeftRotation(&(*root)->left);
    simpleRightRotation(root);  
  }
}

int main(void) {
  Node *root = NULL;
  
  insertElement(&root, 10);
  insertElement(&root, 30);
  insertElement(&root, 20);
  printTree(root, 0);

  return 0;
}