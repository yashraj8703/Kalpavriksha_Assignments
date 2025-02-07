#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct Element {
    int id;
    int data;
    struct Element* next;
} Element;

Element* hashArray[SIZE] = {NULL};

int hashKey(int id) {
    return id % SIZE;
}

Element* createElement(int id, int data) {
    Element* newElement = (Element*)malloc(sizeof(Element));
    newElement->id = id;
    newElement->data = data;
    newElement->next = NULL;
    return newElement;
}

void addElement(int id, int data) {
    int index = hashKey(id);
    Element* newElement = createElement(id, data);
    
    Element* temp = hashArray[index];
    while (temp) {
        if (temp->id == id) {
            temp->data = data;
            free(newElement);
            return;
        }
        temp = temp->next;
    }

    newElement->next = hashArray[index];
    hashArray[index] = newElement;
}

int findElement(int id) {
    int index = hashKey(id);
    Element* temp = hashArray[index];
    while (temp) {
        if (temp->id == id) {
            return temp->data;
        }
        temp = temp->next;
    }
    return -1;
}

void removeElement(int id) {
    int index = hashKey(id);
    Element* temp = hashArray[index];
    Element* prev = NULL;
    
    while (temp) {
        if (temp->id == id) {
            if (prev) {
                prev->next = temp->next;
            } else {
                hashArray[index] = temp->next;
            }
            free(temp);
            printf("Element with ID %d removed.\n", id);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Element with ID %d not found.\n", id);
}

void showTable() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Bucket %d: ", i);
        Element* temp = hashArray[i];
        while (temp) {
            printf("(%d, %d) -> ", temp->id, temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int option, id, data;
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add Element\n2. Find Element\n3. Remove Element\n4. Show Table\n5. Exit\n");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Data: ");
                scanf("%d", &data);
                addElement(id, data);
                break;
            case 2:
                printf("Enter ID: ");
                scanf("%d", &id);
                data = findElement(id);
                if (data != -1) {
                    printf("Data: %d\n", data);
                } else {
                    printf("Element not found.\n");
                }
                break;
            case 3:
                printf("Enter ID: ");
                scanf("%d", &id);
                removeElement(id);
                break;
            case 4:
                showTable();
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}
