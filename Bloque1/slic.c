#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
//funciones
void bien();
void pregun(int argc,char *argv[]);
int convertidor(char argv[],int size);
int suma(char *cdc[],int cnum);
//
//main
//
int main(int argc, char *argv[]){
	bien();
	pregun(argc,argv);
	printf("\n");
	return 1;
}
//
//funciones
//
//inicio
void bien(){
	printf("Programa que suma los numero dados desde la terminal \n \n");
}
//discrimina cuantos caracteres hay en linea de comando
void pregun(int argc,char *argv[]){
	if (argc==1){
		printf("Error, no existen numeros \n");
		exit(0);
	}else{
		printf("La suma de los numero en la linea de comandos es :%d",suma(argv,argc));
	}
}
//convertidor de char a int
int convertidor(char argv[],int size){
	int i=0,dig=0,f=0,a=0;
	if(argv[i]=='-'){
		i++;
		size--;
		f=-1;
	}else{
		f=1;
	}
	while(argv[i]!='\0'){
		//printf("\n numero \n%c",argv[i]);
		if(argv[i]<=57 && argv[i]>=48){
			dig+=((int)pow(10,size--))*((argv[i])-48)*(f);
		}
		argv[i++];
	}
	return dig;
}
//For para el numero de numeros puestos
int suma(char *cdc[],int cnum){
	int i=0,size=0,num=0;
	for(i=1;i<=cnum-1;i++){
		size=(int)strlen(cdc[i])-1;
		num+=convertidor(cdc[i],size);	
	}
	return num;
}
