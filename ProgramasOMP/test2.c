#include <stdio.h>
#include <stdlib.h>

#define FILS 1000000
#define COLS 200

int main(void){
	char *A;
	int i,j;

	A=(char *) malloc (FILS*COLS*sizeof(char));
	for ( j = 0; j < COLS; j++){
		for ( i= 0; i< FILS; i++){
			A[i*COLS + j] = i + j;
		}
	}
	free(A);
	return 0;
}
