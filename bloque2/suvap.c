#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
void bien();
int tamvect();
int *resermem(int t);
void llevec(int *v,int ve,int t);
void sumvec(int *v1,int *v2,int*v3,int t);
void mosvec(int *v,int t);
void condi(int t);
int salrep();
void sumat();
//
//main
//
int main(int argc, char **argv){
	bien();
	sumat();
	return 0;
}
//
//funciones
//
//inico
void bien(){
	printf("Programa que lee vectores y los suma");
}
//lee tamaños de vectores
int tamvect(){
	int t;
	printf("\nIngrese el tamaño del vector \n ->");
	scanf("%d",&t);
	return t;
}
//reserva memoria
int *resermem(int t){
	return (int*)malloc(sizeof(int)*t);
}
//llenar vector
void llevec(int *v,int ve,int t){
	int i=0;
	printf("\n Ingrese los valores del vector %d, uno por uno \n",ve);
	for(i=0;i<=t-1;i++){//vector 1
		printf("\n ->");
		scanf("%d",v);
		v++;
	}
}
//suma de vectores
void sumvec(int *v1,int *v2,int*v3,int t){
	int i=0;
	for(i=0;i<=t;i++){
		*v3=*v1+*v2;
		v1++;
		v2++;
		v3++;
	}
}
//mostrar vector
void mosvec(int *v,int t){
	int i=0;
	printf("\n El vector resultante es:\n");
	for(i=0;i<=t-1;i++){//el vector suma se guara en v1
		printf("\n ->%d",*v,"");
		v++;
	}
}
//pregunta discriminante
void condi(int t){
	int *aux1, *aux2, *aux3;
	int *v1, *v2, *v3;
	if (t<=0){
		printf("\n El vector no puede tener el tamaño ",t);
	}else{
		aux1=v1=resermem(t);
		aux2=v2=resermem(t);
		aux3=v3=resermem(t);
		llevec(v1,1,t);
		llevec(v2,2,t);
		v1=aux1;
		v2=aux2;
		sumvec(v1,v2,v3,t);
		v3=aux3;
		mosvec(v3,t);
	}
}
//salida del repetidor
int salrep(){
	int f=0;
	printf("\n Quiere realizar una nueva suma?");
	printf("\n \"1\" para si y cualquier tecla para no \n ->");
	scanf("%d",&f);
	return f;
}
//while para repetir el programa
void sumat(){
	int f=1,t=0;
	do{
		t=tamvect();
		condi(t);
		f=salrep();
	}
	while (f==1);
}
