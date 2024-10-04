#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *left;
    int ele;
    struct node *right;
} Node;

// Insertion for a binary tree
void NodeInsertion(Node **root, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->ele = value;
    newNode->left = NULL;
    newNode->right = NULL;

    // If the tree is empty, insert the first node
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    // Use a queue for level-order (BFS) traversal to find the first available spot
    Node *queue[100];  // Fixed size for simplicity
    int front = 0, rear = 0;

    queue[rear++] = *root;

    while (front < rear) {
        Node *current = queue[front++];

        // Check the left child
        if (current->left == NULL) {
            current->left = newNode;
            return;
        } else {
            queue[rear++] = current->left;
        }

        // Check the right child
        if (current->right == NULL) {
            current->right = newNode;
            return;
        } else {
            queue[rear++] = current->right;
        }
    }
}

// In-order Traversal (Left, Root, Right)
void inordertraverse(Node *root) {
    if (root == NULL)
        return;

    inordertraverse(root->left);
    printf("%d ", root->ele);
    inordertraverse(root->right);
}

// Pre-order Traversal (Root, Left, Right)
void preordertraverse(Node *root) {
    if (root == NULL)
        return;

    printf("%d ", root->ele);
    preordertraverse(root->left);
    preordertraverse(root->right);
}

// Post-order Traversal (Left, Right, Root)
void postordertraverse(Node *root) {
    if (root == NULL)
        return;

    postordertraverse(root->left);
    postordertraverse(root->right);
    printf("%d ", root->ele);
}

int main() {
    Node *root = NULL;  

    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int ele;
        printf("Enter the element: ");
        scanf("%d", &ele);
        NodeInsertion(&root, ele);  
    }

    printf("\nIn order: ");
    inordertraverse(root);

    printf("\nPre order: ");
    preordertraverse(root);

    printf("\nPost order: ");
    postordertraverse(root);

    printf("\n");

    return 0;
}
