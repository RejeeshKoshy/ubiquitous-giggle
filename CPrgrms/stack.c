/*----------------------------
Stack.c

Rejeesh Koshy
09-09-2024
----------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 5

typedef struct stackType
{
	int A[SIZE];
	int top;
} stack;
stack s;

void InitStack();
void Push(int num);
int Pop();
int stackEmpty();
void printStack();
void Menu(int *choice);

int main()
{
	int num, choice = 1;
	
	InitStack();
	while(choice){
		Menu(&choice);
		switch(choice){
			case 1: if(stackEmpty() == 0){
						printf("Stack Overflow");
						getch();
					} else {
						printf("\nEnter a number:\t");
						scanf("%d",&num);
						Push(num);
					}
					break;
			case 2: if(stackEmpty() == 1){
						printf("Stack Underflow");
						getch();
					} else {
						printf("\nDeleted number is: %d\n",Pop());
						getch();
					}
					break;
			case 3:	if(stackEmpty() == 1){
						printf("Stack Underflow");
						getch();
					} else {
						printf("\nThe printed form of Stack is:\n");
						printStack();
						getch();
					}
					break;
			case 4: exit(1);
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
int stackEmpty(){
	if(s.top == 0){
		return 1;	// Stack Empty
	} else if (s.top == SIZE) {
		return 0;	// Stack Full
	}else{
		return -1;	// Stack exists
	}
}
//---------------------------------
void printStack(){
	for(int i = s.top; i > 0; i--){
		printf("%d",s.A[i]);
		printf("\n");
	}
}
//---------------------------------
void Menu(int *choice)
{
	system("cls");
	printf("--------------------STACK IMPEMENTATION--------------------");
	printf("\n\n\t1. Enter number\n");
	printf("\t2. Delete number\n");
	printf("\t3. Display content of stack\n");
	printf("\t4. Exit");
	printf("\n\n");
	printf("Enter your choice: ");
	scanf("%d", choice);
}