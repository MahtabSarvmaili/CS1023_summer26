# 1. Symbolic Constant vs Global Variable

## Symbolic Constant (`#define`)

A symbolic constant is replaced by the preprocessor before compilation.

```c
#include <stdio.h>

#define PI 3.14

int main()
{
    printf("PI = %.2f\n", PI);

    return 0;
}
```

### Important points

* `PI` is **not stored in memory** as a variable.
* The preprocessor replaces `PI` with `3.14`.
* Its value cannot change.

After preprocessing, the compiler basically sees:

```c
printf("PI = %.2f\n", 3.14);
```

---

## Global Variable

A global variable is a real variable stored in memory.

```c
#include <stdio.h>

int counter = 10;   // global variable

void increase()
{
    counter++;
}

int main()
{
    printf("Before: %d\n", counter);

    increase();

    printf("After: %d\n", counter);

    return 0;
}
```

### Important points

* Stored in memory.
* Has an address.
* Can change during execution.
* Accessible by functions after its declaration.

---

## Main Difference

| Symbolic Constant           | Global Variable          |
| --------------------------- | ------------------------ |
| Replaced before compilation | Stored in memory         |
| No memory address           | Has memory address       |
| Cannot change               | Can change               |
| Created using `#define`     | Created using data types |


### What happens during compilation

The preprocessor replaces PI everywhere before the program becomes machine code:

```c
double x = 3.14;
double y = 3.14 * 2;
```

So the compiler never sees PI.


--- 

# 2. Array of Strings Instead of Characters

A normal string in C is:

```c
char name[] = "Alice";
```

This is an array of characters.

---

## Multiple Strings

To store many strings, use a 2D character array:

```c
#include <stdio.h>

int main()
{
    char fruits[3][20] = {
        "Apple",
        "Banana",
        "Orange"
    };

    printf("%s\n", fruits[0]);
    printf("%s\n", fruits[1]);
    printf("%s\n", fruits[2]);

    return 0;
}
```

---

## Memory Layout

```text
fruits
├── fruits[0] -> "Apple"
├── fruits[1] -> "Banana"
└── fruits[2] -> "Orange"
```

Each row can store up to 19 characters plus `'\0'`.

---

# 3. Why `scanf` for Strings Does Not Need `&`

For integers:

```c
int age;
scanf("%d", &age);
```

`scanf` needs the address of `age`.

---

## For Strings

```c
char name[20];
scanf("%s", name);
```

No `&` is needed.

---

## Why?

Because the array name already represents an address.

`name` means:

```c
&name[0]
```

the address of the first character.

So these are equivalent:

```c
scanf("%s", name);
scanf("%s", &name[0]);
```

---

## Visual Example

```text
name array in memory:

Index:   0   1   2   3   4
Value:  'A' 'l' 'i' 'c' 'e'

name  -----> address of index 0
```

---
## How to Create a List of Strings in C

C does not have a built-in “string list” type. You simulate it using arrays of `char` pointers or 2D character arrays.

### 1. Array of pointers (most common)

Each element is a pointer to a string literal or dynamically allocated string.

```c
#include <stdio.h>

int main() {
    const char *list[] = {
        "apple",
        "banana",
        "cherry"
    };

    int n = 3;

    for (int i = 0; i < n; i++) {
        printf("%s\n", list[i]);
    }

    return 0;
}
```

**Key point:**

* `list` is an array of pointers (`const char *`)
* Strings are not copied; pointers reference existing string literals


### 2. 2D character array (fixed-size storage)

Here strings are stored inside a contiguous block.

```c
#include <stdio.h>

int main() {
    char list[3][10] = {
        "apple",
        "banana",
        "cat"
    };

    for (int i = 0; i < 3; i++) {
        printf("%s\n", list[i]);
    }

    return 0;
}
```

**Key point:**

* Each string has fixed max length (10 here)
* Data is stored directly in memory, not pointers


---

# 4. Why Array Name Acts Like a Pointer

Consider:

```c
int numbers[5] = {10, 20, 30, 40, 50};
```

The array is stored in consecutive memory locations.

Example:

```text
Address      Value
1000         10
1004         20
1008         30
1012         40
1016         50
```

Suppose:

```c
numbers == 1000
```

because it points to the first element.

---

## Example

```c
#include <stdio.h>

int main()
{
    int numbers[5] = {10, 20, 30, 40, 50};

    printf("%p\n", numbers);
    printf("%p\n", &numbers[0]);

    return 0;
}
```

Both print the same address.

---

# 5. What Happens When We Add Integers to Array Name

```c
numbers + 1
```

does NOT mean “add 1 byte”.

It means:

```text
move to next integer
```

Since an `int` is usually 4 bytes:

```text
numbers     -> address 1000
numbers + 1 -> address 1004
numbers + 2 -> address 1008
```

---

## Example

```c
#include <stdio.h>

int main()
{
    int numbers[5] = {10, 20, 30, 40, 50};

    printf("%d\n", *numbers);        // 10
    printf("%d\n", *(numbers + 1));  // 20
    printf("%d\n", *(numbers + 2));  // 30

    return 0;
}
```

---

## Important Concept

These are equivalent:

```c
numbers[2]
```

and

```c
*(numbers + 2)
```

because array indexing internally uses pointer arithmetic.

---

# Key Idea

Array name behaves like a constant pointer to the first element.

```text
numbers
   ↓
+----+----+----+----+----+
| 10 | 20 | 30 | 40 | 50 |
+----+----+----+----+----+
```

But unlike normal pointers, you cannot change the array name:

```c
numbers = numbers + 1; // ERROR
```

because the array address itself is fixed.

---

# In C, you cannot return a normal array directly from a function because arrays are not first-class return values. Instead

## 1. Return a Pointer to Dynamically Allocated Memory

Most common when the array size is determined at runtime.

```c
#include <stdio.h>
#include <stdlib.h>

int* createArray(int size) {
    int* arr = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        arr[i] = i * 10;
    }

    return arr;
}

int main() {
    int size = 5;

    int* numbers = createArray(size);

    for (int i = 0; i < size; i++) {
        printf("%d\n", numbers[i]);
    }

    free(numbers);

    return 0;
}
```

Key points:

* `malloc` allocates memory on the heap.
* The memory survives after the function ends.
* You must call `free()` later.

---

## 2. Pass the Array Into the Function

Very common in C.

```c
#include <stdio.h>

void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
}

int main() {
    int numbers[5];

    fillArray(numbers, 5);

    for (int i = 0; i < 5; i++) {
        printf("%d\n", numbers[i]);
    }

    return 0;
}
```

Key idea:

* Arrays decay into pointers when passed to functions.
* The function modifies the original array.

---

# 3. Return a Struct Containing an Array

Useful for fixed-size arrays.

```c
#include <stdio.h>

typedef struct {
    int data[5];
} ArrayStruct;

ArrayStruct createArray() {
    ArrayStruct arr = {{1, 2, 3, 4, 5}};
    return arr;
}

int main() {
    ArrayStruct result = createArray();

    for (int i = 0; i < 5; i++) {
        printf("%d\n", result.data[i]);
    }

    return 0;
}
```

This works because structs can be returned by value.

---

### What You Must NOT Do

This is incorrect:

```c
int* badFunction() {
    int arr[5] = {1,2,3,4,5};
    return arr;   // WRONG
}
```

Why:

* `arr` is a local stack variable.
* It disappears after the function returns.
* The returned pointer becomes invalid (dangling pointer).

---

### Summary

| Method                         | Use Case          | Safe |
| ------------------------------ | ----------------- | ---- |
| Return `malloc` pointer        | Dynamic arrays    | Yes  |
| Pass array into function       | Preferred/simple  | Yes  |
| Return struct containing array | Fixed-size arrays | Yes  |
| Return local array pointer     | Never             | No   |

