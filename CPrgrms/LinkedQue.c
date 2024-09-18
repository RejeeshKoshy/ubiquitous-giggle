/*----------------------------
LinkedQue.c

Rejeesh Koshy
05-08-2024
----------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct QueType{
	int Num;
	struct QueType *Next;
}QUENODE;

QUENODE *front, *rear;

//=========Prototypes=========

void InitQue();
void Enque(int Num);
int Deque();
void PrintQue(QUENODE *front);
void Menu(int *Choice);

int main()
{
	int Num, i, N, choice = 1;
	
	InitQue();
	while(choice){
		Menu(&choice);
		switch(choice){
			case 1: printf("\nEnter a number:\t");
					scanf("%d",&Num);
					Enque(Num);
					break;
			case 2: printf("\nThe printed form of queue is:\n");
					PrintQue(front);
					getch();
					break;
			case 3: printf("\n\n%d is deleted from the queue",Deque());
					printf("\nNow the printed form of queue is:\n");
					PrintQue(front);
					getch();
					break;
			case 4: exit(1);
			default:Menu(&choice);
		}
	}
	
	return 0;
}
//-----------------------------
void InitQue()
{
	front = rear = NULL;
}
//-----------------------------
void Enque(int Num)
{
	QUENODE *curr, *NODE;
	NODE = (QUENODE*)malloc(sizeof(QUENODE));
	NODE->Num = Num;
	NODE->Next = NULL;
	
	//Case I : No queue
	if(front == NULL){
		front = rear = NODE;
		return;
	}
	
	//Case II : Attach new node at the end of the queue
	rear->Next = NODE;
	rear = NODE;
}
//-----------------------------
int Deque()
{
	int Num;
	QUENODE *curr;
	
	//Case I : No Queue
	if(front == NULL){
		printf("Queue is empty");
		return -1;
	}
	
	//Case II : Queue exist(But only 1 node)
	if(front == rear){
		Num = front->Num;
		curr = front;
		front = NULL;
		free(curr);
		return Num;
	}
	
	curr = front;
	front = front->Next;
	//Case III: Default case
	Num = curr->Num;
	free(curr);
	return Num;
	
}
//-----------------------------
void PrintQue(QUENODE *front)
{
	QUENODE *curr;
	curr = front;
	
	if(curr==NULL){
		printf("\nNo Queue to print");
		return;
	}
	while(curr){
		printf("%d\t", curr->Num);
		curr = curr->Next;
	}
}
//------------------------------
void Menu(int *choice)
{
	system("cls");
	printf("------------------Menu---------------------");
	printf("\n\n\t1. Insert number into queue\n");
	printf("\t2. Display content of the queue\n");
	printf("\t3. Remove first Node of the queue\n");
	printf("\t4. Exit");
	printf("\n\n");
	printf("Enter your choice: ");
	scanf("%d", choice);
}