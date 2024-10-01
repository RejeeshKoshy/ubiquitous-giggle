/*----------------------------
InfixToPostfix.c

Rejeesh Koshy
26-09-2024
----------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define SIZE 25

// Stack structure
typedef struct stackType {
    char oprts[SIZE]; // Stack to hold operators
    int top;
} stack;

stack s; // Global stack instance

// Function prototypes
void InitStack();
void Push(char optr);    // Should use `char` for operators
char Pop();              // Should return `char`
int IsStackEmpty();

char *InfixToPost(char infix[]);
int Precedence(char optr);

int main() {
    char infix[SIZE], *postfix;

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    postfix = InfixToPost(infix);  // Convert infix to postfix
    printf("Postfix expression: %s\n", postfix);

    return 0;
}

//-------------------------------------------
void InitStack() {
    s.top = -1;  // Stack top initialized to -1 (empty)
}

//-------------------------------------------
void Push(char optr) {
    if (s.top == SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    } else {
        s.top++;
        s.oprts[s.top] = optr; // Push operator onto the stack
    }
}

//-------------------------------------------
char Pop() {
    if (s.top == -1) {  // Stack is empty
        printf("Stack Underflow\n");
        return -1; // Return a special value
    } else {
        return s.oprts[s.top--]; // Pop the operator
    }
}

//-------------------------------------------
int IsStackEmpty() {
    return s.top == -1;
}

//-------------------------------------------
int Precedence(char optr) {
    int p = 0;  // Default precedence is 0 (for any undefined operators)
    switch (optr) {
        case '^': 
            p = 5;
            break;
        case '*': case '/': 
            p = 4;
            break;
        case '+': case '-':
            p = 3;
            break;
        case '(':
            p = 2;
            break;
        case ')':
            p = 1;
            break;
    }
    return p;
}

//-------------------------------------------
char *InfixToPost(char infix[]) {
    int i = 0, j = 0;
    char ch, optrStack;
    static char postFix[SIZE]; // Static so it can be returned from the function

    InitStack();  // Initialize the stack

    while ((ch = infix[i]) != '\0') {  // Proper string termination with '\0'
        if (ch == '(') {
            Push(ch);  // Push opening bracket
        } else if ((ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            // If operand (alphanumeric), add to postfix array
            postFix[j++] = ch;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            // Operator: Pop from stack to output postfix until stack is empty or a lower precedence operator is found
            while (!IsStackEmpty() && Precedence(s.oprts[s.top]) >= Precedence(ch)) {
                postFix[j++] = Pop();
            }
            Push(ch);  // Push the current operator onto the stack
        } else if (ch == ')') {
            // Pop until '(' is encountered
            while ((optrStack = Pop()) != '(' && !IsStackEmpty()) {
                postFix[j++] = optrStack;
            }
        }
        i++;
    }

    // Pop remaining operators from the stack
    while (!IsStackEmpty()) {
        postFix[j++] = Pop();
    }

    postFix[j] = '\0';  // Null-terminate the postfix expression
    return postFix;
}
