#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef struct StackType{
	int top;
	int A[SIZE];
}STACK;
STACK S;

//------------- Function Prototypes---------------------------//
void push(int num);
int pop();

void display();
void InitStack();
void Menu();

int main(){
	int num,i,check;
	
	printf("-----------------STACK IMPLEMENTATION------------------- \n");
	
	InitStack();
    do {
        Menu();
        printf("Enter your choice: ");
        scanf("%d", &i);
        switch(i) {
            case 1:
                printf("Enter number to be inserted: ");
                scanf("%d", &num);
                push(num);
                break;
            case 2:
                printf("the deleted number is %d",num);
                
                pop();
                break;
            case 3:
                printf("elements in the stack are:\n");
    
                	display();
				
                
                break;
            case 4:
                printf("Exiting...\n");
                break;    
            default:
                printf("Invalid choice! \n");
        }
    } while(i != 4);

    return 0;
}

void Menu() {
    printf("\nMenu:\n");
    printf("1. Enter number\n");
    printf("2. Delete number\n");
    printf("3. Display contents of the stack\n");
    printf("4. Exit\n");
}

// function to initialize the stack
void InitStack()
{
    S.top = 0;
}

// function to push the number into the stack
void push(int num)
{
	if(S.top==SIZE){
		printf("stack overflow !");
		return;
	}else{
		S.top++;
		S.A[S.top]=num;
	}
}

// function to pop the number from the stack
int pop()
{
	int num;
	if(S.top==0){
		printf("stack underflow !");
		return 0;
	}else{
		num=S.A[S.top];
		S.top--;
		return num;
		
	}
}


// function to display the contents of the stack
void display()
{
	int i;
	for(i=S.top;i>=1;i--){
		printf("%d\n",S.A[i]);
	}
}