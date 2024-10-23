/*----------------------------
StackFact.c

Rejeesh Koshy
23-09-2024
----------------------------*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 2

typedef struct {
	double A[SIZE];
	int top;
} stack;

stack s = { .top = 0 };

void push(int num);
int pop();
double stackFactorial(int n);

int main() {
	int choice, num;
	while (1) {
		system("cls");
		printf("---- STACK FACTORIAL ----\n");
		printf("1. Find Factorial\n0. Exit\n\nChoice: ");
		scanf("%d", &choice);
		
		if (choice == 1) {
			printf("Enter a number: ");
			scanf("%d", &num);
			printf("Factorial: %.2f\n", stackFactorial(num));
			getchar(); getchar();  
		} else {
			exit(0);
		}
	}
	return 0;
}

void push(int num) { s.A[++s.top] = num; }

int pop() { return s.A[s.top--]; }

double stackFactorial(int n) {
	push(1);
	for (int i = 2; i <= n; i++) {
		push(pop() * i);
	}
	return pop();
}