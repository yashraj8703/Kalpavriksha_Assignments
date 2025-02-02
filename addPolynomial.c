#include <stdio.h>
#include <stdlib.h>

struct Node{
    int coeff;
    int power;
    struct Node* next;
};
struct Node* createNode(int coeff,int power)
{
    struct Node* Node=(struct Node*)malloc(sizeof(struct Node));
    Node->coeff=coeff;
    Node->power=power;
    Node->next=NULL;
    return Node;
}
void insertAtEnd(struct Node** head,int coeff,int power)
{
    struct Node* newnode=createNode(coeff,power);
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
        printf("%d|%d -> ", temp->coeff,temp->power);
        temp = temp->next;
    }
    printf("NULL\n");
}
struct Node* addPolynomial(struct Node** head1,struct Node** head2)
{
    struct Node* dummy=createNode(-1,-1);
    struct Node* temp=dummy;
    struct Node* t1=*head1;
    struct Node* t2=*head2;
    while(t1 && t2)
    {
        if(t1->power>t2->power)
        {
            temp->next=t1;
            t1=t1->next;
        }
        else if(t1->power<t2->power)
        {
            temp->next=t2;
            t2=t2->next;
        }
        else if(t1->power==t2->power)
        {
            temp->next = createNode(t1->coeff + t2->coeff, t1->power);
            t1 = t1->next;
            t2 = t2->next;
        }
        temp=temp->next;
    }
    if (t1 != NULL) {
    temp->next = t1;
    }
    if (t2 != NULL) {
        temp->next = t2;
    }
    return dummy->next;
}

int main()
{
    struct Node* head = NULL;
    insertAtEnd(&head, 5,2);
    insertAtEnd(&head, 4,1);
    insertAtEnd(&head,2,0);
    printList(head);
    struct Node* head2=NULL;
    insertAtEnd(&head2, 5,1);
    insertAtEnd(&head2, 7,0);
    insertAtEnd(&head2, 11,3);
    printList(head2);
    struct Node* newnode=NULL;
    newnode=addPolynomial(&head,&head2);
    printList(newnode);
    
}