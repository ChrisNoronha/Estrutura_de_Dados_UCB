#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int key;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *createNode(int key) {
  struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  newNode->key = key;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

struct TreeNode *insert(struct TreeNode *root, int key) {
  if (root == NULL) {
    return createNode(key);
  }

  if (key < root->key) {
    root->left = insert(root->left, key);
  } else if (key > root->key) {
    root->right = insert(root->right, key);
  }

  return root;
}

struct TreeNode *minValueNode(struct TreeNode *node) {
  struct TreeNode *current = node;

  while (current && current->left != NULL) {
    current = current->left;
  }

  return current;
}

struct TreeNode *deleteNode(struct TreeNode *root, int key) {
  if (root == NULL) {
    return root;
  }

  if (key < root->key) {
    root->left = deleteNode(root->left, key);
  } else if (key > root->key) {
    root->right = deleteNode(root->right, key);
  } else {
    if (root->left == NULL) {
      struct TreeNode *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct TreeNode *temp = root->left;
      free(root);
      return temp;
    }

    struct TreeNode *temp = minValueNode(root->right);
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

struct TreeNode *search(struct TreeNode *root, int key) {
  if (root == NULL || root->key == key) {
    return root;
  }

  if (key < root->key) {
    return search(root->left, key);
  }

  return search(root->right, key);
}

void inorder(struct TreeNode *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
  }
}

void preorder(struct TreeNode *root) {
  if (root != NULL) {
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(struct TreeNode *root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
  }
}

struct TreeNode *findMin(struct TreeNode *root) {
  if (root == NULL) {
    return NULL;
  }

  while (root->left != NULL) {
    root = root->left;
  }

  return root;
}

struct TreeNode *findMax(struct TreeNode *root) {
  if (root == NULL) {
    return NULL;
  }

  while (root->right != NULL) {
    root = root->right;
  }

  return root;
}

void clearScreenAfterDelay(int seconds) {
  sleep(seconds);  // Espera pelo número de segundos especificado
  system("clear"); // Limpa a tela após o intervalo de tempo
}

void printMenu() {
  clearScreenAfterDelay(5);
  printf("|--------------------------------------------------------|\n");
  printf("|Binary Search Tree Operations                           |\n");
  printf("|1. Inserir valor                                        |\n");
  printf("|2. Remover valor                                        |\n");
  printf("|3. Buscar valor                                         |\n");
  printf("|4. Percorrer a árvore em ordem (inorder)                |\n");
  printf("|5. Percorrer a árvore em pré-ordem (preorder)           |\n");
  printf("|6. Percorrer a árvore em pós-ordem (postorder)          |\n");
  printf("|7. Encontrar valor mínimo                               |\n");
  printf("|8. Encontrar valor máximo                               |\n");
  printf("|9. Sair                                                 |\n");
  printf("|--------------------------------------------------------|\n");
  printf("Escolha uma operacao: ");
}

void freeTree(struct TreeNode *root) {
  if (root != NULL) {
    freeTree(root->left);
    freeTree(root->right);
    free(root);
  }
}

int main() {
  struct TreeNode *root = NULL;
  int choice, value;

  do {

    printMenu();
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Digite o valor a ser inserido: ");
      scanf("%d", &value);
      root = insert(root, value);
      break;
    case 2:
      printf("Digite o valor a ser removido: ");
      scanf("%d", &value);
      root = deleteNode(root, value);
      break;
    case 3:
      printf("Digite o valor a ser buscado: ");
      scanf("%d", &value);
      if (search(root, value) != NULL) {
        printf("O valor %d está presente na árvore.\n", value);
      } else {
        printf("O valor %d não está presente na árvore.\n", value);
      }
      break;
    case 4:
      printf("Percorrendo a árvore em ordem (inorder): ");
      inorder(root);
      printf("\n");
      break;
    case 5:
      printf("Percorrendo a árvore em pré-ordem (preorder): ");
      preorder(root);
      printf("\n");
      break;
    case 6:
      printf("Percorrendo a árvore em pós-ordem (postorder): ");
      postorder(root);
      printf("\n");
      break;
    case 7:
      printf("Valor mínimo na árvore: %d\n", findMin(root)->key);
      break;
    case 8:
      printf("Valor máximo na árvore: %d\n", findMax(root)->key);
      break;
    case 9:
      printf("Encerrando o programa...\n");
      break;
    default:
      printf("Opcao invalida! Tente novamente.\n");
    }

  } while (choice != 9);

  freeTree(root); // Liberar a memória alocada para os nós da árvore antes de
                  // encerrar o programa

  return 0;
}