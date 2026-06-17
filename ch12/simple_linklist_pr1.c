#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert(struct node **head, int data);
void delete(struct node **head, int data);
int isEmpty(struct node *head); // for the isEmpty and printLinkList we don't need to pass the 
void printLinkList(struct node *head);

int main(void)
{
    struct node *head = NULL;
    int a[10] = {1,3,2,5,4, 10, 8, 7, 6, 9};

    for (size_t i = 0; i < 10; i++) {
        insert(&head, a[i]);
        printLinkList(head);
    }

    printLinkList(head);
    printf("Deleting 5 from the linked list...\n");
    delete(&head, 5);
    printLinkList(head);
}

void insert(struct node **head, int data)
{
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->next =NULL;

        // we need to add the new node in the correct position in the linked list
        struct node *prevNode = NULL;
        struct node *currentNode = *head;

        while (currentNode !=NULL && currentNode->data < data)
        {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
        if (prevNode ==NULL){
            // we assign the new Node as head of the linked List
            // and then the head that we return from the main function will point to the new node that we just created
            newNode->next = *head;
            *head = newNode;
        } else {
            prevNode->next = newNode;
            newNode->next = currentNode;
        }
    }
}

void printLinkList(struct node *head){
    struct node *currentNode = head;
    printf("Linked List: ");
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}



void delete(struct node **head, int data)
{
    struct node *prevNode = NULL;
    struct node *currentNode = *head;
    
    while (currentNode != NULL && currentNode->data != data) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    if (currentNode == NULL) {
        printf("Data %d not found in the linked list.\n", data);
        return;
    }

    if (prevNode == NULL) {
        // Deleting the head node
        *head = currentNode->next;
    } else {
        prevNode->next = currentNode->next;
    }
    free(currentNode);
}

int isEmpty(struct node *head){
    return head == NULL;
} 