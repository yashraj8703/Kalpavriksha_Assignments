#include <stdio.h>
#include <stdlib.h>
#include<string.h>
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
struct Node* mergeList(struct Node** head1,struct Node**head2)
{
    struct Node* dummy=createNode(-1);
    struct Node*temp=dummy;
    struct Node*t1=*head1;
    struct Node*t2=*head2;
    while(t1 && t2)
    {
        if(t1->data<t2->data)
        {
            temp->next=t1;
            t1=t1->next;
        }
        if(t2->data<t1->data)
        {
            temp->next=t2;
            t2=t2->next;
        }
        temp = temp->next;
    }
    if (t1 != NULL) {
        temp->next = t1;
    } else {
        temp->next = t2;
    }
    return dummy->next;
}
int main()
{
    struct Node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 8);
    insertAtEnd(&head, 10);
    printList(head);
    struct Node* head2=NULL;
    insertAtEnd(&head2,4);
    insertAtEnd(&head2,7);
    insertAtEnd(&head2,9);
    printList(head2);
    struct  Node* mergelinked=NULL;
    mergelinked=mergeList(&head,&head2);
    printList(mergelinked);
    
}