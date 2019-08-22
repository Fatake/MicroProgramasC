#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void bien();
void leec(char cad[]);
int tcad(char cad[]);
int arts(char cad[], int t);
void imp(int c);
//
//main
//
int main(){
	char cad[200];
	bien();
	leec(cad);
	imp(arts(cad,tcad(cad)));
	return 0;
}
//inico
void bien() {
	printf("Programa que lee una cadena y dice cuantos articulos tiene\n");
}
//lee cacena
void leec(char cad[]){
	printf ("ingrese una frase\n ->");
	fflush(stdout);//limpia buffer
	gets(cad);
}
//tamaño cadena
int tcad(char cadena[]) {
	int x;
	x=strlen(cadena);
	return x;
}
//checa los articulos
int arts(char cad[], int t) {
	int i, art=0;
	char *ars = ("el","los","les","las","la","al");
	for (i=0; i<=t; i++) {
		if (cad[i] == *ars)
			art++;
		}
	return art;
}
//imprime cuantos articulos encontró
void imp(int c){
	printf ("\n Número de artículos = %d \n",c);
}
