// You are using GCC
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node* left;
    int ele;
    struct node* right;
}Node; 

void addNode(Node** root, int ele){
    Node* current = *root;
    
    if(current==NULL){
        Node* node = new Node;
        node->left = NULL;
        node->right = NULL;
        node->ele = ele;
        *root = node;
        return;
    }
    if(current->ele < ele){
        addNode(&current->right, ele);
    }
    else if(current->ele > ele){
        addNode(&current->left, ele);
    }
    
}

void deleteNode(Node** root, int ele){
    Node* current = *root;
    
    if(current == NULL) return;
    
    if(current->ele > ele){
        deleteNode(&current->left, ele);
    }
    else if(current->ele < ele){
        deleteNode(&current->right, ele);
    }
    else{
            
        if(current->right == NULL && current->left == NULL){
            free(current);
            *root = NULL;
        }
        
        else if(current->right == NULL){
            *root = (*root)->left;
            free(current);
        }
        else if(current->left == NULL){
            *root = (*root)->right;
            free(current);
        }
        
        else{
            Node* temp = current->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            (*root)->ele = temp->ele;
            deleteNode(&(*root)->right, temp->ele);
        }
    }
}

void inordertraversal(Node **root, int x){
    Node* current = *root;
    if(current == NULL) return;
    
    inordertraversal(&current->left, x);
    if(current->ele <= x)  {
        printf("%d ", current->ele);
    }
    else deleteNode(root, (*root)->ele);
    inordertraversal(&current->right, x);
}

int main(){
    Node* root = NULL;
    
    int n;
    scanf("%d", &n);
    int sum = 0;
    for(int i=0; i<n; i++){
        int ele;
        scanf("%d",&ele);
        sum += ele;
        addNode(&root, ele);
    }
    
    int x = sum / n;
    
    inordertraversal(&root, x);
    
    return 0;
}