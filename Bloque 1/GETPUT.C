#include <stdio.h>
void bien();
void leerc(char cd[]);
int contador(char cad[]);
void imp();
int main(){
	bien();
	imp();
	return 1;
}
//inicio
void bien(){
	printf("Programa que calcula cuantos caracteres tiene una cadena con while \n");
	printf("Programa con maximo de 500 caracteres");
}
//lector de cadenas
void leerc(char cd[]){
	printf("introduzca el texto \n");
	scanf("%c",cd);
	printf("%c",cd);
}
//condador de caractes
int contador(char cad[]){
	int i=0, tchar=0;
	while(cad[i]=!'\0'){
		tchar++;
		i++;
	}
	return tchar;
}
void imp(){
	char cd[500];
	leerc(cd);
	printf("La cadena tiene %d carcteres",contador(cd));
}
