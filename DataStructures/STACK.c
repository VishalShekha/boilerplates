#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int top;
    int size;
    int* stack;
} Stack;

Stack* createStack(int size) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->size = size;
    s->top = -1;
    s->stack = (int*)malloc(s->size * sizeof(int));
    return s;
}

void push_operation(int x, Stack* s) {
    if (s->top == s->size - 1) {
        printf("The Stack is full.\n");
    } else {
        s->stack[++(s->top)] = x;
    }
}

void pop_operation(Stack* s) {
    if (s->top == -1) {
        printf("The Stack is empty.\n");
    } else {
        printf("%d\n", s->stack[(s->top)--]);
    }
}

void print_stack(Stack* s) {
    printf("STACK : ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->stack[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the max number of elements: ");
    scanf("%d", &n);
    
    Stack* s = createStack(n);

    while (1) {
        int i;
        printf("Enter the operation: \nPUSH - 0\nPOP - 1\nPRINT - 2\n: ");
        scanf("%d", &i);
        
        if (i == 0) {
            int x;
            printf("Enter the number to push: ");
            scanf("%d", &x);
            push_operation(x, s);
        } else if (i == 1) {
            pop_operation(s);
        } else if (i == 2) {
            print_stack(s);
        } else {
            printf("Choose a valid option.\n");
        }
    }

    free(s->stack);
    free(s);

    return 0;
}
