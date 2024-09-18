/*----------------------------
SelectionSort.c

Rejeesh Koshy
19-07-2024
----------------------------*/

#include <stdio.h>
#include <stdlib.h>

void InputArray(int N, int A[20]);
void PrintArray(int N, int A[20]);
void SelectionSort(int N, int A[20]);

int main()
{
	int N, X[20];

	printf("PROGRAM TO SORT ARRAY USING SELCTION SORT\n\n");

	printf("Enter numbers of values into the array : ");
	scanf("%d", &N);

	printf("Enter %d integers into the array: \n", N);
	InputArray(N, X);

	printf("\n\nPrint content of the array: ");
	PrintArray(N, X);

	//printf("\n\n");
	SelectionSort(N, X);

	printf("\n\nPrint content of the array after Selection sort: ");
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

void SelectionSort(int N, int A[20]){
	int i, j, loc, min;

	for(i=1; i<=N; i++){
		min = A[i];
		loc = i;
		for(j=i+1; j<=N; j++){
			//PrintArray(N,A);
			//printf("\n");
			if (A[j] <= min){
				min = A[j];
				loc = j;
			}
		}
		A[loc] = A[i];
		A[i] = min;
	}
}