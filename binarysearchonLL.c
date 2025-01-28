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
    return newNodea;
}

struct Node* findMiddle(struct Node* start, struct Node* end) {
    struct Node* slow = start;
    struct Node* fast = start;

    while (fast != end && fast->next != end) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

int findPeakElement(struct Node* head) {

    if (head == NULL) return -1;

    struct Node* start = head;
    struct Node* end = NULL;

    while (start != NULL) {
        struct Node* mid = findMiddle(start, end);
        struct Node* previous = start;
        
        while (previous != NULL && previous->next != mid) {
            previous = previous->next;
        }

        struct Node* forward = mid->next;

        if ((forward == NULL || mid->data > forward->data) && (previous == NULL || mid->data > previous->data)) {
            return mid->data;
        }
        if (previous != NULL && mid->data < previous->data) {
            end = previous;
        } else {
            start = mid->next;
        }
    }

    return -1;
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

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int size;
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    struct Node* head = arrayToLinkedList(arr, size);

    printf("Linked List: ");
    printList(head);

    int peak = findPeakElement(head);
    printf("Peak Element: %d\n", peak);

    return 0;
}
