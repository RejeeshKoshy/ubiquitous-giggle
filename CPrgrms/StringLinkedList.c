/*----------------------------
StringLinkedList.c

Rejeesh Koshy
06-08-2024
----------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Define a struct for the linked list nodes
typedef struct ListNode {
    char str[20];
    struct ListNode *Next;
} LISTNODE;

LISTNODE *Head;

// Function prototypes
void InitList();
void InsertListNode(char str[]);
void PrintList(LISTNODE *Head);
int DeleteFirstNode();
int SearchString(char str[]);
int DeleteLastNode();
void str_cpy(char *T, char *S);
int StrCmp(char *T, char *S);

// Main function with a menu-driven interface
int main() {
    int choice, found;
    char str[20];

    InitList();
    printf("Program for linked list operations:\n");

    while (1) {
		system("cls");
        printf("\n================================================");
        printf("\n1->Insert a string (into an ordered list)");
        printf("\n2->Display the contents of the list");
        printf("\n3->Remove the first node");
        printf("\n4->Search for a given string in the list");
        printf("\n5->Remove the last node");
        printf("\n6->Exit");
        printf("\n================================================");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter the string: ");
                scanf("%s", str);
                InsertListNode(str);
                break;
            }
            case 2: {
                printf("The List is:");
                PrintList(Head);
				getch();
                break;
            }
            case 3: {
                if (DeleteFirstNode() == -1) {
                    printf("The List is empty!\n");
                } else {
                    printf("The first node is deleted from the list.\n");
                }
				getch();
                break;
            }
            case 4: {
                printf("Enter the string to be searched: ");
                scanf("%s", str);
                found = SearchString(str);
                if (found == -1) {
                    printf("Item not found!\n");
                } else {
                    printf("Item found!\n");
                }
				getch();
                break;
            }
            case 5: {
                if (DeleteLastNode() == -1) {
                    printf("The List is empty!\n");
                } else {
                    printf("The last node is deleted from the list.\n");
                }
				getch();
                break;
            }
            case 6: {
                exit(0);
            }
        }
    }
}

// Initialize the list
void InitList() {
    Head = NULL;
}

// Insert a string into an ordered list
void InsertListNode(char str[]) {
    LISTNODE *Prev = NULL, *Curr = Head, *Node;

    // Allocate memory for the new node and copy the string
    Node = (LISTNODE *)malloc(sizeof(LISTNODE));
    str_cpy(Node->str, str);
    Node->Next = NULL;

    // Case 1: Insert at the beginning or in an empty list
    if (Head == NULL) {
        Head = Node;
        return;
    }

    // Case 2: Insert before the head node (if str is less than the current head node's str)
    if (StrCmp(Head->str, str) > 0) {
        Node->Next = Head;
        Head = Node;
        return;
    }

    // Case 3: Traverse the list to find the correct position
    while (Curr != NULL && StrCmp(Curr->str, str) <= 0) {
        Prev = Curr;
        Curr = Curr->Next;
    }

    // Insert the new node at the correct position
    Node->Next = Curr;
    Prev->Next = Node;

}

// Print the list contents
void PrintList(LISTNODE *Head) {
    LISTNODE *Curr = Head;
	
    while (Curr != NULL) {
        printf("\t%s", Curr->str);
        Curr = Curr->Next;
    }
    printf("\n");
}

// Delete the first node
int DeleteFirstNode() {
    if (Head == NULL) {
        return -1;
    }
    LISTNODE *Temp = Head;
    Head = Head->Next;
    free(Temp);
    return 0;
}

// Search for a given string in the list
int SearchString(char str[]) {
    LISTNODE *Curr = Head;
    while (Curr != NULL) {
        if (StrCmp(Curr->str, str) == 0) {
            return 0;
        }
        Curr = Curr->Next;
    }
    return -1;
}

// Delete the last node
int DeleteLastNode() {
    if (Head == NULL) {
        return -1;
    }
    LISTNODE *Curr = Head, *Prev = NULL;
    if (Head->Next == NULL) {
        free(Head);
        Head = NULL;
        return 0;
    }
    while (Curr->Next != NULL) {
        Prev = Curr;
        Curr = Curr->Next;
    }
    free(Curr);
    Prev->Next = NULL;
    return 0;
}

// Custom string copy function
void str_cpy(char *T, char *S) {
    int i = 0;
    while (*(S + i) != '\0') {
        *(T + i) = *(S + i);
        i++;
    }
    *(T + i) = '\0';
}

// Custom string comparison function
int StrCmp(char *T, char *S) 
{
    int i = 0;
    while (*(T + i) == *(S + i)) {
        if (*(T + i) == '\0') {
            return 0;
        }
        i++;
    }
    return (*(T + i) - *(S + i));
}
