#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* arrayToLinkedList(int arr[], int size) {
    if (size == 0) return NULL;

    struct Node* head = createNode(arr[0]);
    struct Node* current = head;

    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }

    return head;
}

int isSorted(struct Node* head) {
    if (head == NULL || head->next == NULL) return 1;

    struct Node* current = head;
    while (current->next != NULL) {
        if (current->data > current->next->data) {
            return 0;
        }
        current = current->next;
    }
    return 1; // List is sorted
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int size1;
    scanf("%d", &size1); 
    int arr1[size1];

    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    struct Node* head = arrayToLinkedList(arr1, size1);

    if (isSorted(head)) {
        printf("The list is sorted.\n");
    } else {
        printf("The list is not sorted.\n");
    }

    return 0;
}
