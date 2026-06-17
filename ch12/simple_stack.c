#include <stdio.h>
#include <stdlib.h>

struct stack {
    int data;
    struct stack *next;
};

void push(struct stack **head, int);
void pop(struct stack **head);
void printStack(struct stack *head);

int main(void)
{
    struct stack *head = NULL;
    int a[5] = {1,3,2,5,4};

    for (size_t i = 0; i < 5; i++) {
        push(&head, a[i]);
    }
    printStack(head);
    pop(&head);
    printStack(head);
}

void push(struct stack **head, int data)
{
    struct stack *newNode = malloc(sizeof(struct stack));

    if (newNode != NULL){
        newNode->data = data;
        newNode->next = * head;
        *head = newNode;
    }
    else {
        printf("Memory allocation failed. Unable to push %d onto the stack.\n", data);
    }
}

void pop(struct stack **head)
{
    if (*head == NULL) {
        printf("Stack underflow. Unable to pop from an empty stack.\n");
        return;
    }
    struct stack *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void printStack(struct stack *head)
{
    struct stack *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}