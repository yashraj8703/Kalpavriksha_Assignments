#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *arr;
};

struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->size = size;
    queue->front = -1;
    queue->rear = -1;
    queue->arr = (int*)malloc(queue->size * sizeof(int));
    return queue;
}

int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

int isFull(struct Queue* queue) {
    return queue->rear == queue->size - 1;
}

void enqueue(struct Queue* queue, int data) {
    if (isFull(queue)) {
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->arr[queue->rear] = data;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    int data = queue->arr[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    return data;
}

void printQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

void stackPush(struct Queue* queue, int data) {
    enqueue(queue, data);
    int size = queue->rear - queue->front + 1;
    for (int i = 0; i < size - 1; i++) {
        int temp = dequeue(queue);
        enqueue(queue, temp);
    }
}

int stackPop(struct Queue* queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    return dequeue(queue);
}

int main() {
    struct Queue* queue = createQueue(3);
    stackPush(queue, 10);
    stackPush(queue, 20);
    stackPush(queue, 30);
    printQueue(queue); 

    return 0;
}
