#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int front, rear, size;
    int* queue;
} Queue;

Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->queue = (int*)malloc(q->size * sizeof(int));
    return q;
}

void Enqueue(Queue* q, int value) {
    if ((q->front == 0 && q->rear == q->size - 1) || (q->rear + 1) % q->size == q->front) {
        printf("Queue is full\n");
        return;
    }

    if (q->front == -1) { // Insert the first element
        q->front = q->rear = 0;
    } else if (q->rear == q->size - 1) { // Wrap around
        q->rear = 0;
    } else { // Normal case
        q->rear++;
    }
    q->queue[q->rear] = value;
}

int Dequeue(Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return INT_MIN;
    }

    int data = q->queue[q->front];
    if (q->front == q->rear) { // Queue becomes empty after dequeue
        q->front = q->rear = -1;
    } else if (q->front == q->size - 1) { // Wrap around
        q->front = 0;
    } else { // Normal case
        q->front++;
    }
    return data;
}

void DisplayQueue(Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Elements in Circular Queue are: ");
    if (q->rear >= q->front) {
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->queue[i]);
        }
    } else {
        for (int i = q->front; i < q->size; i++) {
            printf("%d ", q->queue[i]);
        }
        for (int i = 0; i <= q->rear; i++) {
            printf("%d ", q->queue[i]);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the queue: ");
    scanf("%d", &n);

    Queue* q = createQueue(n);

    while (1) {
        printf("Enter the operation to be done\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n: ");
        int op;
        scanf("%d", &op);
        switch (op) {
            case 1: {
                int x;
                printf("Enter the element to be inserted: ");
                scanf("%d", &x);
                Enqueue(q, x);
                break;
            }
            case 2: {
                int data = Dequeue(q);
                if (data != INT_MIN) {
                    printf("Removed: %d\n", data);
                }
                break;
            }
            case 3:
                DisplayQueue(q);
                break;
            case 4:
                free(q->queue);
                free(q);
                return 0;
            default:
                printf("Enter a valid number.\n");
                break;
        }
    }
}
