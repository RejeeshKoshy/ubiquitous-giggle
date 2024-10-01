/*----------------------------
StackFact.c

Rejeesh Koshy
23-09-2024
----------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 2

typedef struct stackType
{
	double A[SIZE];
	int top;
} stack;
stack s;

void InitStack();
void Push(int num);
int Pop();
void Menu(int *choice);
double StackFact(int n);

int main()
{
	int num, choice = 1;
	
	InitStack();
	while(choice){
		Menu(&choice);
		switch(choice){
			case 1: printf("\nEnter your number: ");
					scanf("%d", &num);
					printf("\nFactorial of the number is %.2f", StackFact(num));
					getch();
					break;
			case 0: exit(1);
			default:Menu(&choice);
		}
	}
	return 0;
}
//---------------------------------
void InitStack()
{
	s.top = 0;
}
//---------------------------------
void Push(int num)
{
	s.top++;
	s.A[s.top] = num;
}
//---------------------------------
int Pop()
{
	int num;
	num = s.A[s.top];
	s.top--;
	return num;
}
//---------------------------------
double StackFact(int n)
{
	int i, num;
	i = 2;
	Push(1);
	while(i<=n){
		num = Pop();
		Push(num*i);
		i++;
	}
	num = Pop();
	return num;
}
//---------------------------------
void Menu(int *choice)
{
	system("cls");
	printf("----------------STACK IMPEMENTATION FOR FACTORIAL----------------");
	printf("\n\n\t1. Find Factorial\n");
	printf("\t0. Exit");
	printf("\n\n");
	printf("Enter your choice: ");
	scanf("%d", choice);
}