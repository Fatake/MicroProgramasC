#include <stdio.h>
#include <malloc.h>
int tamvect();
int *resermem(int t);
void leevec(int *v,int tam);
int valbus();
int buscar(int *v,int t,int valb);
void mostrar(int num, int c);
int repeter();
//
//main
//
int main(){
	int b=1,tam=0,val=0,tot=0;
	int *v;
	do{
		printf("Programa que lee un vector y busca un numero \n");
		tam=tamvect();//tamaño de vector
		v=resermem(val);//asgina el tamaño a v
		leevec(v,tam);//lee elementos de v
		val=valbus();//lee el valor a buscar
		tot=buscar(v,tam,val);//busca el valor val
		mostrar(val,tot);//el numero se repite tantas veces
		b=repeter();//modifica b para salir
	}
	while (b==1);
	return 0;
}
//
//funciones
//
//lee tamaños de vectores
int tamvect(){
	int t;
	printf("\nIngrese el tamaño del vector \n");
	scanf("%d",&t);
	return t;
}
//reserva memoria
int *resermem(int t){
	return (int*)malloc(sizeof(int)*t);
}
//leer valores vector
void leevec(int *v,int tam){
	int i=1;
	while(i++<=tam){
		printf("\n Ingrese el valor %d \n ->",i-1);
		scanf("%i",v++);
	}
}
//lee valor a buscar
int valbus(){
	int a;
	printf("\n Ingrese el valor a buscar \n ->");
	scanf("%i",&a);
return a;
}
//busca el valor en el vector
int buscar(int *v,int t,int valb){
	int j=0,c=0;
	for(j=0;j<=t;j++){//buscar valores en arreglo
		if(v[j]==valb){
			c++;
		}
	}
return c;
}
//mostrar cuantas veces se repite
void mostrar(int num, int c){
	printf("\nEl numero %d se encontró %d veces \n",num,c);
}
//repetidor
int repeter(){
	int b=0;
	printf("\n Quiere poner un nuevo arreglo??");
	printf("\n \"1\" para si y cualquier tecla para no \n ->");
	scanf("%d",&b);
return b;
}

