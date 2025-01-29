#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(int data) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void arrayToLinkedList(int arr[], int n) {
    head = createNode(arr[0]);
    struct Node *mover = head;
    for (int i = 1; i < n; i++) {
        struct Node *newnode = createNode(arr[i]);
        mover->next = newnode;
        mover = newnode;
    }
}

void swapNodes(struct Node *node1, struct Node *node2) {
    if (node1 == node2) return;  
    struct Node *prev1 = NULL, *prev2 = NULL, *curr1 = head, *curr2 = head;

    while (curr1 && curr1 != node1) {
        prev1 = curr1;
        curr1 = curr1->next;
    }

    while (curr2 && curr2 != node2) {
        prev2 = curr2;
        curr2 = curr2->next;
    }

    if (!curr1 || !curr2) return;

    if (prev1) prev1->next = curr2;
    else head = curr2; 

    if (prev2) prev2->next = curr1;
    else head = curr1;
    struct Node *temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;
}

void selectionSort() {
    struct Node *current = head;

    while (current && current->next) {
        struct Node *mini = current;
        struct Node *nextnode = current->next;

        while (nextnode) {
            if (nextnode->data < mini->data) {
                mini = nextnode;
            }
            nextnode = nextnode->next;
        }

        if (mini != current) {
            swapNodes(current, mini);
            current=mini;
        }
        current = current->next;
    }
}

void printList() {
    struct Node *temp = head;
    while (temp != NULL) {
        if (temp->next == NULL) {
            printf("%d->NULL", temp->data);
        } else {
            printf("%d->", temp->data);
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    arrayToLinkedList(arr, n);
    printList();
    selectionSort();
    printList();
    return 0;
}
