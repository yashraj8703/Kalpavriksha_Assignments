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
    stack->arr=(int*)malloc(stack->size*sizeof(int));
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
void Push(struct stack * stack,int data)
{
    if(isFull(stack))
    {
        return;
    }
    stack->top++;
    stack->arr[stack->top]=data;
}
int pop(struct stack * stack)
{
    if(isEmpty(stack))
    {
        return -1;
    }
    int value=stack->arr[stack->top];
    stack->top--;
    return value;
}
void PrintStack(struct stack*stack)
{
    if(isEmpty(stack))
    {
        printf("stack is Empty");
        return;
    }
    for(int i=0;i<=stack->top;i++)
    {
        printf("%d ",stack->arr[i]);
    }
}
int main()
{
    struct stack*stack1=createStack(5);
    Push(stack1,10);
    Push(stack1,20);
    Push(stack1,30);
    Push(stack1,40);
    Push(stack1,50);
    int value=pop(stack1);
    printf("%d\n",value);
    PrintStack(stack1);
    return 0;
}