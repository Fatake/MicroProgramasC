#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

#define DIM 2000

int main(void){
	char *A, *B, *C;
	int i,j;

	A=(char *) malloc (DIM*DIM*sizeof(char));
	B=(char *) malloc (DIM*DIM*sizeof(char));
	C=(char *) malloc (DIM*DIM*sizeof(char));

	//variables compartidas i y j se didiven entre cada uno de los threads
	//#pragma omp parallel shared(i,j) num_threads(10)
	#pragma omp parallel num_threads(10)
	{
		#pragma omp for private (i,j)
		for (i=0; i<DIM; i++) 
			for (j=0; j<DIM; j++){
				A[i*DIM+j]=1;
				B[i*DIM+j]=2;
			}
		#pragma omp for private (i,j)
		for (i=0; i<DIM; i++) 
		for (j=0; j<DIM; j++)
		C[i*DIM+j]=A[i*DIM+j]+B[i*DIM+j];
	}

	printf("Suma = %d \n", C[10000]);
	free(A);
	free(B);
	free(C);
	return 0;
}
