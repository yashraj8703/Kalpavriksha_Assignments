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

void bubbleSort(struct Node* head) {
    struct Node* i;
    struct Node* j;
    for (i = head; i != NULL; i = i->next) {
        for (j = head; j->next != NULL; j = j->next) {
            if (j->data > j->next->data) {
                int temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
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

int countCommonElements(struct Node* head1, struct Node* head2) {
    struct Node* p = head1;
    struct Node* t = head2;
    int matches = 0;

    while (p != NULL && t != NULL) {
        if (p->data <= t->data) { 
            matches++;
            p = p->next;
            t = t->next;  
        } else {
            t = t->next; 
        }
    }

    return matches;
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
    int size1, size2;
    scanf("%d %d", &size1, &size2);
    int arr1[size1];
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }
    int arr2[size2];
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    struct Node* head1 = arrayToLinkedList(arr1, size1);
    struct Node* head2 = arrayToLinkedList(arr2, size2);

    bubbleSort(head1);
    bubbleSort(head2); 

    int count = countCommonElements(head1, head2);
    printf("Count is : %d\n", count);

    return 0;
}
