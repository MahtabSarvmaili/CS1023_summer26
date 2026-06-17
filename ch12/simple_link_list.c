#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert(struct node **head, int data);
void printLinkList(struct node *head);

int main(void){

    struct node *head = NULL;
    int a[5] = {1,3,2,5,4};

    for (size_t i = 0; i < 5; i++) {
        // if we don't send the address of head, we will be passing the value of head which is NULL and we won't be able to modify the head pointer in the insert function
        insert(&head, a[i]);
        printLinkList(head);
    }

    printLinkList(head);
}

void insert(struct node **head, int data){
    // first we need to allocate memory for the new node
    // because we need to need to first create the container
    struct node *newNode = malloc(sizeof(struct node));
    
    // then we need to check if the memory allocation was successful
    // if the memory allocation was successful, we can proceed to insert the new node
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
        // then we need to create two pointters to traverse the linked list
        struct node *prevNode = NULL;
        struct node *currentNode = *head;
        printf("Inserting %d into the linked list...\n", data);

        while (currentNode !=NULL && currentNode->data < newNode->data){
            prevNode = currentNode;
            currentNode = currentNode->next;
            // printing the current node and prev node
            if (prevNode != NULL) {
                printf("Current node: %d, Previous node: %d\n", currentNode != NULL ? currentNode->data : -1, prevNode->data);
            } else {
                printf("Current node: %d, Previous node: NULL\n", currentNode != NULL ? currentNode->data : -1);
            }
        }
        // just in case if we are inserting the first node at the begining of the linked list
        if (prevNode == NULL) {
            printf("Inserting %d at the beginning of the linked list.\n", data);
            newNode->next = *head;
            *head = newNode;
        } else {
            prevNode->next = newNode;  
            newNode->next = currentNode;
        }
    }
    else {
        printf("Memory allocation failed for new node with data: %d\n", data);
    }
}

void printLinkList(struct node *head){
    struct node *currentNode = head;

    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}


/**
 * `head` is a **pointer to a pointer**.

Let's start with the normal case.

---

## 1. `struct node *head`

Suppose:

```c
struct node *head = NULL;
```

Memory looks like:

```
head
 |
 v
NULL
```

`head` is a variable whose value is an address of a `struct node`.

Type:

```c
struct node *
```

---

## 2. `&head`

The `&` operator means "address of".

If we write:

```c
&head
```

we are asking:

> What is the memory address where the variable `head` itself is stored?

Diagram:

```
+-------+
| head  | -----> NULL
+-------+
    ^
    |
  &head
```

Type:

```c
struct node **
```

because it is the address of a `struct node *`.

---

## 3. What does `*head` mean inside `insert()`?

Suppose we define:

```c
void insert(struct node **head, int data)
```

and call:

```c
insert(&head, 5);
```

Then:

```
main:

head
 |
 v
NULL
```

Inside `insert`:

```
head
 |
 v
(address of main's head)
```

So:

```c
*head
```

means:

> Go to the address stored in `head` and retrieve the value there.

That value is the original pointer from `main`.

Therefore:

```c
*head
```

is exactly the same as the `head` variable in `main`.

---

## Example

Before:

```c
struct node *head = NULL;

insert(&head, 5);
```

Inside `insert`:

```c
*head == NULL
```

Now:

```c
*head = newNode;
```

is equivalent to:

```c
head = newNode;
```

in `main`.

After:

```
main:

head
 |
 v
+------+------+
|  5   | NULL |
+------+------+
```

---

## Visualizing the stars

### One star

```c
struct node *head;
```

```
head -----> node
```

Read as:

> head points to a node

---

### Two stars

```c
struct node **head;
```

```
head -----> head -----> node
```

Read as:

> head points to a pointer that points to a node

or

> pointer to pointer to node

---

## Why use `**head`?

Because you want to change the original pointer.

This won't work:

```c
void f(struct node *head)
{
    head = newNode;
}
```

because only a copy changes.

This works:

```c
void f(struct node **head)
{
    *head = newNode;
}
```

because you're modifying the actual pointer owned by the caller.

---

A useful rule:

* `node *p` → `p` is a pointer to a node.
* `node **p` → `p` is a pointer to a pointer to a node.
* `*p` removes one level of indirection.

So if:

```c
struct node **head;
```

then:

```c
*head      // struct node *
(**head)   // struct node (actual node)
```

which is exactly why you often see linked-list code using `(*head)->data`:

```c
(*head)->data
```

because:

1. `head` is `struct node **`
2. `*head` becomes `struct node *`
3. `(*head)->data` accesses the node's `data` field.

**/