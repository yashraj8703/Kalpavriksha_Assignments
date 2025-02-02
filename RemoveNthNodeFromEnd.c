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
struct Node* NthNodeFromEnd(struct Node** head,int k)
{
    struct Node* dummy=createNode(0);
    dummy->next=*head;
    struct Node* fast=dummy;
    struct Node* slow=dummy;
    for(int i=1;i<=k+1;i++)
    {
        fast=fast->next;
    }
    while(fast != NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;
    return dummy->next;
}
int main()
{
    struct Node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head,3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head,5);
    printList(head);
    struct Node* newHead=NULL;
    newHead=NthNodeFromEnd(&head,4);
    printList(newHead);
    
}