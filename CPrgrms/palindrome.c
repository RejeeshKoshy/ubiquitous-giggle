/*----------------------------
palindrome.c

Rejeesh Koshy
XX-10-2024
----------------------------*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100 // Maximum size for the string and stack

// Stack structure
typedef struct {
    char A[SIZE];
    int top;
} stack;

stack s;


// Stack functions
void InitStack();
void Push(char ch);
char Pop();
int IsEmpty();
// Function to check if a given string is a palindrome
int IsPalindrome(char str[]);

int main() {
    char str[SIZE];

    // Input: string
    printf("Enter a string: ");
    gets(str);

    // Check if the string is a palindrome
    if (IsPalindrome(str)) {
        printf("The string \"%s\" is a palindrome.\n", str);
    } else {
        printf("The string \"%s\" is not a palindrome.\n", str);
    }

    return 0;
}


// Stack functions
void InitStack() {
    s.top = -1; // Initializing the stack to be empty
}

void Push(char ch) {
    if (s.top == SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        s.top++;
        s.A[s.top] = ch;
    }
}

char Pop() {
    if (s.top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return s.A[s.top--];
    }
}

int IsEmpty() {
    return s.top == -1;
}

// Function to check if a given string is a palindrome
int IsPalindrome(char str[]) {
    int len = strlen(str);
    InitStack();

    // Push the first half of the string onto the stack
    for (int i = 0; i < len / 2; i++) {
        Push(str[i]);
    }

    // Start comparing from the middle of the string (skip the middle character for odd-length strings)
    int start = (len % 2 == 0) ? len / 2 : len / 2 + 1;

    for (int i = start; i < len; i++) {
        if (tolower(Pop()) != tolower(str[i])) {
            return 0; // Not a palindrome
        }
    }

    return 1; // It's a palindrome
}