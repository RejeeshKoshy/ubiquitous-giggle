/*----------------------------
postFix.c

Rejeesh Koshy
----------------------------*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 100

// Stack structure
typedef struct {
    int items[SIZE];
    int top;
} Stack;

void initStack(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int evaluatePostfix(char* expr);

int main() {
    char expr[SIZE];
    
    printf("Enter a postfix expression: ");
    scanf("%s", expr);

    int result = evaluatePostfix(expr);
    printf("The result is: %d\n", result);

    return 0;
}

void initStack(Stack *s) { s->top = -1; }

int isEmpty(Stack *s) { return s->top == -1; }

void push(Stack *s, int value) { s->items[++s->top] = value; }

int pop(Stack *s) { return s->items[s->top--]; }

int evaluatePostfix(char* expr) {
    Stack s;
    initStack(&s);

    for (int i = 0; expr[i] != '\0'; i++) {
        if (isdigit(expr[i])) {
            push(&s, expr[i] - '0');  
        }
        else {
            int val2 = pop(&s);
            int val1 = pop(&s);

            switch (expr[i]) {
                case '+': push(&s, val1 + val2); break;
                case '-': push(&s, val1 - val2); break;
                case '*': push(&s, val1 * val2); break;
                case '/': push(&s, val1 / val2); break;
            }
        }
    }

    return pop(&s);
}

