#include <stdio.h>
void bien();
int leenu();
void tabmu(int n);
int rep();
int main(){
	int b=1;
	do{
		bien();
		tabmu(leenu());
		b=rep();
	}while(b==1);
	return 0;
}
void bien(){
	printf("Programa que calcula la tabla de multiplicar \n");
}
int leenu(){
	int n=0;
	printf("Ingrese el numero que desea saber la tabla de multiplicar\n ->");
	scanf("%d",&n);
	return n;
}
//Tabla de multiplicar
void tabmu(int n){
	int i=0;
	do{
		 printf("\n %d * %d = %d",i,n,i*n);
	}while(i++<=10);
}
//repetidor
int rep(){
	int b=1;
	printf("\n desea poner otro numero 1 para si cualquier letra par a no: \n->");
	scanf("%d",&b);
	return b;
}
