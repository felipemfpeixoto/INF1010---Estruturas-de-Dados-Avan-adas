#include <stdio.h>
#include <stdlib.h>

// Alunos:
// Felipe Mussi Ferreira Peixoto
// Ricardo Stuckert

typedef struct Node {
  int data;
  int height;
  struct Node* left;
  struct Node* right;
} Node;

Node* createNode(int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->height = 0;
  return newNode;
}

int calculateHeight(Node* root) {
  if (root == NULL)
    return -1;
  else {
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    root->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    
    return root->height;
  }
}

void freeTree(Node* root) {
  if (root == NULL)
      return;
  if (root->left != NULL) {
    freeTree(root->left);
  }
  if (root->right != NULL) {
    freeTree(root->right);
  }

  // Liberar o nó atual
  free(root);
}

void printNodeHeights(Node* root) {
  if (root != NULL) {
    printf("Altura do nó %d: %d\n", root->data, root->height);
    printNodeHeights(root->left);
    printNodeHeights(root->right);
  }
}

int main() {
  Node* root = createNode(4);
  root->left = createNode(2);
  root->right = createNode(6);
  root->left->left = createNode(1);
  root->left->right = createNode(3);
  root->right->left = createNode(5);
  root->right->right = createNode(7);

  int height = calculateHeight(root);

  printNodeHeights(root);

  freeTree(root);
  
  return 0;
}
