#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *arr;
};
struct Queue* createQueue(int size)
{
    struct Queue* Queue=(struct Queue*)malloc(sizeof(struct Queue));
    Queue->size=size;
    Queue->front=-1;
    Queue->rear=-1;
    Queue->arr=(int*)malloc(Queue->size*sizeof(int));
    return Queue;
}

int isEmpty(struct Queue* Queue)
{
    return Queue->front==-1;
}
int isFull(struct Queue* Queue)
{
    return Queue->rear == Queue->size - 1;
}
void Push(struct Queue* Queue,int data)
{
    if(isFull(Queue))
    {
        return;
    }
    if(Queue->front==-1)
    {
        Queue->front=0;
    }
    Queue->rear++;
    Queue->arr[Queue->rear]=data;
}
int pop(struct Queue* Queue)
{
    if(isEmpty(Queue))
    {
        return -1;
    }
    int data=Queue->arr[Queue->front];
    Queue->front++;
    if(Queue->front>Queue->rear)
    {
        Queue->front=-1;
        Queue->rear=-1;
    }
    return data;
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
void stackPush(struct Queue* Queue1,int data)
{
    Push(Queue1,data);
}
int stackPop(struct Queue* Queue1,struct Queue* Queue2)
{
    if (isEmpty(Queue1)) {
        printf("Stack is empty\n");
        return -1; 
    }
    int size=Queue1->rear-Queue1->front+1;
    for(int i=0;i<size-1;i++)
    {
        int data=pop(Queue1);
        Push(Queue2,data);
    }
    int popdata=pop(Queue1);
    while (!isEmpty(Queue2)) {
        int data = pop(Queue2);
        Push(Queue1, data);
    }
    return popdata;
}
int main()
{
    struct Queue* Queue1=createQueue(3);
    struct Queue* Queue2=createQueue(3);
    stackPush(Queue1,10);
    stackPush(Queue1,20);
    stackPush(Queue1,30);
    PrintQueue(Queue1);  
    printf("Popped: %d\n", stackPop(Queue1, Queue2)); 
    PrintQueue(Queue1);  
}

