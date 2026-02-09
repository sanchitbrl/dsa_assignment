# prog_2

## Data Structures Used

### Character Stack (for conversion)
```c
typedef struct {
    char arr[MAX];
    int top;
} CharStack;
```
- Used to store operators during infix to postfix conversion
- Follows LIFO principle

### Integer Stack (for evaluation)
```c
typedef struct {
    int arr[MAX];
    int top;
} IntStack;
```
- Used to store operands during postfix evaluation
- Also follows LIFO principle

## Functions Implemented

### Character Stack Functions
1. **initChar()** - Initialize character stack
2. **isEmptyChar()** - Check if stack is empty
3. **pushChar()** - Push character to stack
4. **popChar()** - Pop character from stack
5. **peekChar()** - View top element without removing

### Integer Stack Functions
1. **initInt()** - Initialize integer stack
2. **isEmptyInt()** - Check if stack is empty
3. **pushInt()** - Push integer to stack
4. **popInt()** - Pop integer from stack

### Utility Functions
1. **precedence(char op)** - Returns precedence of operator
   - +, - have precedence 1
   - *, / have precedence 2
   - ^ has precedence 3

2. **isOperator(char ch)** - Checks if character is an operator

### Main Functions
1. **infixToPostfix(char *infix, char *postfix)**
   - Converts infix expression to postfix
   - Algorithm:
     - Scan expression left to right
     - If operand, add to output
     - If '(', push to stack
     - If ')', pop until '(' found
     - If operator, pop operators with higher/equal precedence, then push current
     - At end, pop all remaining operators

2. **evaluatePostfix(char *postfix)**
   - Evaluates postfix expression
   - Algorithm:
     - Scan expression left to right
     - If operand, push to stack
     - If operator, pop two operands, apply operation, push result
     - Final value in stack is the answer

## Main Function Organization

1. Declares character arrays for infix and postfix expressions
2. Tests three different expressions:
   - Simple expression: 3+5*2
   - Expression with parentheses: (3+5)*2
   - Complex expression: 2+3*4-5
3. For each expression:
   - Converts to postfix
   - Evaluates the result
   - Prints all steps

## Sample Output

```
Infix to Postfix Conversion and Evaluation
===========================================

Infix Expression: 3+5*2
Postfix Expression: 352*+
Evaluation Result: 13

Infix Expression: (3+5)*2
Postfix Expression: 35+2*
Evaluation Result: 16

Infix Expression: 2+3*4-5
Postfix Expression: 234*+5-
Evaluation Result: 9
```

## How It Works

**Conversion**: We use operator precedence to decide when to pop operators from stack. Higher precedence operators are evaluated first.

**Evaluation**: We scan postfix left to right. Numbers go to stack. When we see operator, we pop two numbers, do the operation, and push result back.

Example: 352*+ 
- Push 3, push 5, push 2
- See *, pop 2 and 5, compute 5*2=10, push 10
- See +, pop 10 and 3, compute 3+10=13
- Result: 13