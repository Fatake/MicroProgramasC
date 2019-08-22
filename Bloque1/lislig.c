#include <stdio.h>
#include <malloc.h>
#include <stdlib.h> 
typedef struct Datos{
	char nombre[50];
	int edad;
	struct Datos *sig;
}DATOS;

int main(int argc, char *argv[]){
	DATOS *Lista=NULL,*aux,*nodo;
	int i=0;
	printf("\nテスト これは動作します。\n");
	do{
		printf("\nテスト これは動作します。%d\n",i);
		if(Lista==NULL){//primer elemento
			printf("\nあなたがこれを行うならば、プログラム。\n");
			Lista=(DATOS*)malloc(sizeof (DATOS));
			Lista->edad=i++;
			printf("\nこれがあります：%d\n",Lista->edad);
			Lista->sig=NULL;
			aux=Lista;//Da la direccion de lista al auxiliar
		}
		else{//Para varios nodos mas
			nodo=(DATOS*)malloc(sizeof (DATOS));
			nodo->edad=i++;
			nodo->sig=NULL;
			//incremento
			nodo->sig=nodo;//en siguiente se va a poner la direccion de nodo
			aux=aux->sig;//El apuntador de aux se pone ahora en auxiliar siguiente
		}
	}while(i<=10);
	while(Lista!=NULL){
	printf("%x:%d\n",Lista,Lista->edad);
		Lista=Lista->sig;
	}
    return 0;
  }
