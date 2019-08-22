#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int main(void){
char *cad;
char *aux;
int i=0, j=0,c=0;
cad=(char*)malloc(sizeof(cad));
//asignacion dinamica de moria
//char [100]<- asignacion estatica de momira
////malloc regresa bits, es para establecer cuanto quieres que sea un areglo char[40] el usuario elige si son 40 o los que quiera 
////malloc (*cantidad);
////sizeof(*expresion); regresa el tamaño en memoria de algo
aux=(char*)malloc(sizeof(cad));
printf("Programa que lee una cadena y cuenta las palabras \n");
printf("Introduzca texto:\n ->");
gets(cad);
do{
do{aux[j++]=cad[i++];}while(cad[i]!=' ' && cad[i]!='\0');
aux[j]='\0';
j=0;
c++;
printf("\n %s",aux);
}while(cad[i] !='\0');
printf("\n La cantidad de plabras es: %d",c);
return 0;
}
