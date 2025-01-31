#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int size;
    int *arr;
};

struct Stack* CreateStack(int size) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->size = size;
    stack->arr = (int*)malloc(stack->size * sizeof(int));  // Fix: store the allocated memory
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->size - 1;
}

void Push(struct Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = data;
}

int Pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1; 
    }
    int value = stack->arr[stack->top];
    stack->top--;
    return value;
}

void PrintStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}
void Enqueue(struct Stack* inputStack,int data)
{
    Push(inputStack,data);
}
int Deque(struct Stack* inputStack,struct Stack* outputStack)
{
    
    if (isEmpty(outputStack)) {
        while (!isEmpty(inputStack)) {
            int data = Pop(inputStack);
            Push(outputStack, data);
        }
    }
    if (isEmpty(outputStack)) {
        printf("Queue is empty\n");
        return -1; 
    }
    return Pop(outputStack); 
}


int main() {
    struct Stack* inputStack = CreateStack(5);
    struct Stack* outputStack= CreateStack(5);

    Enqueue(inputStack,5);
    Enqueue(inputStack,4);
    Enqueue(inputStack,3);
    Enqueue(inputStack,2);
    Enqueue(inputStack,1);
    PrintStack(inputStack);

    int val=Deque(inputStack,outputStack);
    printf("%d",val);
    
    

    return 0;
}
