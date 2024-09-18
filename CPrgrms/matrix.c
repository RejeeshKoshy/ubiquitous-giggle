/*----------------------------
matrix.c

Rejeesh Koshy
23-07-2024
----------------------------*/

#include <stdio.h>
#include <stdlib.h>

void InputMat(int M, int N, int A[10][10]);
void PrintMat(int M, int N, int A[10][10]);
void AddMat(int M, int N, int A[10][10], int B[10][10], int C[10][10]);

int main()
{
	int M,P,N,A[10][10],B[10][10],C[10][10];

	printf("PROGRAM TO INPUT, PRINT AND ADDD MATRIX\n\n");
	printf("Enter the dimensions of the matrix: ");
	scanf("%d %d %d",&M, &N, &P);

	printf("Input first matrix: \n");
	InputMat(M,P,A);

	printf("Input second matrix: \n");
	InputMat(P,N,B);

	printf("First Matrix: \n");
	PrintMat(M, P, A);

	printf("Second Matrix: \n");
	PrintMat(P, N, B);

	//printf("\n\nMatrix after summation: \n");
	//AddMat(M, N, A, B, C);
	//PrintMat(M, N, C);

	printf("\n\nMatrix after multiplication: \n");
	PrintMat(M, N, C);

	return 0;
}

//------------------------------------------------------
void InputMat(int M, int N, int A[10][10]){
	int i, j;

	for(i=1; i<=M; i++){
		for(j=1; j<=N; j++){
			scanf("%d",&A[i][j]);
		}
	}
}
//------------------------------------------------------
void PrintMat(int M, int N, int A[10][10]){
	int i, j;

	for(i=1; i<=M; i++){
		for(j=1; j<=N; j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
}
//-----------------------------------------------------
void AddMat(int M, int N, int A[10][10], int B[10][10], int C[10][10]){
	int i, j;

	for(i=1; i<=M; i++){
		for(j=1; j<=N; j++){
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}
//-----------------------------------------------------

void MultMat(int M, int P, int N, int A[10][20], int B[10][10], int C[10][10]){
	int i,j,k;

	for(i = 1; i <= M; i++){
		for(j = 1; j <= N; j++){
			C[i][j] = 0;
			for(k = 1;k <= P; k++){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}