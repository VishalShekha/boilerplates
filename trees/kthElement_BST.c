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
        node->right = NULL;
        node->left = NULL;
        node->ele = ele;
        *root = node;
        return;
    }
    
    if(ele > current->ele){
        addNode(&current->right, ele);
    }
    else if(ele < current->ele){
        addNode(&current->left, ele);
    }
}

int cnt = 0;

void traversal(Node* root, int x){
    if(root==NULL){
        return;
    }
    traversal(root->left, x);
    
    cnt++;
    if(cnt==x){
    printf("%d ", root->ele);
        return;
    }
    
    traversal(root->right, x);
}

int main(){
    
    Node* root = NULL;
    
    int x;
    scanf("%d",&x);
    
    while(x>0){
        addNode(&root, x);
        scanf("%d",&x);
    }
    int k;
    scanf("%d",&k);
    
    traversal(root, k);
    
    return 0;
}