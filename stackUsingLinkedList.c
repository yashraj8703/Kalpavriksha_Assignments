#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void Push(struct Stack* stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int Pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poppedValue;
}

void PrintStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Stack* stack1 = createStack();

    Push(stack1, 10);
    Push(stack1, 20);
    Push(stack1, 30);
    Push(stack1, 40);
    Push(stack1, 50);

    printf("Stack contents: ");
    PrintStack(stack1);

    printf("Popped element: %d\n", Pop(stack1));
    printf("Stack contents after pop: ");
    PrintStack(stack1);
     struct Stack* stack2 = createStack();

    Push(stack2, 102);
    Push(stack2, 204);
    Push(stack2, 304);
    Push(stack2, 40);
    Push(stack2, 50);

    printf("Stack contents: ");
    PrintStack(stack2);

    printf("Popped element: %d\n", Pop(stack2));
    printf("Stack contents after pop: ");
    PrintStack(stack2);

    return 0;
}
