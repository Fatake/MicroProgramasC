#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#define MX 99
#define randomize (srand(time(NULL)))
#define random(num) (rand()%(num))
typedef int Item;
typedef struct Elemenot{
	Item dato;
	struct Elemento* sig;
}Nodo;
void InsertarCabezaLista(Nodo** cabeza, Item entrada);
Nodo* NuevoNodo(Item x);
//main
int main(int argc, char **argv){
	Item d;
	Nodo *cabeza,*ptr;
	int k;
	cabeza=NULL;/*Debe de estas vacio*/
	randomize;
	for(d=random(MX);d;){
		InsertarCabezaLista(&cabeza,d);
		d=random(MX);
	}
	/*Se Recorre la lista para escribir los pares*/
	for(k=0,ptr=cabeza;ptr;){
		if(ptr->dato%2==0){
			printf("%d",ptr->dato);
			k++;
			printf("\n");/*Cada 12 datos salta d elinea*/
		}
		ptr = ptr->sig;
	}
	printf("\n\n");
	return 0;
}
void InsertarCabezaLista(Nodo** cabeza, Item entrada){
	Nodo *nuevo;
	nuevo = NuevoNodo(entrada);
	nuevo->sig = *cabeza;
	*cabeza=nuevo;
}
Nodo* NuevoNodo(Item x){
	Nodo *a;
	a=(Nodo*)malloc(sizeof(Nodo));
	a->dato=x;
	a->sig=NULL;
	return a;
}

