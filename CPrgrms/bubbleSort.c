/*----------------------------
BubbleSort.c

Rejeesh Koshy
22-07-2024
----------------------------*/

#include <stdio.h>
#include <stdlib.h>

void InputArray(int N, int A[20]);
void PrintArray(int N, int A[20]);
void BubbleSort(int N, int A[20]);

int main()
{
	int N, X[20];

	printf("PROGRAM TO SORT ARRAY USING BUBBLE SORT\n\n");

	printf("Enter numbers of values into the array : ");
	scanf("%d", &N);

	printf("Enter %d integers into the array: \n", N);
	InputArray(N, X);

	printf("\n\nPrint content of the array: ");
	PrintArray(N, X);

	//printf("\n\n");
	BubbleSort(N, X);

	printf("\n\nPrint content of the array after Bubble sort: ");
	PrintArray(N, X);

	return 0;
}

//--------------------------------------

void InputArray(int N, int A[20]){
	int i;
	
	for(i = 1; i <= N;i++){
		scanf("%d", &A[i]);
	}
}
//--------------------------------------

void PrintArray(int N, int A[20]){
	int i;
	
	for(i = 1; i <= N;i++){
		printf("%d\t", A[i]);
	}
}
//--------------------------------------

void BubbleSort(int N, int A[20]){
	int i, j, temp;

	for(i=1; i<=N; i++){
		for(j=1; j<=N-i; j++){
			//PrintArray(N,A);
			//printf("\n");
			if (A[j]>A[j+1]){
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
}