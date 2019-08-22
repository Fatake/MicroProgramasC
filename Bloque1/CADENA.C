#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
void cad(char *a);
int contcar(char *a);
void imp(char *a,int totcar);
//
//main
//
int main(){
	char *c;
	cad(c);
	imp(c,contcar(c));
	return 0;
}
//cuando introducen la cadena
void cad(char *a){
	printf("Ingrese texto \n");
	scanf("%s",a);
}
//contador de caracteres
int contcar(char *a){
	int sumcad=0;
	while(a++!='\0'){
		sumcad++;
	}
return sumcad;
}
//imprimir
void imp(char *a,int totcar){
	printf ("la cadena es: %s y el numero de caracteres es: %d",a, totcar);
}
