/*----------------------------
CelsiusToFarenheit.c

Rejeesh Koshy
16-07-2024
----------------------------*/

#include <stdio.h>
#include <stdlib.h>

float CToF(float F);

int main(){
	float C,F;

	printf("PROGRAM TO CONVERT CELSIUS TO FARENHEIT\n\n");
	printf("--------------------------\n");
	printf("Celsius \t Farenheit\n");
	printf("--------------------------\n");
	
	for(C = 0; C <= 100; C+=10){
		F = CToF(C);
		printf("%.2f \t\t %.2f\n", C, F);
	}
	
	return 0;
}

float CToF(float C){
	return (9.0/5.0)*C + 32;
}