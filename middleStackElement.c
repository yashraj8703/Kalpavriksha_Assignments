#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct stack{
    int size;
    int top;
    char *arr;
};
struct stack* createStack(int size)
{
    struct stack* stack=(struct stack*)malloc(sizeof(struct stack));
    stack->size=size;
    stack->top=-1;
    stack->arr=(char *)malloc(stack->size*sizeof(char));
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
int top(struct stack* stack)
{
    if(isEmpty(stack))
    {
        return -1;
    }
    int value=stack->arr[stack->top];
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
    printf("\n");
}
int findAndRemoveMiddle(struct stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }

    struct stack* tempStack = createStack(stack->size);
    int middleIndex = stack->top / 2;

    for (int i = 0; i < middleIndex; i++) {
        push(tempStack, pop(stack));
    }

    int middleElement = pop(stack);

    while (!isEmpty(tempStack)) {
        push(stack, pop(tempStack));
    }

    free(tempStack->arr);
    free(tempStack);

    return middleElement;
}
int main()
{
    struct stack* stack=createStack(50);
    push(stack,1);
    push(stack,2);
    push(stack,3);
    push(stack,4);
    push(stack,5);
    printStack(stack);
    int middle=findAndRemoveMiddle(stack);
    printStack(stack);
    
}