#include <stdio.h>
#include <string.h>
void bien();
void leec(char cad[]);
void camcad(char cad[],char in[]);
void impfra(char cad[],char in[]);
//
//Main
//
int main (void) {
	char cad[150],in[150];
	int i=0;
	bien();
	leec(cad);
	camcad(cad,in);
	impfra(cad,in);
	return 0;
}
void bien(){
	printf("Programa que lee una frase y la muestra alrevez \n");
}
//lee cadenas
void leec(char cad[]){
	printf ("Ingrese una frase para mostrarla al revés\n");
	gets(cad);
	//scanf("%c",cad);
}
//Cambia cadenas de orden
void camcad(char cad[],char in[]){
	int i=0;
	do{
		in[i]=cad[strlen(cad)-i];
	}while(cad[i++]!='\0');
}
//imprime cadenas
void impfra(char cad[],char in[]){
	int i=0;
	printf ("\n La frase cambiada es:\n ");
	for (i=0;i<=(int)strlen(cad);i++){
		printf ("%c",in[i]);
	}
	printf("\n");
}
