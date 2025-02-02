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
struct Node* removeDuplicate(struct Node** head,int k)
{
    struct Node* dummy=createNode(0);
    dummy->next=*head;
    struct Node* current=dummy;
    while(current != NULL && current->next != NULL)
    {
        if(current->next->data==k)
        {
            struct Node* temp = current->next;  
            current->next = current->next->next;
            free(temp); 
        }
        else
        {
            current=current->next;
        }
    }
    return dummy->next;
}
int main()
{
    struct Node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 3);
    insertAtEnd(&head,4);
    insertAtEnd(&head, 3);
    insertAtEnd(&head,15);
    printList(head);
    struct Node* newHead=NULL;
    newHead=removeDuplicate(&head,3);
    printList(newHead);
    
}