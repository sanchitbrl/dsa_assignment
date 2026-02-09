#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// stack structure
typedef struct {
    char arr[MAX];
    int top;
} Stack;

// initialize stack
void init(Stack *s) {
    s->top = -1;
}

// check if the Stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// push element to stack
void push(Stack *s, char ch) {
    if (s->top < MAX - 1) {
        s->arr[++(s->top)] = ch;
    }
}

// pop element from stack
char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return '\0';
}

// checking if the character is opening bracket
int isOpening(char ch) {
    return (ch == '(' || ch == '[' || ch == '{');
}

// checking if the character is closing bracket
int isClosing(char ch) {
    return (ch == ')' || ch == ']' || ch == '}');
}

// checking if opening and closing brackets match
int isMatching(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '[' && close == ']') return 1;
    if (open == '{' && close == '}') return 1;
    return 0;
}

// main function to check balanced parenthesis
int isBalanced(char *expr) {
    int i;
    
    Stack s;
    init(&s);
    
    for (i = 0; i < strlen(expr); i++) {
        char ch = expr[i];
        
        if (isOpening(ch)) {
            push(&s, ch);
        }
        else if (isClosing(ch)) {
            if (isEmpty(&s)) {
                return 0;  // no matching opening bracket
            }
            char top = pop(&s);
            if (!isMatching(top, ch)) {
                return 0;  // brackets dont match
            }
        }
    }
    
    return isEmpty(&s);  // stack should be empty if balanced
}

int main() {
    char expr1[] = "a + (b - c) * (d)";
    char expr2[] = "m + [a - b * (c + d * {m)]";
    char expr3[] = "a + (b - c)";
    
    printf("Testing the Expression 1: %s\n", expr1);
    if (isBalanced(expr1)) {
        printf("Result: BALANCED\n\n");
    } else {
        printf("Result: NOT BALANCED\n\n");
    }
    
    printf("Testing Expression 2: %s\n", expr2);
    if (isBalanced(expr2)) {
        printf("Result: BALANCED\n\n");
    } else {
        printf("Result: NOT BALANCED\n\n");
    }
    
    printf("Testing Expression 3: %s\n", expr3);
    if (isBalanced(expr3)) {
        printf("Result: BALANCED\n\n");
    } else {
        printf("Result: NOT BALANCED\n\n");
    }
    
    return 0;
}
