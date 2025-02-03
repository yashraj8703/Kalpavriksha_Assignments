#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    int marks;
    int roll;
    char name[50];
    struct Node* next;
};
struct Node* createNode(int marks,int roll,char str[]){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->marks=marks;
    newnode->roll=roll;
    strcpy(newnode->name,str);
    newnode->next=NULL;
    return newnode;
    
}
struct Node* insertAtend(struct Node** head,int marks,int roll,char str[])
{
    struct Node*newnode=createNode(marks,roll,str);
    if(*head==NULL)
    {
        *head=newnode;
        return *head;
        
    }
    struct Node*temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    return *head;
}
void listofstudent(struct Node** head)
{
   struct Node* current=*head;
   for (struct Node* i = current; i != NULL; i = i->next)
   {
        for (struct Node* j = i->next; j != NULL; j = j->next)
        {
            if (i->marks > j->marks)
            {
                int tempMarks = i->marks;
                int tempRoll = i->roll;
                char tempName[50];
                strcpy(tempName, i->name); 
                i->marks = j->marks;
                i->roll = j->roll;
                strcpy(i->name, j->name); 
                j->marks = tempMarks;
                j->roll = tempRoll;
                strcpy(j->name, tempName);
            }
            else if(i->marks==j->marks)
            {
                if (i->roll > j->roll) {
                int tempMarks = i->marks;
                int tempRoll = i->roll;
                char tempName[50];
                strcpy(tempName, i->name); 
                i->marks = j->marks;
                i->roll = j->roll;
                strcpy(i->name, j->name); 
                j->marks = tempMarks;
                j->roll = tempRoll;
                strcpy(j->name, tempName);
                
            }
        }
    }
}
    struct Node* temp=*head;
    while(temp!=NULL)
    {
        printf("%d %d %s",temp->marks,temp->roll,temp->name);
        temp=temp->next;
        printf("\n");
    }
    
}
int main()
{
    // struct Node* head=NULL;
    // insertAtend(&head,85,103,"alice");
    // insertAtend(&head,90,101,"bob");
    // insertAtend(&head,85,102,"oswald");
    // insertAtend(&head,95,105,"rocko");
    // listofstudent(&head);
    struct Node* head = NULL;
    int choice, marks, roll;
    char name[50];

    do {
        printf("1. Insert student\n");
        printf("2. Display sorted list of students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter marks: ");
                scanf("%d", &marks);
                printf("Enter roll number: ");
                scanf("%d", &roll);
                printf("Enter name: ");
                scanf(" %[^\n]s", name);
                insertAtend(&head, marks, roll, name);
                break;

            case 2:
                listofstudent(&head);
                break;

            case 3: 
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}