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
}
int precedence(char a)
{
    if(a=='^') return 3;
    if(a=='*' || a=='/') return 2;
    if(a=='+' || a=='-') return 1;
    else return 0;
}
void infixToPostfix(char str[],struct stack*stack)
{
    int n=strlen(str);
    char result[100];
    int index=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            result[index++]=str[i];
        }
        else if((str[i])=='(')
        {
            push(stack,str[i]);
        }
        else if((str[i])==')')
        {
            while(!isEmpty(stack) && (top(stack)!='('))
            {
                result[index++]=pop(stack);
            }
            if(!isEmpty(stack)){
             pop(stack);   
            }
        }
        else
        {
            while (!isEmpty(stack) && precedence(top(stack)) >= precedence(str[i])) 
            {
                result[index++] = pop(stack);
            }
            push(stack, str[i]);
        }
    }
    while(!isEmpty(stack))
    {
        result[index++]=pop(stack);
    }
    result[index] = '\0';
    printf("%s",result);
    
}
int main()
{
    struct stack* stack1=createStack(50);
    char str[]="(p+q)*(m-n)";
    infixToPostfix(str,stack1);
    
}