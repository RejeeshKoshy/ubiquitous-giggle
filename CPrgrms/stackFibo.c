/*----------------------------
StackFib.c

Rejeesh Koshy
25-09-2024
----------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 25

typedef struct stackType
{
    int A[SIZE];
    int top;
} stack;

stack s;

void InitStack();
void Push(int num);
int Pop();
void Menu(int *choice);
void StackFib(int n);

int main()
{
    int num, choice = 1;
    
    InitStack();
    while(choice)
    {
        Menu(&choice);
        switch(choice)
        {
            case 1: 
                printf("\nEnter the number of Fibonacci terms: ");
                scanf("%d", &num);
                printf("\nFibonacci series:");
                StackFib(num);
                getch();
                break;
            case 0: 
                exit(1);
            default:
                Menu(&choice);
        }
    }
    return 0;
}

//---------------------------------
void InitStack()
{
    s.top = -1;
}

//---------------------------------
void Push(int num)
{
    if (s.top < SIZE - 1)
    {
        s.top++;
        s.A[s.top] = num;
    }
    else
    {
        printf("\nStack Overflow");
    }
}

//---------------------------------
int Pop()
{
    if (s.top >= 0)
    {
        int num = s.A[s.top];
        s.top--;
        return num;
    }
    else
    {
        printf("\nStack Underflow");
        return -1; // Indicating underflow
    }
}

//---------------------------------
void StackFib(int n)
{
    int i;
    int num1, num2, fib;

    if (n < 1) return;

    // Push first two Fibonacci numbers
    Push(0); // F(0) = 0
    Push(1); // F(1) = 1

    // Print F(0) and F(1)
    printf(" %d", s.A[0]); // F(0)
    if (n > 1)
        printf(" %d", s.A[1]); // F(1)

    for (i = 2; i < n; i++)
    {
        num1 = Pop();
        num2 = Pop();
        fib = num1 + num2;

        // Push back the previous two and the new Fibonacci number
        Push(num2); // Re-push num2 to maintain order
        Push(num1); // Re-push num1
        Push(fib);

        printf(" %d", fib);
    }
}

//---------------------------------
void Menu(int *choice)
{
    system("cls");
    printf("----------------STACK IMPLEMENTATION FOR FIBONACCI----------------");
    printf("\n\n\t1. List Fibonacci Numbers\n");
    printf("\t0. Exit");
    printf("\n\n");
    printf("Enter your choice: ");
    scanf("%d", choice);
}
