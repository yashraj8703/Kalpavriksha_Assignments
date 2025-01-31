#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *arr;
};

struct Queue* createQueue(int size) {
    struct Queue* Queue = (struct Queue*)malloc(sizeof(struct Queue));
    Queue->size = size;
    Queue->front = -1;
    Queue->rear = -1;
    Queue->arr = (int*)malloc(Queue->size * sizeof(int));
    return Queue;
}

int isFull(struct Queue* Queue) {
    return Queue->rear == Queue->size - 1;
}

int isEmpty(struct Queue* Queue) {
    return Queue->front == -1;
}

void Push(struct Queue* Queue, int data) {
    if (isFull(Queue)) {
        printf("Queue is Full\n");
        return;
    }
    if (Queue->front == -1) {
        Queue->front = 0;
    }
    Queue->rear++;
    Queue->arr[Queue->rear] = data;
}

int pop(struct Queue* Queue) {
    if (isEmpty(Queue)) {
        printf("Queue is Empty\n");
        return -1;
    }
    int value = Queue->arr[Queue->front];
    Queue->front++;
    
    if (Queue->front > Queue->rear) {
        Queue->front = Queue->rear = -1;
    }
    return value;
}

void PrintQueue(struct Queue* Queue) {
    if (isEmpty(Queue)) {
        printf("Queue is Empty\n");
        return;
    }
    for (int i = Queue->front; i <= Queue->rear; i++) {
        printf("%d ", Queue->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue* Queue1 = createQueue(5);

    Push(Queue1, 10);
    Push(Queue1, 20);
    Push(Queue1, 30);
    Push(Queue1, 40);
    Push(Queue1, 50);
    PrintQueue(Queue1);

    return 0;
}
