#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
        char movie_name[50];
        int amount;
        int seat;
        int status;
};
struct Node* createNode(char movie_name[],int amount,int seat,int status)
{
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    strcpy(newnode->movie_name,movie_name);
    newnode->amount=amount;
    newnode->seat=seat;
    newnode->status=status;
    return newnode;
}
struct Queue{
    int size;
    int front;
    int rear;
    struct Node** arr;
};
struct Queue* createQueue(int size)
{
    struct Queue* Queue = (struct Queue*)malloc(sizeof(struct Queue));
    Queue->size = size;
    Queue->front = -1;
    Queue->rear = -1;
    Queue->arr = (struct Node**)malloc(Queue->size * sizeof(struct Node*)); 
    return Queue;
}
int isFull(struct Queue* Queue) {
    return Queue->rear == Queue->size - 1;
}

int isEmpty(struct Queue* Queue) {
    return Queue->front == -1;
}

void Push(struct Queue* Queue, struct Node* newnode) {
    if (isFull(Queue)) {
        printf("Queue is Full\n");
        return;
    }
    if (Queue->front == -1) {
        Queue->front = 0;
    }
    Queue->rear++;
    Queue->arr[Queue->rear] = newnode;
}

struct Node* pop(struct Queue* Queue) {
    if (isEmpty(Queue)) {
        printf("Queue is Empty\n");
        return NULL;
    }
    struct Node* value = Queue->arr[Queue->front];
    Queue->front++;
    
    if (Queue->front > Queue->rear) {
        Queue->front = Queue->rear = -1;
    }
    return value;
}
void PrintQueue(struct Queue* Queue) {
    if (isEmpty(Queue)) {
        printf("Queue is Empty\n");
        return;
    }
    for (int i = Queue->front; i <= Queue->rear; i++) {
        printf("Movie: %s, Amount: %d, Seat: %d, Status: %d\n",
            Queue->arr[i]->movie_name, Queue->arr[i]->amount, Queue->arr[i]->seat, Queue->arr[i]->status);
    }
    printf("\n");
}
void ApprovedQueueFunction(struct Queue* BookingQueue,struct Queue* ApprovedQueue)
{
    struct Node* value=pop(BookingQueue);
    value->status=1;
    Push(ApprovedQueue,value);
}
void menu() {
    printf("\n--- Movie Booking System ---\n");
    printf("1. Add a Movie Booking\n");
    printf("2. Approve a Booking\n");
    printf("3. Display Booking Queue\n");
    printf("4. Display Approved Queue\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}
int main()
{
    struct Queue* BookingQueue = createQueue(5);
    struct Queue* ApprovedQueue=createQueue(5);
    
    // struct Node* node1 = createNode("Movie1", 100, 50, 0);
    // struct Node* node2 = createNode("Movie2", 150, 75, 0);
    
    // Push(BookingQueue, node1);
    // Push(BookingQueue, node2);
    // ApprovedQueueFunction(BookingQueue,ApprovedQueue);
    // ApprovedQueueFunction(BookingQueue,ApprovedQueue);
    // PrintQueue(ApprovedQueue);
    // PrintQueue(BookingQueue);
    int choice;
    char movie_name[50];
    int amount, seat;

    while (1) {
        menu();
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1: 
                printf("Enter movie name: ");
                fgets(movie_name, sizeof(movie_name), stdin);
                movie_name[strcspn(movie_name, "\n")] = '\0';

                printf("Enter amount: ");
                scanf("%d", &amount);

                printf("Enter number of seats: ");
                scanf("%d", &seat);

                struct Node* newMovie = createNode(movie_name, amount, seat, 0);
                Push(BookingQueue, newMovie);
                printf("Movie Booking added to the queue!\n");
                break;

            case 2: 
                ApprovedQueueFunction(BookingQueue, ApprovedQueue);
                printf("Booking approved and moved to the Approved Queue.\n");
                break;

            case 3: 
                printf("\n--- Booking Queue ---\n");
                PrintQueue(BookingQueue);
                break;

            case 4:  
                printf("\n--- Approved Queue ---\n");
                PrintQueue(ApprovedQueue);
                break;

            case 5: 
                printf("Exiting the program...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}