#include <stdio.h>

int main(void){
	int b=1,n=0,i=0;
	printf("tabla de multiplicar\n");
	do{
		printf("Ingrese el numero que desea saber la tabla de multiplicar\n ->");
		scanf("%d",&n);
		while(i++<=11){
			 printf("\n %d",i," * %d",n," = %d",i*n);
		}
		printf("\nn desea poner otro numero 1 para si cualquier letra par a no: \n->");
		scanf("%d",&b);
	}while(b==1);
	return 0;
}
