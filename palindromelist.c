#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data)
{
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
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

void printList(struct Node* head)
{
    struct Node* temp=head;
    while(temp)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
struct Node* reverseLinkedlist(struct Node** head)
{
    struct Node* prev=NULL;
    struct Node* front=*head;
    struct Node* curr=front->next;
    while(curr)
    {
       struct Node* temp=curr->next;
        front->next=prev;
        curr->next=front;
        prev=front;
        front=curr;
        curr=temp;
        
    }
    return front;
}
int isPalindrome(struct Node** head)
{
    struct Node* slow=*head;
    struct Node* fast=*head;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    struct Node* secondHalf=reverseLinkedlist(&slow);
    struct Node* firstHalf=*head;
    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data) {
            return 0; 
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return 1;  
}
int main()
{
    struct Node* head=NULL;
    insertAtEnd(&head,1);
    insertAtEnd(&head,3);
    insertAtEnd(&head,3);
    insertAtEnd(&head,3);
    insertAtEnd(&head,1);
    printList(head);
    if(isPalindrome(&head))
    {
        printf("List is palindrome");
    }
    else{
        printf("List is not palindrome");
    }
}