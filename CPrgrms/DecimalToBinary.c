/*------------------
DecimalToBinary.c

Rejeesh Koshy
-------------------*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 32 // Assuming the maximum size of the stack to handle 32-bit binary numbers

// Stack structure
typedef struct stackType {
    int A[SIZE];
    int top;
} stack;

stack s;

// Stack functions
void InitStack();

void Push(int num);

int Pop();

int IsEmpty();

// Function to convert decimal to binary using stack
void DecimalToBinary(int decimal);

int main() {
    int decimal;

    // Initialize stack
    InitStack();

    // Input: decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    if (decimal == 0) {
        printf("Binary Equivalent: 0\n");
    } else {
        // Convert and print binary equivalent
        DecimalToBinary(decimal);
    }

    return 0;
}

void InitStack() {
    s.top = -1; // Initializing top to -1 indicating the stack is empty
}

void Push(int num) {
    if (s.top == SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        s.top++;
        s.A[s.top] = num;
    }
}

int Pop() {
    if (s.top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return s.A[s.top--];
    }
}

int IsEmpty() {
    return s.top == -1;
}

// Function to convert decimal to binary using stack
void DecimalToBinary(int decimal) {
    // Keep dividing the decimal number by 2 and pushing the remainder onto the stack
    while (decimal > 0) {
        Push(decimal % 2);
        decimal /= 2;
    }

    // Pop and print elements from the stack (this gives the binary number in correct order)
    printf("Binary Equivalent: ");
    while (!IsEmpty()) {
        printf("%d", Pop());
    }
    printf("\n");
}
