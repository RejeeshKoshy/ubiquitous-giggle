/*----------------------------
ArithemeticArray.c

Rejeesh Koshy
19-07-2024
----------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void InputArray(int N, int A[20]);
void PrintArray(int N, int A[20]);
float fnAvg(int N, int A[20]);
float fnStdDev(int N, int A[20]);

int main(){
	int N, X[20];
	float avg;

	printf("PROGRAM TO INPUT, PRINT AND FIND AVERAGE OF AN ARRAY WITH INTEGERS\n\n");
	
	printf("Enter numbres of values into the array : ");
	scanf("%d", &N);

	printf("Enter %d integers into the array: \n", N);
	InputArray(N, X);

	printf("\n\nPrint content of the array: ");
	PrintArray(N, X);

	printf("\n\nThe average of the array is : %.2f",fnAvg(N,X));
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
	int i,sum,numerator;
	float avg;

	sum = 0;
	numerator = 0;
	for(i = 0; i < N;i++){
		sum += A[i];
	}

	avg = sum/N;

	for(i = 0; i<N; i++){
		numerator += ((A[i]-avg)*(A[i]-avg)); 
	}

	return sqrt(numerator/N);
}