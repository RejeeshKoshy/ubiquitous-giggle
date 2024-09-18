/*----------------------------
stdDevArray.c

Rejeesh Koshy
19-07-2024
----------------------------*/

#include <stdio.h>
#include <math.h>

void InputArray(int N, int A[20]);
void PrintArray(int N, int A[20]);
float fnAvg(int N, int A[20]);
float fnStdDev(int N, int A[20]);

int main()
{
	int N, X[20];
	float avg;

	printf("PROGRAM TO INPUT, PRINT AND FIND AVERAGE OF AN ARRAY WITH INTEGERS\n\n");
	
	printf("Enter numbers of values into the array : ");
	scanf("%d", &N);

	printf("Enter %d integers into the array: \n", N);
	InputArray(N, X);

	printf("\n\nPrint content of the array: ");
	PrintArray(N, X);

	printf("\n\nThe standard deviation of the array is : %.2f",fnStdDev(N,X));
	
	return 0;
}

//--------------------------------------

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

float fnAvg(int N, int A[20]){
	int i,sum = 0;
	float avg;

	for(i = 0; i < N;i++){
		sum += A[i];
	}

	return sum/N;
}
//--------------------------------------

float fnStdDev(int N, int A[20]){
	int sum,sumSqr,i;
	
	sum = 0;
	sumSqr = 0;

	for(i = 0; i < N;i++){
		sum += A[i];
		sumSqr += (A[i]*A[i]);
	}

	return sqrt((sumSqr/N)-(sum/N)*(sum/N));
}