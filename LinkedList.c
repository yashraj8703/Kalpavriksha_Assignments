#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* head = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void InsertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

void InsertAtPosition(int k, int data) {
    if (k == 1) {
        InsertAtBeginning(data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    for (int i = 1; i < k - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) return;
    newNode->next = temp->next;
    temp->next = newNode;
}

void InsertAtEnd(int data) {
    if (head == NULL) {
        head = createNode(data);
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    struct Node* newNode = createNode(data);
    temp->next = newNode;
}

void DeleteAtBeginning() {
    if (head == NULL) return;
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void DeleteAtEnd() {
    if (head == NULL) return;
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;
    }
    struct Node* delNode = temp->next;
    temp->next = NULL;
    free(delNode);
}

void DeleteAtPosition(int k) {
    if (head == NULL || k < 1) return;
    if (k == 1) {
        DeleteAtBeginning();
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < k - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) return;
    struct Node* delNode = temp->next;
    temp->next = temp->next->next;
    free(delNode);
}

void UpdateAtBeginning(int data) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    head->data = data;
}

void UpdateAtEnd(int data) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->data = data;
}

void UpdateAtPosition(int k, int data) {
    if (head == NULL || k < 1) {
        printf("Invalid position or empty list\n");
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < k && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    temp->data = data;
}

void printList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int LengthLinkedList() {
    int length = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int ch;
        scanf("%d", &ch);

        if (ch == 1) {
            int value;
            scanf("%d", &value);
            InsertAtEnd(value);
        } else if (ch == 2) {
            int value;
            scanf("%d", &value);
            InsertAtBeginning(value);
        } else if (ch == 3) {
            int position, value;
            scanf("%d %d", &position, &value);
            InsertAtPosition(position, value);
        } else if (ch == 4) {
            printList();
        } else if (ch == 5) {
            int position, value;
            scanf("%d %d", &position, &value);
            UpdateAtPosition(position, value);
        } else if (ch == 6) {
            DeleteAtBeginning();
        } else if (ch == 7) {
            DeleteAtEnd();
        } else if (ch == 8) {
            int position;
            scanf("%d", &position);
            DeleteAtPosition(position);
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
