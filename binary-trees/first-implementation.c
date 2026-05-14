#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *left;
  struct Node *right;
} Node;

void addNode(Node **root, int value) {
  Node *new_node = malloc(sizeof(Node));

  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;

  *root = new_node;
}

void printTree(Node *tree) {
  if (tree == NULL) return;

  // pré ordem
  // em ordem
  // pós ordem
  
  printTree(tree->left);
  printf("%d\n", tree->value);
  printTree(tree->right);
}

int countTreeNodes(Node *tree) {
  if (tree == NULL) return 0;
  return countTreeNodes(tree->left) + countTreeNodes(tree->right) + 1;
}

int countTreeSheets(Node *tree) {
  if (tree == NULL) return 0;
  if (tree->left == NULL && tree->right == NULL) return 1;
  return countTreeSheets(tree->left) + countTreeSheets(tree->right); 
}

int countNotTreeSheets(Node *tree) {
  if (tree == NULL) return 0;
  if (tree->left != NULL || tree->right != NULL) return 1;
  return countNotTreeSheets(tree->left) + countNotTreeSheets(tree->right); 
}

int getTreeHeight(Node *tree) {
  if (tree == NULL) return -1;
  int leftheigth = getTreeHeight(tree->left);
  int rightHeight = getTreeHeight(tree->right);
  return (leftheigth > rightHeight ? leftheigth : rightHeight) + 1;
}

Node *getNodeByValue(Node *tree, int value) {
  if (tree == NULL) return NULL;
  if (tree->value == value) return tree;
  Node *isOnLeft = getNodeByValue(tree->left, value);
  Node *isOnRight = getNodeByValue(tree->right, value);
  if (isOnLeft != NULL) return isOnLeft;
  if (isOnRight != NULL) return isOnRight;
}

Node *binarySearch(Node *tree, int value) {
  if (tree == NULL) return NULL;
  if (tree->value == value) return tree;
  if (value < tree->value) return binarySearch(tree->left, value);
  else return binarySearch(tree->right, value);
}

int getNodeHeight(Node *tree, int value) {
  return getTreeHeight(binarySearch(tree, value));
}


int main(void) {
  Node *root = NULL;

  addNode(&root, 2);

  addNode(&root->left, 1);
  addNode(&root->right, 3);

  addNode(&root->right->left, 4);
  addNode(&root->right->right, 5);

  printTree(root);
  printf("Quantidade de nós: %d\n", countTreeNodes(root));
  printf("Quantidade de folhas: %d\n", countTreeSheets(root));
  printf("Quantidade de não folhas: %d\n", countNotTreeSheets(root));
  printf("Altura da árvore: %d\n", getTreeHeight(root));
  printf("Altura do node 2: %d\n", getNodeHeight(root, 2));
  printf("Valor 5 está na árvore? %s\n", getNodeByValue(root, 5) != NULL ? "Sim" : "Não");
  printf("Valor 5 está na árvore? %s", binarySearch(root, 5) != NULL ? "Sim" : "Não");

  return 0;
}