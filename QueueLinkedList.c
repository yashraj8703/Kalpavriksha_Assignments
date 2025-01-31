#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node*next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};
struct Queue* createQueue() {
    struct Queue* Queue = (struct Queue*)malloc(sizeof(struct Queue));
    Queue->front = NULL;
    Queue->rear = NULL;
    return Queue;
};


int isEmpty(struct Queue* Queue) {
    return Queue->front->data == -1;
}

void Push(struct Queue* Queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (Queue->rear == NULL) {
        Queue->front = Queue->rear = newNode;
        return;
    }
    
    Queue->rear->next = newNode;
    Queue->rear = newNode;
}

int pop(struct Queue* Queue) {
    if(isEmpty(Queue))
    {
        return -1;
    }
    struct Node* temp=Queue->front;
    int value=temp->data;
    Queue->front=temp->next;
    if (Queue->front == NULL) {  
        Queue->rear = NULL;
    }

    free(temp);
    return value;
}

void PrintQueue(struct Queue* Queue) {
    if (isEmpty(Queue)) {
        printf("Queue is Empty\n");
        return;
    }

    struct Node* current = Queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
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
    pop(Queue1);
    PrintQueue(Queue1);

    return 0;
}
