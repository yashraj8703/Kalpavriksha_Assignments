#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* createNode(int data)
{
    struct Node* Node=(struct Node*)malloc(sizeof(struct Node));
    Node->data=data;
    Node->next=NULL;
    return Node;
}
void insertAtEnd(struct Node** head,int data)
{
    struct Node* newnode=createNode(data);
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }
    struct Node* temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
struct Node* removeDuplicate(struct Node** head)
{
    struct Node* current=*head;
    while(current)
    {
        if(current->next!=NULL && current->data==current->next->data)
        {
            current->next=current->next->next;
        }
        else
        {
            current=current->next;
        }
    }
    return *head;
}
int main()
{
    struct Node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 3);
    insertAtEnd(&head,15);
    printList(head);
    struct Node* newHead=NULL;
    newHead=removeDuplicate(&head);
    printList(newHead);
    
}