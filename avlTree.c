#include <stdio.h>
#include <stdlib.h>

// Create Node
struct Node {
    int key;
    struct Node *l;
    struct Node *r;
    int height;
};

int max(int a, int b);

// Calculate height
int height(struct Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Create a node
struct Node *newNode(int key) {
    struct Node *node = (struct Node *)
        malloc(sizeof(struct Node));
    node->key = key;
    node->l = NULL;
    node->r = NULL;
    node->height = 1;
    return (node);
}

// Right rotate
struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->l;
    struct Node *T2 = x->r;

    x->r = y;
    y->l = T2;

    y->height = max(height(y->l), height(y->r)) + 1;
    x->height = max(height(x->l), height(x->r)) + 1;

    return x;
}

// Left rotate
struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->r;
    struct Node *T2 = y->l;

    y->l = x;
    x->r = T2;

    x->height = max(height(x->l), height(x->r)) + 1;
    y->height = max(height(y->l), height(y->r)) + 1;

    return y;
}

// Get the balance factor
int getBalance(struct Node *N) {
    if (N == NULL)
        return 0;
    return height(N->l) - height(N->r);
}

// Insert node
struct Node *insertNode(struct Node *node, int key) {
    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->l = insertNode(node->l, key);
    else if (key > node->key)
        node->r = insertNode(node->r, key);
    else
        return node;

  // Update the balance factor of each node and
  // Balance the tree
    node->height = 1 + max(height(node->l), 
                height(node->r));

    int balance = getBalance(node);
    if (balance > 1 && key < node->l->key)
        return rightRotate(node);

    if (balance < -1 && key > node->r->key)
        return leftRotate(node);

    if (balance > 1 && key > node->l->key) {
        node->l = leftRotate(node->l);
        return rightRotate(node);
  }

    if (balance < -1 && key < node->r->key) {
        node->r = rightRotate(node->r);
        return leftRotate(node);
  }

    return node;
}

struct Node *minValueNode(struct Node *node) {
    struct Node *current = node;

    while (current->l != NULL)
        current = current->l;

    return current;
}

// Delete a nodes
struct Node *deleteNode(struct Node *root, int key) {
  // Find the node and delete it
    if (root == NULL)
        return root;

    if (key < root->key)
        root->l = deleteNode(root->l, key);

    else if (key > root->key)
        root->r = deleteNode(root->r, key);

    else {
        if ((root->l == NULL) || (root->r == NULL)) {
            struct Node *temp = root->l ? root->l : root->r;
        
        if (temp == NULL) {
            temp = root;
            root = NULL;
        } else
            *root = *temp;
        free(temp);
        } else {
        struct Node *temp = minValueNode(root->r);

        root->key = temp->key;

        root->r = deleteNode(root->r, temp->key);
        }
    }

    if (root == NULL)
        return root;

  // Update the balance factor of each node and
  // balance the tree
    root->height = 1 + max(height(root->l),
                height(root->r));

    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->l) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->l) < 0) {
        root->l = leftRotate(root->l);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->r) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->r) > 0) {
        root->r = rightRotate(root->r);
        return leftRotate(root);
    }

    return root;
}

// Print the tree
void printPreOrder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        printPreOrder(root->l);
        printPreOrder(root->r);
    }
}

int main() {
    struct Node *root = NULL;

    root = insertNode(root, 2);
    root = insertNode(root, 1);
    root = insertNode(root, 7);
    root = insertNode(root, 4);
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 8);

    printPreOrder(root);

    root = deleteNode(root, 3);

    printf("\nAfter deletion: ");
    printPreOrder(root);

    return 0;
}