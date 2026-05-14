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
  if (tree == NULL) {
    printf("Árvore vazia.");
    return;
  }

  // pré ordem
  // em ordem
  // pós ordem
  
  printTree(tree->left);
  printTree(tree->right);
  printf("%d\n", tree->value);
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

void clearTree(Node **tree) {
  if (*tree == NULL) return;
  
  clearTree(&(*tree)->left);
  clearTree(&(*tree)->right);
  free(*tree);

  *tree = NULL;
}

int main(void) {
  Node *root = NULL;

  addNode(&root, 50);

  addNode(&root->left, 30);
  addNode(&root->left->left, 20);
  addNode(&root->left->right, 40);
  addNode(&root->left->right->right, 45);

  addNode(&root->right, 70);
  addNode(&root->right->right, 85);

  printTree(root);
  printf("Quantidade de nós: %d\n", countTreeNodes(root));
  printf("Quantidade de folhas: %d\n", countTreeSheets(root));
  printf("Quantidade de não folhas: %d\n", countNotTreeSheets(root));
  printf("Altura da árvore: %d\n", getTreeHeight(root));
  printf("Altura do node 2: %d\n", getNodeHeight(root, 2));
  printf("Valor 5 está na árvore? %s\n", getNodeByValue(root, 5) != NULL ? "Sim" : "Não");
  printf("Valor 5 está na árvore? %s\n", binarySearch(root, 5) != NULL ? "Sim" : "Não");
  clearTree(&root);
  printTree(root);

  return 0;
}