/*----------------------------
bst.c

Rejeesh Koshy
12-08-2024
----------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Define a struct for the BST nodes
typedef struct TreeType {
    int num;
    struct TreeType *right, *left;
} TreeNode;

TreeNode *Root;

// Function prototypes
void InitTree();
void InsertTreeNode(int num);
void PreOrder(TreeNode *Root);
void InOrder(TreeNode *Root);
void PostOrder(TreeNode *Root);
void Menu(int *Choice);

// Main function with a menu-driven interface
int main() {
    int num, choice = 1;
	
	InitTree();
	while(choice){
		Menu(&choice);
		switch(choice){
			case 1: printf("\nEnter a number:\t");
					scanf("%d",&num);
					InsertTreeNode(num);
					break;
			case 2: printf("\nThe printed form of tree in Pre-Order form is:\n");
					PreOrder(Root);
					getch();
					break;
			case 3: printf("\nThe printed form of tree in In-Order form is:\n");
					InOrder(Root);
					getch();
					break;
			case 4: printf("\nThe printed form of tree in Post-Order form is:\n");
					PostOrder(Root);
					getch();
					break;
			case 5: exit(1);
			default:Menu(&choice);
		}
	}
	
	return 0;
}

//---------------------------------Initialize the list---------------------------------
void InitTree() 
{
    Root = NULL;
}

//-------------------Insert a node into an Binary Search Tree--------------------------
void InsertTreeNode(int num) 
{
    TreeNode *prev, *curr, *node;
	
	node = (TreeNode *)malloc(sizeof(TreeNode));
	node->num = num;
	node->right = NULL;
	node->left = NULL;
	
	//Case I: No tree, node becomes root
	if(Root == NULL){
		Root = node;
		return;
	}
	
	//Case II: Traverse the tree (left or right) & append
	curr = Root;
	
	while(curr != NULL){
		prev = curr;
		if(num > curr->num){
			curr = curr->right;
		} else {
			curr = curr->left;
		}
	}
	
	if (prev->num < num){
		prev->right = node;
	} else {
		prev->left = node;
	}
}
//---------------------------------------------------------------------------------------
void PreOrder(TreeNode *Root)
{
	if(Root != NULL){
		printf("%d \t", Root->num);
		PreOrder(Root->left);
		PreOrder(Root->right);
	}
}
//---------------------------------------------------------------------------------------
void InOrder(TreeNode *Root)
{
	if(Root != NULL){
		InOrder(Root->left);
		printf("%d \t", Root->num);
		InOrder(Root->right);
	}
}
//---------------------------------------------------------------------------------------
void PostOrder(TreeNode *Root)
{
	if(Root != NULL){
		PostOrder(Root->left);
		PostOrder(Root->right);
		printf("%d \t", Root->num);
	}
}
//---------------------------------------------------------------------------------------
void Menu(int *choice)
{
	system("cls");
	printf("---------------------------Menu------------------------------");
	printf("\n\n\t1. Insert number into BST\n");
	printf("\t2. Display content of the Tree in Pre-Order\n");
	printf("\t3. Display content of the Tree in In-Order\n");
	printf("\t4. Display content of the Tree in Post-Order\n");
	printf("\t5. Exit");
	printf("\n\n");
	printf("Enter your choice: ");
	scanf("%d", choice);
}