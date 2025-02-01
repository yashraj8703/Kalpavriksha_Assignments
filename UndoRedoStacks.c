#include <stdio.h>
#include <stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};
struct stack* createStack(int size)
{
    struct stack* stack=(struct stack*)malloc(sizeof(struct stack));
    stack->size=size;
    stack->top=-1;
    stack->arr=(int *)malloc(stack->size*sizeof(int));
    return stack;
}
int isFull(struct stack* stack)
{
    return stack->top==stack->size-1;
}
int isEmpty(struct stack* stack)
{
    return stack->top==-1;
}
void push(struct stack* stack,int data)
{
    if(isFull(stack))
    {
        return;
    }
    stack->top++;
    stack->arr[stack->top]=data;
}
int pop(struct stack* stack)
{
    if(isEmpty(stack))
    {
        return -1;
    }
    int value=stack->arr[stack->top];
    stack->top--;
    return value;
}
void printStack(struct stack*stack)
{
    if(isEmpty(stack))
    {
        return;
    }
    for(int i=0;i<=stack->top;i++)
    {
        printf("%d ",stack->arr[i]);
    }
}
void undoOperation(struct stack* stack,struct stack* undoStack)
{
    int value=pop(stack);
    push(undoStack,value);
}
void redoOperation(struct stack* stack,struct stack* undoStack)
{
    int value=pop(undoStack);
    push(stack,value);
}
int main()
{
    struct stack* stack1=createStack(5);
    struct stack* undoStack=createStack(5);
    push(stack1,1);
    push(stack1,2);
    push(stack1,3);
    push(stack1,4);
    push(stack1,5);
    printStack(stack1);
    printf("\n---------------------\n");
    undoOperation(stack1,undoStack);
    undoOperation(stack1,undoStack);
    printStack(stack1);
    redoOperation(stack1,undoStack);
    redoOperation(stack1,undoStack);
    printf("\n---------------------\n");
    printStack(stack1);
    return 0;
}