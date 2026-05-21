
---

# 1. `auto` (default local variable, block scope, stack storage)

```c
#include <stdio.h>

void demo_auto() {
    int x = 10;   // auto is implicit
    printf("x = %d\n", x);
}
```

Key points:

* block scope
* exists only during function call
* stored on stack

---

# 2. `register` (hint to CPU register, no address)

```c
#include <stdio.h>

void demo_register() {
    register int i;

    for (i = 0; i < 5; i++) {
        printf("%d ", i);
    }

    // printf("%p", &i); // ❌ not allowed (may fail)
}
```

Key points:

* cannot take address (`&i`)
* compiler may ignore suggestion

---

# 3. `static` local variable (persistent state)

```c
#include <stdio.h>

void counter() {
    static int count = 0;  // static storage duration
    count++;
    printf("count = %d\n", count);
}

int main() {
    counter();
    counter();
    counter();
}
```

Expected output:

```
count = 1
count = 2
count = 3
```

Key points:

* scope: inside function
* lifetime: entire program
* stored in static/data segment (not stack)

---

# 4. `static` global (file scope restriction = internal linkage)

```c
// file: a.c
#include <stdio.h>

static int secret = 42;  // only visible in this file

void print_secret() {
    printf("%d\n", secret);
}
```

```c
// file: b.c
// extern int secret; ❌ not accessible here
```

Key points:

* limits visibility to current file
* prevents external linkage

---

# 5. `extern` (cross-file global access)

```c
// file: a.c
int shared = 100;
```

```c
// file: b.c
#include <stdio.h>

extern int shared;

void show() {
    printf("%d\n", shared);
}
```

Key points:

* declares variable defined elsewhere
* no new storage created

---

# 6. Static function (internal linkage)

```c
// file: utils.c
#include <stdio.h>

static void helper() {
    printf("internal helper\n");
}

void public_api() {
    helper();
}
```

```c
// file: main.c
// helper() ❌ not visible here
```

Key points:

* function restricted to file
* improves encapsulation

---

# 7. Scope example (block vs file scope)

```c
#include <stdio.h>

int global = 10;  // file scope

void test() {
    int local = 5; // block scope

    printf("%d %d\n", global, local);
}
```

Key points:

* `global` → file scope
* `local` → block scope

---

# 8. Function scope (labels with `goto`)

```c
#include <stdio.h>

void label_demo() {

    int x = 1;

    if (x == 1) {
        goto skip;
    }

    printf("This will be skipped\n");

skip:   // label (function scope)
    printf("Reached label\n");
}
```

Key points:

* labels visible anywhere in function
* only used with `goto`

---

# 9. Combined mini program (all concepts together)

```c
#include <stdio.h>

int global_var = 10;
static int file_private = 20;

void demo() {
    static int persistent = 0;
    register int i;

    persistent++;

    for (i = 0; i < 2; i++) {
        printf("i=%d persistent=%d global=%d file_private=%d\n",
               i, persistent, global_var, file_private);
    }

label:
    if (persistent < 3)
        goto label;
}

int main() {
    demo();
    demo();
}
```
---
### Memory layout of a C program (for reference):

```
+-------------------+
|   Code Segment    |
+-------------------+
| Global/Static     |
| Variables         |
+-------------------+
|       Heap        |
|   (malloc/free)   |
+-------------------+
|       Stack       |
| Function Calls    |
| Local Variables   |
+-------------------+
```

---
What it demonstrates:

* `global_var` → file scope + external linkage
* `file_private` → static global (internal linkage)
* `persistent` → static local (static storage duration)
* `register` → loop optimization hint
* `label` → function scope
* stack vs static memory behavior indirectly

---

# Clean conceptual summary

* **auto/local** → stack, temporary
* **static local** → persistent memory, same scope
* **global** → file scope, external linkage
* **static global/function** → file-restricted (internal linkage)
* **extern** → cross-file access
* **labels** → function-wide visibility only for `goto`

---

If needed, I can convert this into a **single teaching worksheet with diagrams of memory + stack frames + execution flow**.
