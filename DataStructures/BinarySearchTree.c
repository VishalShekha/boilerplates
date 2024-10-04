#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node* left;
    int ele;
    struct node* right;
}Node; 


// Insertion of nodes in BST
void InsertNode(Node** root, int ele){
    Node *current = *root;
    if(current==NULL){
        Node* node = (Node*)malloc(sizeof(Node));
        node->left = NULL;
        node->right = NULL;
        node->ele = ele;
        *root = node;
        return;
    }

    if(current->ele < ele){
        InsertNode(&current->right, ele);
    }

    else if(current->ele > ele){
        InsertNode(&current->left, ele);
    }

}



// Delete a Node
void DeleteNode(Node** root, int ele) {
    if (*root == NULL) {
        return;
    }

    if (ele < (*root)->ele) {
        DeleteNode(&(*root)->left, ele);
    } else if (ele > (*root)->ele) {
        DeleteNode(&(*root)->right, ele);
    } else {
        Node* temp = NULL;

        // Case 1: No children (leaf node)
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        }
        // Case 2: One child (right or left)
        else if ((*root)->left == NULL) {
            temp = *root;
            *root = (*root)->right;
            free(temp);
        } else if ((*root)->right == NULL) {
            temp = *root;
            *root = (*root)->left;
            free(temp);
        }
        // Case 3: Two children
        else {
            temp = (*root)->right;  // Find in-order successor
            while (temp->left != NULL) {
                temp = temp->left;
            }
            (*root)->ele = temp->ele;  // Replace with in-order successor
            DeleteNode(&(*root)->right, temp->ele);  // Delete the successor
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
        InsertNode(&root, ele);  
    }

    printf("\nIn order: ");
    inordertraverse(root);

    DeleteNode(&root, 2);

    printf("\nPre order: ");
    preordertraverse(root);

    printf("\nPost order: ");
    postordertraverse(root);

    printf("\n");

    return 0;
}
