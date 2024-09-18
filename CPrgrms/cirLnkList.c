/*----------------------------
CirLnkList.c

Rejeesh Koshy
18-08-2024
----------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <memory.h>

// Define a struct for the DBLL nodes
typedef struct CirListType {
    int num;
    struct CirListType *next;
} CirListNode;

// Global variables
CirListNode *front, *rear;

// Function prototypes
void InitCirList();
void Enque(int num);
int Deque();
void PrintCirList();
void Menu(int *choice);

// Main function with a menu-driven interface
int main() {
    int num, choice = 1;
	
	InitCirList();
	
	while(choice){
		Menu(&choice);
		switch(choice){
			case 1: 
				printf("\nEnter a number:\t");
				scanf("%d",&num);
				Enque(num);
				break;
			case 2:
				printf("\nValue of the first node deleted: %d\n",Deque());
				getch();
				break;
			case 3: 
				printf("\nThe printed form of List is:\n");
				PrintCirList();
				getch();
				break;
			case 4: exit(1);
			default: Menu(&choice);
		}
	}
	return 0;
}

//---------------------------------Initialize the list---------------------------------
void InitCirList() 
{
    front = rear = NULL;
}

//-------------------Insert a node into an Doubly linked list--------------------------
void Enque(int num) 
{
    CirListNode *node;
	
	node = (CirListNode *)malloc(sizeof(CirListNode));
	node->num = num;
	node->next = NULL;
	
	if(rear == NULL){	//Case I: No list, node becomes front and rear
		front = rear = node;
	} else {	//Case II: List exist, append node
		rear->next = node;
		rear = node;
	}
	
	rear->next = front;
	
	return;
}
//---------------------------------------------------------------------------------------
int Deque()
{
	CirListNode *temp;
	int num;
	
	if(rear == NULL){			// Case 1 : No list
		printf("\nCircular list is empty\n");
		front = rear = NULL;
		return -1;
	} else if(front == rear){	// Case 2 : List has 1 node
		num = front->num;
		free(front);
		front = rear = NULL;
		return num;
	}
	// Case 3 : List has > 1 node
	temp = front;
	front = front->next;
	rear->next = front;
	num = temp->num;
	free(temp);
	
	return num;
}
//---------------------------------------------------------------------------------------
void PrintCirList()
{
	CirListNode *curr;
	
	if(rear == NULL){
		printf("List is empty");
		return;
	}
	
	curr = front;
	printf("%d\t", curr->num);
	curr = curr->next;

	while(curr != front){
		printf("%d\t", curr->num);
		curr = curr->next;
	}
	return;
}
//---------------------------------------------------------------------------------------
void Menu(int *choice)
{
	system("cls");
	printf("---------------------------Menu------------------------------");
	printf("\n\n\t1. Insert number into List\n");
	printf("\t2. Delete first node from the list\n");
	printf("\t3. Display content of the list\n");
	printf("\t4. Exit");
	printf("\n\n");
	printf("Enter your choice: ");
	scanf("%d", choice);
}