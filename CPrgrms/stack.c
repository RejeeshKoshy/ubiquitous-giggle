/*----------------------------
Stack.c

Rejeesh Koshy
09-09-2024
----------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 5

typedef struct {
    int A[SIZE];
    int top;
} stack;

stack s;

void InitStack();
int stackEmpty();
void Push(int num);
int Pop();
void printStack();
void Menu(int *choice);

int main() {
    int num, choice = 1;
    InitStack();
    
    while (choice) {
        Menu(&choice);
        switch (choice) {
            case 1:
                if (stackEmpty() == 0) printf("Stack Overflow"), getch();
                else printf("\nEnter a number: "), scanf("%d", &num), Push(num);
                break;
            case 2:
                if (stackEmpty() == 1) printf("Stack Underflow"), getch();
                else printf("\nDeleted: %d\n", Pop()), getch();
                break;
            case 3:
                if (stackEmpty() == 1) printf("Stack Empty"), getch();
                else printf("\nStack content:\n"), printStack(), getch();
                break;
            case 4: exit(0);
        }
    }
    return 0;
}

void InitStack() { s.top = 0; }

int stackEmpty() { return s.top == 0 ? 1 : s.top == SIZE ? 0 : -1; }

void Push(int num) { s.A[++s.top] = num; }

int Pop() { return s.A[s.top--]; }

void printStack() { for (int i = s.top; i > 0; i--) printf("%d\n", s.A[i]); }

void Menu(int *choice) {
    system("cls");
    printf("--------- STACK IMPLEMENTATION ---------\n\n");
    printf("1. Enter number\n2. Delete number\n3. Display stack\n4. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", choice);
}