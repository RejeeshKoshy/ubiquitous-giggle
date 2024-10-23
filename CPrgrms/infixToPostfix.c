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
    char oprts[SIZE];
    int top;
} stack;

stack s; 

// Function prototypes
void InitStack();
void Push(char optr);    
char Pop();              
int IsStackEmpty();

char *InfixToPost(char infix[]);
int Precedence(char optr);

int main() {
    char infix[SIZE], *postfix;

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    postfix = InfixToPost(infix);  
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
        s.oprts[s.top] = optr; 
    }
}

//-------------------------------------------
char Pop() {
    if (s.top == -1) {  
        printf("Stack Underflow\n");
        return -1; 
    } else {
        return s.oprts[s.top--]; 
    }
}

//-------------------------------------------
int IsStackEmpty() {
    return s.top == -1;
}

//-------------------------------------------
int Precedence(char optr) {
    int p = 0;  
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
    static char postFix[SIZE]; 

    InitStack();  

    while ((ch = infix[i]) != '\0') {  
        if (ch == '(') {
            Push(ch);  
        } else if ((ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postFix[j++] = ch;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            while (!IsStackEmpty() && Precedence(s.oprts[s.top]) >= Precedence(ch)) {
                postFix[j++] = Pop();
            }
            Push(ch);
        } else if (ch == ')') {
            while ((optrStack = Pop()) != '(' && !IsStackEmpty()) {
                postFix[j++] = optrStack;
            }
        }
        i++;
    }

    while (!IsStackEmpty()) {
        postFix[j++] = Pop();
    }

    postFix[j] = '\0';
    return postFix;
}