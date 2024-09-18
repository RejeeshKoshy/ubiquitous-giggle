/*----------------------------
LinkedList.c

Rejeesh Koshy
01-08-2024
----------------------------*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ListType{
	int Num;
	struct ListType *Next;
}LISTNODE;

LISTNODE *Head;

//=========Prototypes=========

void InitList();
void InsertListNode();
void PrintListNode(LISTNODE *Head);
int DeleteFirstNode();
int DeleteLastNode();
void DeleteNode(int Num);
int CountNodes(LISTNODE *Head);
int SearchNum(int Num);

int main()
{
	int Num, i, N;
	
	InitList();
	printf("Program to insert values into Linked List\n\n");
	
	printf("How many numbers do you want to enter?\n");
	scanf("%d",&N);
	
	for(i=0;i<N;i++){
		printf("\nEnter a number:\t");
		scanf("%d",&Num);
		InsertListNode(Num);
	}
	
	printf("\nThe printed form of Linked list is:\n");
	PrintListNode(Head);
	return 0;
}

//-----------------------------
void InitList()
{
	Head = NULL;
}

//-----------------------------
void InsertListNode(int Num)
{
	LISTNODE *prev, *curr, *Node;
	Node = (LISTNODE*)malloc(sizeof(LISTNODE));
	Node->Num = Num;
	Node = NULL;
	
	//Case I : No list
	if(Head == NULL){
		Head = Node;
		return;
	}
	
	//Case II : Num is the smallest
	curr = Head;
	if(curr->Num > Num){
		Node = curr;
		Head = Node;
		return;
	}
	
	//Case III : Traverse and insert
	while((curr!=NULL) && (Num >= curr->Num)){
		prev = curr;
		curr = curr->Node;
	}
	prev = Node;
	Node = curr;
}
//-----------------------------
void PrintListNode(LISTNODE* Head)
{
	LISTNODE *curr = Head;
	
	if(Head == NULL){
	    printf("The list is empty");
	    return;
	}
	
	while(curr != NULL){
		printf("%d\t",curr->Num);
		curr = curr->Node;
	}
}
//-----------------------------
int DeleteFirstNode()
{
	int Num;
	LISTNODE *curr;
	curr = Head;
	Num = Head->Num;
	
	
	Head = Head->Next;
	free(curr);
	return(num);
}
//-----------------------------
int DeleteLastNode()
{
	int Num;
	LISTNODE *curr, *prev;
	
	curr = Head;
	
	while(curr->Next != NULL){
		
	}
}
//----------------------------
void DeleteNode(int Num)
{
	LISTNODE *prev, *curr;
	
	curr = Head;
	
	//Case I: No list
	if(Head == NULL){
		return;
	}
	
	//Case II: 	Number to be deleted is on th head.
	//			Make the next node the head of the list.
	
	if(
int CountNodes(LISTNODE *Head);
int SearchNum(int Num);