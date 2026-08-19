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


void traversal(Node* root) {
    if (root == NULL) {
        return;
    }

    Node* queue[100];
    int rear = 0, front = 0;

    queue[rear++] = root;  

    while (rear > front) {
        Node* current = queue[front++]; 
        printf("%d ", current->ele); 

        if (current->left != NULL) { 
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {  
            queue[rear++] = current->right;
        }
    }
}
int main(){
    
    Node* root = NULL;
    
    int x;
    scanf("%d",&x);
    
    while(x>0){
        addNode(&root, x);
        scanf("%d",&x);
    }
    
    traversal(root);
    
    return 0;
}