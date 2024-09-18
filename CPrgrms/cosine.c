/*----------------------------
cosine.c

Rejeesh Koshy
19-07-2024
----------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float fnCosX(float theta);

int main(){
	int theta;

	printf("Program to print cosine values from 0 to 180\n\n");

	printf("-------------------\n");
	printf("Theta \t Cosine\n");
	printf("-------------------\n");
	for(theta = 0; theta <= 180; theta += 10){
		printf("%d \t %.2f\n",theta, fnCosX(theta));
	}

	return 0;
}

//-----------------------------

float fnCosX(float theta){
	float x, term, cosX;
	int i;

	x = (22.0/7.0)*(theta/180);

	term = 1.0;
	cosX = term;
	i = 1;

	while (fabs(term)>=0.0001){
		term *= -x*x/((2*i-1)*(2*i));
		cosX += term;
		i++;
	}

	return cosX;
}