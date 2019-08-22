#include <stdio.h>
void bien();
int leenu();
void tabmul(int num);
int rep();
int main(void){
	int b=1;
	do{
		bien();
		tabmul(leenu());
		b=rep();
	}while(b==1);
	return 0;
}
void bien(){
	printf("Programa que calcula la tabla de multiplicar\n");
}
//lee numeros
int leenu(){
	int n;
	printf("Ingrese el numero que desea saber la tabla de multiplicar\n ->");
	scanf("%d",&n);
	return n;
}
//tabla de multiplicar
void tabmul(int num){
	int i=0;
	for(i=0;i<=10;i++){
		 printf("\n %d * %d = %d",i,num,i*num);
	}
}
//salir repetidor
int rep(){
	int b=1;
	printf("\n Desea poner otro numero 1 para si cualquier letra par a no: \n->");
	scanf("%d",&b);
	return b;
}
