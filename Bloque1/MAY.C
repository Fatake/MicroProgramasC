#include <stdio.h>
void bien();
void leec(char cad[]);
void cammay(char cad[]);
int salir();
int main(){
	char cad[100];
	int y=1;
	bien();
	do{
		leec(cad);
		cammay(cad);
		printf("\n%s\n", cad);
		y=salir();
	} while(y != 0);
	return 0;
}
void bien(){
	printf("Programa que cambia de minusculas a mayusculas\n");
}
//lee cadenas
void leec(char cad[]){
	printf("Escribe un letra o frase: \n");
	//scanf("%s", &cad);
	gets(cad);
}
//CAmbiar mayusculas
void cammay(char cad[]){
	int i=0;
	for(i = 0; cad[i]; i++){
		if (cad[i]>97 && cad[i]<122){
			cad[i]=cad[i]-32;
		}
	}
}
//salir del repetidor 
int salir(){
	int y=1;
	printf ("desea repetir o salir 1=repetir 0=salir \n");
	scanf ("%d", &y);
	return y;
}
