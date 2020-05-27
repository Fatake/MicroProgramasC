#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

#define DATA 1000000

int main(void){
	char *A;
	int i;
	float suma=0.0;

	A=(char *) malloc (DATA*sizeof(char));

	#pragma omp parallel shared(suma) num_threads(10)
	{
		#pragma omp for private(i)
		
		for (i=0; i<DATA; i++) A[i]=2;
		
		#pragma omp for private(i) reduction(+:suma)
		for (i=0; i<DATA; i++){
			suma += A[i];
		}
	}

	printf("Suma = %.2f \n", suma);
	free(A);
	return 0;
}
