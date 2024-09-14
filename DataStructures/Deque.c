#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int front, rear, size;
    int *queue;
}Queue;

Queue *Q = (Queue*)malloc(sizeof(Queue));

void enqueueRear(int x){
    if(Q->rear != Q->size-1){
        Q->queue[++Q->rear] = x;
    }
}
void enqueueFront(int x){
    if(Q->rear != Q->size-1){
        for(int i = Q->rear+1; i>Q->front;i--){
            Q->queue[i] = Q->queue[i-1]; 
        }
        Q->queue[Q->front] = x;
        Q->rear++;
    }
}
void dequeueRear(){
    if(Q->rear != -1){
        Q->rear--;
    }
}
void dequeueFront(){
    if(Q->rear != -1){
        for(int i =Q->front; i<Q->rear;i++){
            Q->queue[i] = Q->queue[i+1]; 
        }
        Q->rear--;
    }
}

void display(){
    for(int i=Q->front; i<Q->rear+1; i++) printf(" %d",Q->queue[i]);
}

int main(){
    
    Q->front=0;
    Q->rear=-1;
    Q->size = 51;
    Q->queue = (int*)malloc(sizeof(int));
    
    int t;
    scanf("%d",&t);
    int x,y;
    for(int i=0;i<t;i++){
        scanf("%d %d",&x,&y);
        if(x==1) enqueueFront(y);
        if(x==2) enqueueRear(y);
    }
    scanf("%d %d",&x,&y);
    
    printf("Original Deque:");
    display();
    
    dequeueFront();
    dequeueRear();
    printf("\nDeque after removing front and rear elements:");
    display();
    
    enqueueFront(x);
    enqueueRear(y);
    printf("\nDeque after adding new front and rear elements:");
    display();
    return 0;
}