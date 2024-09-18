/*----------------------------
maxArray.c

Rejeesh Koshy
22-07-2024
----------------------------*/

#include <stdio.h>
#include <stdlib.h>

void InputArray(int N, int A[20]);
void PrintArray(int N, int A[20]);
int MaxArray(int N, int A[20]);

int main()
{
	int N, A[20];
	
	printf("PROGRAM TO FIND MAX VALUE IN THE ARRAY\n\n");
	
	printf("Enter the number of elements: ");
	scanf("%d",&N);

	printf("\nEnter elements of the array: ");
	InputArray(N, A);

	printf("\n\nPrint content of the array: \n");
	PrintArray(N, A);

	printf("\n\nThe maximum value present in the array is : %d\n", MaxArray(N, A));

	return 0;
}

//--------------------------------------------------------------------------------------

void InputArray(int N, int A[20]){
	int i;
	
	for(i = 0; i < N;i++){
		scanf("%d", &A[i]);
	}
}
//--------------------------------------

void PrintArray(int N, int A[20]){
	int i;
	
	for(i = 0; i < N;i++){
		printf("%d\t", A[i]);
	}
}
//--------------------------------------

int MaxArray(int N, int A[20]){
	int max, i;
	max = A[0];

	for (i=1;i<N;i++){
		if (max < A[i]){
			max = A[i];
		}
	}

	return max;
}