#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// stack for characters (For conversion)
typedef struct {
    char arr[MAX];
    int top;
} CharStack;

// stack for integers (For evaluation)
typedef struct {
    int arr[MAX];
    int top;
} IntStack;

// initialize char stack
void initChar(CharStack *s) {
    s->top = -1;
}

// check if char stack is empty
int isEmptyChar(CharStack *s) {
    return s->top == -1;
}

// push to char stack
void pushChar(CharStack *s, char ch) {
    if (s->top < MAX - 1) {
        s->arr[++(s->top)] = ch;
    }
}

// pop from char stack
char popChar(CharStack *s) {
    if (!isEmptyChar(s)) {
        return s->arr[(s->top)--];
    }
    return '\0';
}

// peek top of char stack
char peekChar(CharStack *s) {
    if (!isEmptyChar(s)) {
        return s->arr[s->top];
    }
    return '\0';
}

// initialize int stack
void initInt(IntStack *s) {
    s->top = -1;
}

// check if int stack is empty
int isEmptyInt(IntStack *s) {
    return s->top == -1;
}

// push to int  stack
void pushInt(IntStack *s, int val) {
    if (s->top < MAX - 1) {
        s->arr[++(s->top)] = val;
    }
}

// pop from int stack
int popInt(IntStack *s) {
    if (!isEmptyInt(s)) {
        return s->arr[(s->top)--];
    }
    return 0;
}

// get precedence of operator
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// check if character is operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// convert infix to postfix
void infixToPostfix(char *infix, char *postfix) {
    CharStack s;
    initChar(&s);
    int i, j = 0;
    
    for (i = 0; i < strlen(infix); i++) {
        char ch = infix[i];
        
        // skip spaces
        if (ch == ' ') continue;
        
        // if operand, add to output
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // if opening parenthesis, push to stack
        else if (ch == '(') {
            pushChar(&s, ch);
        }
        // if closing parenthesis, pop until opening parenthesis
        else if (ch == ')') {
            while (!isEmptyChar(&s) && peekChar(&s) != '(') {
                postfix[j++] = popChar(&s);
            }
            popChar(&s); // remove opening parenthesis
        }
        // if operator
        else if (isOperator(ch)) {
            while (!isEmptyChar(&s) && precedence(peekChar(&s)) >= precedence(ch)) {
                postfix[j++] = popChar(&s);
            }
            pushChar(&s, ch);
        }
    }
    
    // pop remaining operators
    while (!isEmptyChar(&s)) {
        postfix[j++] = popChar(&s);
    }
    
    postfix[j] = '\0';
}

// evaluate postfix expression
int evaluatePostfix(char *postfix) {
    IntStack s;
    initInt(&s);
    int i;
    
    for (i = 0; i < strlen(postfix); i++) {
        char ch = postfix[i];
        
        // if operand, push to stack
        if (isdigit(ch)) {
            pushInt(&s, ch - '0');
        }
        // if operator, pop two operands and apply operation
        else if (isOperator(ch)) {
            int op2 = popInt(&s);
            int op1 = popInt(&s);
            int result, k;
            
            switch(ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': {
                    result = 1;
                    for (k = 0; k < op2; k++) {
                        result *= op1;
                    }
                    break;
                }
                default: result = 0;
            }
            
            pushInt(&s, result);
        }
    }
    
    return popInt(&s);
}

int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Infix to Postfix Conversion and Evaluation\n");
    printf("===========================================\n\n");
    
    // Example 1
    strcpy(infix, "3+5*2");
    printf("Infix Expression: %s\n", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    printf("Evaluation Result: %d\n\n", evaluatePostfix(postfix));
    
    // Example 2
    strcpy(infix, "(3+5)*2");
    printf("Infix Expression: %s\n", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    printf("Evaluation Result: %d\n\n", evaluatePostfix(postfix));
    
    // Example 3
    strcpy(infix, "2+3*4-5");
    printf("Infix Expression: %s\n", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    printf("Evaluation Result: %d\n\n", evaluatePostfix(postfix));
    
    return 0;
}
