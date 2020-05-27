#include<stdio.h>
#include <omp.h>
#include <time.h>

int main(){
	omp_set_num_threads(4);
  int a[2][2], b[2][2], c[2][2], i, j;
  int m1, m2, m3, m4 , m5, m6, m7;
 
  printf("Ingrese los elementos de la primera Matriz: ");
  for(i = 0;i < 2; i++)
      for(j = 0;j < 2; j++)
           scanf("%d", &a[i][j]);
 
  printf("Ingrese los elementos de la segunda matriz: ");
  for(i = 0; i < 2; i++)
      for(j = 0;j < 2; j++)
           scanf("%d", &b[i][j]);
 
  printf("\nMatriz A\n");
  for(i = 0; i < 2; i++){
      printf("\n");
      for(j = 0; j < 2; j++)
           printf("%d\t", a[i][j]);
  }
 
  printf("\nMatriz B\n");
  for(i = 0;i < 2; i++){
      printf("\n");
      for(j = 0;j < 2; j++)
           printf("%d\t", b[i][j]);
  }
 
	
 #pragma omp parallel
 {
 #pragma omp sections
 {
	 
 #pragma omp section
 {
  m1= (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
  m2= (a[1][0] + a[1][1]) * b[0][0];
  m3= a[0][0] * (b[0][1] - b[1][1]);
  m4= a[1][1] * (b[1][0] - b[0][0]);
  m5= (a[0][0] + a[0][1]) * b[1][1];
  m6= (a[1][0] - a[0][0]) * (b[0][0]+b[0][1]);
  m7= (a[0][1] - a[1][1]) * (b[1][0]+b[1][1]);
  printf("\n\nNUMERO DE THREAD USADO EN ASIGNACION DE MATRICES AUXILIARES: %d\n", omp_get_thread_num());
  sleep(1);
}
#pragma omp section
{
  sleep(1);
  c[0][0] = m1 + m4- m5 + m7;
  c[0][1] = m3 + m5;
  c[1][0] = m2 + m4;
  c[1][1] = m1 - m2 + m3 + m6;
   printf("\nNUMERO DE THREAD USADO EN ASIGNACION A MATRIZ C: %d\n", omp_get_thread_num());
	sleep(1);
 }

#pragma omp section
{
	sleep(1);
   printf("\nResultado usando Algoritmo de Strassen \n");
   for(i = 0; i < 2 ; i++){
      printf("\n");
      for(j = 0;j < 2; j++)
           printf("%d\t", c[i][j]);
   }
    printf("\nNUMERO DE THREAD PARA IMPRESION DE MATRIZ C: %d\n", omp_get_thread_num());

 }  
 }
}  
 

   return 0;

}
