**prog_1.c**

---

### Aim

To check whether an expression has balanced brackets using a stack.

---

### Data Structure Used

**Stack**

```c
typedef struct {
    char arr[MAX];
    int top;
} Stack;
```

* `arr` stores the brackets.
* `top` shows the position of the top element.
* Stack works on **LIFO** (Last In First Out) rule.

---

### Functions Used

1. **`void init(Stack *s)`**
   Initializes the stack by setting `top = -1`.

2. **`int isEmpty(Stack *s)`**
   Returns 1 if stack is empty, otherwise returns 0.

3. **`void push(Stack *s, char ch)`**
   Adds a character to the stack.

4. **`char pop(Stack *s)`**
   Removes and returns the top element from the stack.

5. **`int isOpening(char ch)`**
   Checks if the character is an opening bracket: `(` `{` `[`.

6. **`int isClosing(char ch)`**
   Checks if the character is a closing bracket: `)` `}` `]`.

7. **`int isMatching(char open, char close)`**
   Checks if the opening and closing brackets match.

8. **`int isBalanced(char *expr)`**
   Main function that checks if the expression is balanced using stack logic.

---

### Logic Used

* If an opening bracket is found, push it into the stack.
* If a closing bracket is found, pop from stack and check if it matches.
* If stack is empty at the end, the expression is **balanced**.
* If mismatch occurs or stack is not empty, the expression is **not balanced**.

---

### Main Function

* Three expressions are tested.
* Each expression is passed to `isBalanced()`.
* The result is printed as **BALANCED** or **NOT BALANCED**.

---

### Sample Output

```
Testing Expression 1: a + (b - c) * (d)
Result: BALANCED

Testing Expression 2: m + [a - b * (c + d * {m)]
Result: NOT BALANCED

Testing Expression 3: a + (b - c)
Result: BALANCED
```

---
