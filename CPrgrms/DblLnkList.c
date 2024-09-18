/*----------------------------
DblLnkList.c

Rejeesh Koshy
16-08-2024
----------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ESC 27
#define LEFT 75
#define RIGHT 77

// Define a struct for the DBLL nodes
typedef struct DBLLType {
    int num;
    struct DBLLType *next, *prev;
} DBLLNode;

DBLLNode *Head;

// Function prototypes
void InitDBLL();
void InsertDBLLNode(int num);
void PrintDBLL();
int KeyHit();
void DisplayOnKeyHit();
void Menu(int *choice);

// Main function with a menu-driven interface
int main() {
    int num, choice = 1;
	
	InitDBLL();
	while(choice){
		Menu(&choice);
		switch(choice){
			case 1: printf("\nEnter a number:\t");
					scanf("%d",&num);
					InsertDBLLNode(num);
					break;
			case 2: printf("\nThe printed form of Doubly linked List is:\n");
					//PrintDBLL();
					DisplayOnKeyHit();
					break;
			case 3: exit(1);
			default:Menu(&choice);
		}
	}
	
	return 0;
}

//---------------------------------Initialize the list---------------------------------
void InitDBLL() 
{
    Head = NULL;
}

//-------------------Insert a node into an Doubly linked list--------------------------
void InsertDBLLNode(int num) 
{
    DBLLNode *prev, *curr, *node;
	
	node = (DBLLNode *)malloc(sizeof(DBLLNode));
	node->num = num;
	node->next = NULL;
	node->prev = NULL;
	
	//Case I: No tree, node becomes head
	if(Head == NULL){
		Head = node;
		return;
	}
	
	curr = Head;
	//Case II: List exist, new node value > head value
	// In InsertDBLLNode:
	if (curr->num >= node->num) {
		node->next = curr;
		curr->prev = node;
		Head = node;
		return;
	}

	
	//Case III: Traverse the list & append
	while(curr != NULL && num >= curr->num){
		prev = curr;
		curr = curr->next;
	}
	
	prev->next = node;
	node->prev = prev;
	node->next = curr;
	if(curr!=NULL)
		curr->prev = node;
}
//---------------------------------------------------------------------------------------
void PrintDBLL()
{
	DBLLNode *prev, *curr = Head;
	
	while(curr != NULL){
		printf("%d\t", curr->num);
		prev = curr;
		curr = curr->next;
	}
	printf("\n");
	prev = curr;
	while(curr != NULL){
		printf("%d\t", curr->num);
		prev = curr;
		curr = curr->prev;
	}
}
//---------------------------------------------------------------------------------------
int KeyHit()
{
	int key;
	key = getch();
	if(key == 0){
		key = getch();
	}
	return key;
}
//---------------------------------------------------------------------------------------
void DisplayOnKeyHit() {
    int key;
    DBLLNode *curr = Head;

    if (curr == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("%d\t", curr->num);
    key = KeyHit();
    while (key != ESC) {
        if (key == RIGHT) {
            curr = curr->next;
            printf("%d\t", curr->num);
        } else if (key == LEFT) {
            curr = curr->prev;
            printf("%d\t", curr->num);
        }
        key = KeyHit(); // Re-read the key inside the loop
    }
}
//---------------------------------------------------------------------------------------
void Menu(int *choice)
{
	system("cls");
	printf("---------------------------Menu------------------------------");
	printf("\n\n\t1. Insert number into Doubly Linked List\n");
	printf("\t2. Display content of the Doubly Linked List\n");
	printf("\t3. Exit");
	printf("\n\n");
	printf("Enter your choice: ");
	scanf("%d", choice);
}