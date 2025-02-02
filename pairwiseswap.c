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
struct Node* pairWiseSwap(struct Node** head)
{
    struct Node* dummy=createNode(0);
    dummy->next=*head;
    struct Node* front=dummy;
    while(front && front->next && front->next->next)
    {
        struct Node* node1=front->next;
        struct Node* node2=front->next->next;
        node1->next=node2->next;
        node2->next=node1;
        front->next=node2;
        front=node1;
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
    insertAtEnd(&head,15);
    printList(head);
    struct Node* piarWiseSwappedNode=NULL;
    piarWiseSwappedNode=pairWiseSwap(&head);
    printList(piarWiseSwappedNode);
    
}