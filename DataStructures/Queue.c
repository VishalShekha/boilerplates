#include <stdio.h>
#include <stdlib.h>

typedef struct q {
    int front, rear, size;
    int* queue;
}Queue;

Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->size = size;
    q->front = 0;
    q->rear = -1;
    q->queue = (int*)malloc(q->size * sizeof(int));
    return q;
}

void Enqueue(Queue *q, int x){
    if(q->rear == q->size -1){
        printf("Queue is full\n");
    }
    else{
        q->queue[++q->rear] = x;
    }
}

void Dequeue(Queue *q){
    if(q->front > q->rear){
        printf("The Queue is empty\n");
    }
    else{
        int temp = q->queue[q->front];
        for(int i = 0; i<q->rear;i++){
            q->queue[i] = q->queue[i+1];
        }
        q->rear--;
        printf("Removed : %d\n",temp);
    }
}

void Peek(Queue *q){
    if(q->front > q->rear){
        printf("The Queue is empty\n");
    }
    else{
        printf("Front Element : %d\n",q->queue[q->front]);
    }
}

int main(){

    int n;
    printf("Enter the size of the queue : ");
    scanf("%d",&n);

    Queue *q = createQueue(n);

    while(1){
        /*
        Enqueue (Insert): Adds an element to the rear of the queue.
        Dequeue (Delete): Removes and returns the element from the front of the queue.
        Peek: Returns the element at the front of the queue without removing it.
        */
        printf("Enter the operation to be done\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Exit\n: ");
        int op;
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            printf("Enter the element to be inserted : ");
            int x;
            scanf("%d",&x);
            Enqueue(q, x);
            break;
        
        case 2:
            Dequeue(q);
            break;

        case 3:
            Peek(q);
            break;

        case 4:
            free(q);
            return 0;
        default:
            printf("Enter a valid number : ");
            break;
        }
    }



    return 0;
}