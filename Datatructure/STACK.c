#include<stdio.h>

void push_operation(int x, int* S, int *top, int n){
    if(top == n-1){
        printf("The Stack is full.");
    }
    else{
        S[++(*top)] = x;
    }
}

void pop_operation(int *S,int *top){
    if(*top == -1){
        printf("The Stack is empty.");
    }
    else{
        printf("%d",S[(*top)--]);
    }
}

void print_stack(int *S,int top){  
    printf("STACK : ");
    for(int i=0;i<=top;i++) printf("%d ",S[i]);
    printf("\n");   
}

int main(){
    int n;
    printf("Enter the max number of elements: ");
    scanf("%d",&n);
    int S[n];
    int top = -1;

    while(1){
        int i;
        printf("Enter the operation: \nPUSH - 0\nPOP - 1\nPRINT - 2\n: ");
        scanf("%d",&i);
        if(i==0){
            int x;
            printf("Enter the number to push: ");
            scanf("%d",&x);
            push_operation(x,S,&top,n);
        }
        else if(i==1) pop_operation(S,&top);
        else if(i==2) print_stack(S,top);
        else printf("Choose valid option");
    }

    return 0;
}