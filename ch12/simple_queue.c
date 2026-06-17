#include <stdio.h>
#include <stdlib.h>

struct queue {
    int data;
    struct queue *next;
};

void enqueue(struct queue **head, int data);
void dequeue(struct queue **head);
void printQueue(struct queue *head);
void enqueue2(struct queue **headptr, struct queue **lastptr, int data);
void dequeue2(struct queue **headptr, struct queue **lastptr);
void freeQueue(struct queue *head);

int main(void)
{
    struct queue *head = NULL;
    int a[5] = {1,3,2,5,4};

    for (size_t i = 0; i < 5; i++) {
        enqueue(&head, a[i]);
    }
    printQueue(head);
    dequeue(&head);
    printQueue(head);
    freeQueue(head);

    free(head);

    struct queue *last = NULL;
    struct queue *head = NULL;
    for (size_t i = 0; i < 5; i++) {
        enqueue2(&head, &last, a[i]);
    }
    enqueue2(&head, &last, 6);
    printQueue(head);
    dequeue2(&head, &last);
    printQueue(head);
}

void enqueue(struct queue **head, int data)
{
    struct queue *newNode = malloc(sizeof(struct queue));
    struct queue *current = NULL;

    if (newNode!=NULL)
    {
        newNode->data = data;
        newNode->next = NULL;

        if (*head == NULL) {
            *head = newNode;
        } else {
            current = *head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    else {
        printf("Memory allocation failed. Unable to enqueue %d into the queue.\n", data);
    }
}

void dequeue(struct queue **head)
{
    if (*head==NULL){
        printf("Queue underflow. Unable to dequeue from an empty queue.\n");
        return;
    }
    struct queue *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void enqueue2(struct queue **headptr, struct queue **lastptr, int data)
{
    // allocate memory for the new node
    struct queue *newNode = malloc(sizeof(struct queue));
    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->next = NULL;
        if (*headptr==NULL)
        {
            printf("Enqueuing2222 %d into the empty queue.\n", data);
            *headptr = newNode;
            *lastptr = newNode;
        } else {
            printf("Enqueuing2222 %d into the non-empty queue.\n", data);
            (*lastptr)->next = newNode;
            *lastptr = newNode;
        }
    }
}


void dequeue2(struct queue **headptr, struct queue **lastptr)
{
    if (*headptr==NULL){
        printf("Queue underflow. Unable to dequeue from an empty queue.\n");
        return;
    }
    struct queue *temp = *headptr;
    *headptr = (*headptr)->next;
    if (*headptr==NULL)
    {
        *lastptr=NULL;
    }
    free(temp);
}

void printQueue(struct queue *head)
{
    struct queue *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeQueue(struct queue *head)
{
    struct queue *currentNode = head;
    while (currentNode != NULL) {
        struct queue *temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }
}