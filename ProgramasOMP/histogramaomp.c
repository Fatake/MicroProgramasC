#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <omp.h>

#define MAX 128

int main(int argc, char *argv[]){
   unsigned int ws;
   double prom=0.0, prom1=0.0, tmp1, tmp2;
   unsigned int i,j,k;

   if (argc < 2){
	 printf("Uso: %s <total_elementos> \n ", argv[0]);
	 return(1);
   }
   ws = atoi(argv[1]);  //total elementos
   srand(time(NULL));
   unsigned int *data=(unsigned int *) malloc(ws*sizeof(unsigned int));
   unsigned int *cont=(unsigned int *) malloc(MAX*sizeof(unsigned int));
   unsigned int *acc=(unsigned int *) malloc(MAX*sizeof(unsigned int));
   
   for (i=0; i<ws; i++) data[i]=rand()%MAX;

   tmp1=omp_get_wtime();
 
   for (i=0; i<ws; i++){
	      j=data[i];
	      cont[j]++;
   }
   
   tmp2=omp_get_wtime();

   unsigned int test=0;
   for (i=0;i<MAX;i++)
   { 
      test+=cont[i];
   }
   if (test!=ws)
     printf("ERROR DE CONTEO! %d \n",test);
   printf("Time(ms): %.6f \n", (tmp2-tmp1*1000));
   return 0;
}
