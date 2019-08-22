#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define limpia() printf("\033[H\033[J")
struct Datos{
	char nombre[50];
	int edad;
	char sexo;
	char dir[10];
};
int Agrega(struct Datos dato[],int *i);
int busnom(struct Datos dato[]);
int main(int argc, char **argv){
	int m=1,i=0,f=0;
	struct Datos reg[10];
	do{
		limpia();
		printf("\n Bienvenido al programa de registros\n");
		printf("\nSeleccione una opción \n");
		printf("1)Agregar nuevo Usuario\n");
		printf("2)Borrar Usuarios\n");
		printf("3)Mostrar usuarios\n");
		printf("\n0)Salir\n");
		printf("\n->");
		scanf("%d",&m);
		switch(m){
			case 1:
				do{
					f=Agrega(reg,&i);
				}while(i++<10 && f!=0);
				break;
			case 2:
				busnom();
				break;
			case 3:
				//code
				break;
			default:
				if(m!=0)
				printf("\n Opcion no disponible \n");
				else
				limpia();
				printf("Saliendo...\n");
				break;
		}
	}while(m!=0);
	return 0;
}
//funciones
//agrega usuario
int Agrega(struct Datos dato[],int *i){
	char cad[50];
	int sal=0;
	limpia();
	printf("\nIngrese nombre\n->");
	scanf("%s",cad);
	strcpy(dato[*i].nombre,cad);
	printf("Ingrese edad\n");
	scanf("%d",&dato[*i].edad);
	printf("Ingrese Sexo\n m)masculino \n f)femenino \n->");
	scanf("%s",dato[*i].sexo);
	printf("Ingrese una dirección\n->");
	scanf("%s",dato[*i].dir);
	printf("\n Desea agregar mas personas?\n 0)para no\n cualquier tecla si\n->");
	scanf("%d",sal);
	return sal;
}
//borrausuario
int busnom(struct Datos dato[]){
	char nom[50];
	int i=0,tmp=10,f=0;
	limpia();
	printf("\nIngrese nombre A borrar\n->");
	scanf("%s",nom);
	do{
		if(!strcmp(dato[i++].nombre,nom)){
			f=1;
			tmp=i;
		}
	}while(f!=1);
	for(i=tmp;i<10;i++){
		strcpy(dato[i].nombre,dato[i+1].nombre);
		dato[i].edad=dato[i+1].edad;
		dato[i].sexo=dato[i+1].sexo;
		strcpy(dato[i].dir,dato[i+1].dir);
	}
	return tmp;
}
