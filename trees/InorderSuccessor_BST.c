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
int flag = 0;
void inordertraversal(Node *root, int x){
    if(root==NULL) return;
    
    inordertraversal(root->left, x);
    if(flag){ 
        printf("In-order Successor of %d is %d ",x,root->ele);
        exit(0);
    }
    if(root->ele == x) flag = 1;
    inordertraversal(root->right, x);
}

int main(){
    
    Node* root=NULL;
    
    int n;
    scanf("%d",&n);
    
    for(int i=0; i<n; i++){
        int x;
        scanf("%d",&x);
        addNode(&root, x);
    }
    
    int x;
    scanf("%d",&x);
    inordertraversal(root, x);
    
    printf("In-order Successor doesn't exist");
    
    return 0;
}