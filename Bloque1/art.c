#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
void bien();
void cadena(char cad[]);
void letxlet(char cad[],char aux[],int *i,int*j);
void poncenti(char aux[],int j);
int comparacad(char aux[],char *art[],int j);
void checart(char aux[],char *art[],int j);
void palxpal(char cad[],char aux[],char *art[]);
//
//main
//
int main(){
	char *art[]={"el","los","les","Las","la","al"};
	char cad[200];
	char aux[200];
	bien();
	palxpal(cad,aux,art);
	return 0;
}
//funciones
//inico
void bien(){
	printf("Programa que lee una cadena y dice cuantos articulos tiene");
}
//lee cadena
void cadena(char cad[]){
	printf("Introduzca texto:\n ->");
	gets(cad);
}
//palabra por palabra
void letxlet(char cad[],char aux[],int *i,int*j){
	do{
		aux[*j++]=cad[*i++];
	}while(cad[i]!=' ' && cad[i]!='\0');
}
//pone centinelas de fin de cadena
void poncenti(char aux[],int j){
	aux[j]='\0';
}
//comparador de cadenas
int comparacad(char aux[],char *art[],int j){
	int c=0,k=0;
	for(k=0;k<=(int)strlen(art);k++){
		if(!(strcmp(aux[j],&art[k])))
			c++;
	}
	return c;
}
//checa articulos
void checart(char aux[],char *art[],int j){
	int a=comparacad(aux,art,j);
	if(a!=0)printf("\n Extisten %s",a,"Articulos");
}
//Palabra por palabra
void palxpal(char cad[],char aux[],char *art[]){
	int i=0, j=0;
	do{
		letxlet(cad,aux,&i,&j);
		poncenti(aux,j);
		checart(aux,art,j);
		j=0;
	}while(cad[i] !='\0');
}
//otras funciones
