#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void arrayToLinkedList(int arr[], int n) {
    head = createNode(arr[0]);
    struct Node* mover = head;
    for (int i = 1; i < n; i++) {
        struct Node* newnode = createNode(arr[i]);
        mover->next = newnode;
        mover = newnode;
    }
}

struct Node* sortedInsert(struct Node* sortedHead, struct Node* newnode) {
    if (sortedHead == NULL || newnode->data < sortedHead->data) {
        newnode->next = sortedHead;
        return newnode;
    }
    struct Node* current = sortedHead;
    while (current->next != NULL && current->next->data < newnode->data) {
        current = current->next;
    }
    newnode->next = current->next;
    current->next = newnode;
    return sortedHead;
}

void insertionSort() {
    struct Node* sorted = NULL;
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        sorted = sortedInsert(sorted, current);
        current = next;
    }
    head = sorted;
}

void printList() {
    struct Node* temp = head;
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
    insertionSort();
    printList();
    return 0;
}
