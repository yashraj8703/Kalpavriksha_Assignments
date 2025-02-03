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
struct Node* OddEvenList(struct Node** head)
{
    
    struct Node* odd=createNode(-1);
    struct Node*oddtemp=odd;
    struct Node* even=createNode(0);
    struct Node*eventemp=even;
    struct Node*temp=*head;
    while(temp!=NULL)
    {
        if(temp->data%2!=0)
        {
            oddtemp->next=temp;
            oddtemp=temp;
        }
        else{
            eventemp->next=temp;
            eventemp=temp;
        }
        temp=temp->next;
    }
    eventemp->next = NULL;
    oddtemp->next=even->next;
    *head=odd->next;
    return*head;
}

int main()
{
    struct Node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head,4);
    insertAtEnd(&head, 4);
    insertAtEnd(&head,6);
    insertAtEnd(&head,9);
    printList(head);
    struct Node* newHead=NULL;
    newHead=OddEvenList(&head);
    printList(newHead);
    
}