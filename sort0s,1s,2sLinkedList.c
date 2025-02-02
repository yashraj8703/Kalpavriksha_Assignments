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
struct Node* SortLinkedList(struct Node** head)
{
    
    struct Node* zerodummy=createNode(-1);
    struct Node* onedummy=createNode(-1);
    struct Node* twodummy=createNode(-1);
    struct Node* zero=zerodummy;
    struct Node* one=onedummy;
    struct Node*two=twodummy;
    struct Node* temp=*head;
    while(temp)
    {
        if(temp->data==0)
        {
            zero->next=temp;
            zero=temp;
        }
        if(temp->data==1)
        {
            one->next=temp;
            one=temp;
        }
        if(temp->data==2)
        {
            two->next=temp;
            two=temp;
        }
        temp=temp->next;
    }
    zero->next = (onedummy->next) ? (onedummy->next) : (twodummy->next); 
    one->next = twodummy->next; 
    two->next = NULL; 
    *head = zerodummy->next; 
    return *head; 
    
}
int main()
{
    struct Node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 0);
    insertAtEnd(&head,1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head,0);
    printList(head);
    struct Node* newHead=NULL;
    newHead=SortLinkedList(&head);
    printList(newHead);
    
}