#include <stdio.h>
#include <stdlib.h>
void bien();
void leec(char cad[]);
void ponpa(char cad[],char aux[],int *pos);
int contador(char cad[],char aux[]);
int main(){
	char aux[100];
	char cad[100];
	bien();
	leec(cad);
	printf("\n La cantidad de plabras es: %d \n",contador(cad,aux));
	return 0;
}
//inicio
void bien(){
	printf("Programa que lee una cadena y cuenta las palabras \n");
}
//Lector de cadenas
void leec(char cad[]){
	printf("Introduzca texto:\n ->");
	//scanf("%s",cad);
	gets(cad);
}
//poner cada palabra en aux
void ponpa(char cad[],char aux[],int *pos){
	int j=0;
	int i=*pos;
	do{
		aux[j++]=cad[i++];
	}while(cad[i]!=' ' && cad[i]!='\0');
	*pos=i+1;
}
//contador
int contador(char cad[],char aux[]){
	int c=0,i=0;
	do{
		ponpa(cad,aux,&i);
		c++;
	}while(cad[i] !='\0');
	return c;
}
