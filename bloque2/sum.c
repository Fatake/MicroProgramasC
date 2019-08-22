#include <stdio.h>
void bien();
int leen();
int pre();
int sum();
void res(int sum);
//
//main
//
int main(int argc, char **argv){
	bien();
	res(sum());
	printf("\n");
	return 0;
}
//funciones
//inicio
void bien(){
	printf("Programa que suma elementos\n");
}
//lee numeros
int leen(){
	int n=0;
	printf("Ingrese un numero\n");
	scanf("%d",&n);
	return n;
}
//
int pre(){
	int f=0;
	printf("Quiere agregar otro numero ? \n");
	printf("1 para si, cualquier tecla no \n->");
	scanf("%d",&f);
	return f;
}
//sumatoria
int sum(){
	int f=1,sum=0;
	do{
		sum+=leen();
		f=pre();
	}while(f==1);
	return sum;
}
//Mostrar resultado
void res(int sum){
	printf("El resultado es %d",sum);
}
