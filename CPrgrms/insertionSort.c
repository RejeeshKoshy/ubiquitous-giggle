/*----------------------------
InsertionSort.c

Rejeesh Koshy
27-07-2024
----------------------------*/

#include <stdio.h>

void InputArray(int N, int A[20]);
void PrintArray(int N, int A[20]);
void InsertionSort(int N, int A[20]);

int main()
{
	int N, X[20];

	printf("PROGRAM TO SORT ARRAY USING INSERTION SORT\n\n");

	printf("Enter numbers of values into the array : ");
	scanf("%d", &N);

	printf("Enter %d integers into the array: \n", N);
	InputArray(N, X);

	printf("\n\nPrint content of the array: ");
	PrintArray(N, X);

	//printf("\n\n");
	InsertionSort(N, X);

	printf("\n\nPrint content of the array after Insertion sort: ");
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

void InsertionSort(int N, int A[20]){
	int i, j, X;

	for(i=2; i<N; i++){
		X = A[i];
		j = i-1;
		while((X<A[j]) && (j>=1)){
			//PrintArray(N,A);
			//printf("\n");
			A[j+1] = A[j];
			j = j-1;
		}
		A[j+1] = X;
	}
}