/*----------------------------
StackBrktChk.c

Rejeesh Koshy
25-09-2024
----------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 15

// Stack structure
typedef struct stackType {
    char A[SIZE];
    int top;
} stack;

stack s;

// Function prototypes
void InitStack();
void Push(char brkt);
char Pop();
int IsStackEmpty();
int IsMatchingPair(char left, char right);
void ChkBrkts(char brkts[]);

int main() {
    char brkts[SIZE];

    printf("Enter the list of brackets: ");
    scanf("%s", brkts);

    ChkBrkts(brkts);

    return 0;
}

// Initialize stack
void InitStack() {
    s.top = -1;
}

// Push element onto stack
void Push(char brkt) {
    if (s.top == SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        s.top++;
        s.A[s.top] = brkt;
    }
}

// Pop element from stack
char Pop() {
    if (s.top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        char brkt = s.A[s.top];
        s.top--;
        return brkt;
    }
}

// Check if stack is empty
int IsStackEmpty() {
    return s.top == -1;
}

// Check if the pair of brackets is matching
int IsMatchingPair(char left, char right) {
    return (left == '(' && right == ')') ||
           (left == '{' && right == '}') ||
           (left == '[' && right == ']');
}

// Function to check if the brackets are balanced
void ChkBrkts(char brkts[]) {
    InitStack();
    int i;
    char ch;

    for (i = 0; brkts[i] != '\0'; i++) {
        char brkt = brkts[i];

        // If it's an opening bracket, push it onto the stack
        if (brkt == '(' || brkt == '{' || brkt == '[') {
            Push(brkt);
        } 
        // If it's a closing bracket, check for matching pair
        else if (brkt == ')' || brkt == '}' || brkt == ']') {
            if (IsStackEmpty()) {
                printf("Improper alignment of brackets\n");
                return;
            }
            ch = Pop();
            if (!IsMatchingPair(ch, brkt)) {
                printf("Improper bracket alignment\n");
                return;
            }
        }
    }

    // If stack is empty after processing, brackets are balanced
    if (IsStackEmpty()) {
        printf("Brackets are properly aligned\n");
    } else {
        printf("Improper alignment of brackets\n");
    }
}
