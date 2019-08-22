#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define limpia() printf("\033[H\033[J")
typedef struct Datos{
	char nombre[50];
	int edad;
	char sexo;
	char dir[10];
	struct Datos *sig;
}Usuarios;
//
//funciones
//
int menu();
Usuarios *nele(void);
char *gets(char *s);
void wait();
int agrega(Usuarios **inicio,Usuarios **final);
void borrar(Usuarios **inicio,Usuarios **final);
void uss(Usuarios *inicio);
void por_alfa(Usuarios **inicio, Usuarios **final);
void por_edad(Usuarios **inicio, Usuarios **final);
void mostrar(Usuarios **inicio,Usuarios **final);
//
//Main
//
int main(int argc, char **argv){
	int m=1,f=0;
	Usuarios *inicio,*final;
	final=NULL;
	inicio=NULL;
	//---------------------------------------------------------------------------------
	do{
		m=menu();
		switch(m){
			case 1:
				do{
					f=agrega(&inicio,&final);
				}while(f!=0);
				break;
			case 2:
				borrar(&inicio,&final);
				break;
			case 3:
				mostrar(&inicio,&final);
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
//
//funciones
//
//Menu
int menu(){
	int m;
	limpia();
	printf("\n			Bienvenido al programa de registros con listas ligadas\n");
	printf("\n	Seleccione una opción:\n");
	printf("\n<---------------------->\n\n");
	printf("1)Agregar nuevo Usuario.\n");
	printf("2)Borrar Usuarios.\n");
	printf("3)Mostrar usuarios.\n");
	printf("\n<---------------------->\n\n");
	printf("\n0)Salir.\n");
	printf("\n-> ");
	scanf("%d",&m);
	return m;
}
//Reserva memoria para el nodo
Usuarios *nele(void){
	return (Usuarios *)malloc(sizeof(Usuarios));
}
//Espera
void wait(){
	int c;
	printf("\n<---------------------->\n");
	printf("Continuar...");
	scanf("%d",&c);
}
//agrega usuario
int agrega(Usuarios **inicio,Usuarios **final){
	int sal=0;
	Usuarios *nuevo;
	nuevo=nele();
	limpia();
	printf("\n			Usuario nuevo:\n");
	printf("\n<---------------------->\n");
	printf("\nIngrese nombre\n->");
	gets(nuevo->nombre);
	gets(nuevo->nombre);
	printf("\nIngrese una dirección\n->");
	gets(nuevo->dir);
	printf("\nIngrese edad\n->"); 
	scanf("%d",&nuevo->edad);
	printf("\nIngrese Sexo\n m)masculino \n f)femenino \n->"); 
	scanf("%c",&nuevo->sexo);
	scanf("%c",&nuevo->sexo);
	// el campo sig va a ser NULL por ser el último elemento de la lista
	nuevo->sig=NULL;
	// ahora metemos el nuevo elemento en la lista. lo situamos al final de la lista 
	// comprobamos si la lista está vacía. si inico==NULL es que no hay ningún elemento en la lista 
	if(*inicio==NULL){
		*inicio=nuevo;
		*final=nuevo;
	}else{
		// el que hasta ahora era el último tiene que apuntar al nuevo 
		*final=(*final)->sig=nuevo;
	}
	//uss(*inicio);
	printf("\n<---------------------->\n");
	printf("\n Desea agregar mas personas?\n 0)para no");
	printf("\n cualquier tecla si\n->");
	scanf("%d",&sal);
	return sal;
}
//Muestra usuarios
void uss(Usuarios *inicio){
	Usuarios *aux; 
	int i=0;
	aux=inicio;
	printf("\n			Usuarios:\n");
	printf("\n<---------------------->\n\n");
	while(aux!=NULL){
		printf("Usuario #%d:\n",i+1);
		printf("Nombre: %s\n",aux->nombre);
		printf("Direcion: %s\n",aux->dir);
		printf("Edad: %d\n",aux->edad);
		printf("Sexo: %c\n",aux->sexo);
		printf("\n<---------------------->\n");
		aux=aux->sig;
		i++;
	}
	if(i==0)
		printf("\n\n			Usted no ha agregado ningun contacto\n\n");
}
//borrausuario
void borrar(Usuarios **inicio,Usuarios **final){
	int b=0;
	char nom[50];
	Usuarios *aux1,*aux2,*aux3;
	limpia();
	printf("			Borra usuarios\n");
	if(*inicio == NULL){
		printf("\n\n			Usted no ha agregado ningun contacto\n\n");
	}else{
		uss(*inicio);
		printf("\n<---------------------->\n");
		printf("Ingrese Nombre a eliminar: \n->");
		gets(nom);
		gets(nom);
		// proceso de eliminacion
		if(*final == *inicio){//si solo hay uno
			if(!strcmp((*inicio)->nombre,nom)){
				aux3=*final;
				*final=*inicio=(*final)->sig;
				free(aux3);
				printf("\nEliminado 1!!\n");
			}else b=2;
		}else{
			if(!strcmp((*inicio)->nombre,nom)){//si es el primero
				aux3=*inicio;
				*inicio=(*inicio)->sig;
				aux3->sig=NULL;
				free(aux3);
				printf("\nEliminado 2!!\n");
			}else{
				aux1=(*inicio)->sig;
				aux2=*inicio;
				do{
					if(!strcmp(aux1->nombre,nom)){
						//si esta en medio
						aux2->sig=aux1->sig;
						aux1->sig=NULL;
						b=1;
						break;
					}else{
						if(aux1->sig==NULL){
							b=2;
							break;
						}else{
							aux1=aux1->sig;
						aux2=aux2->sig;
						}
					}
				}while(aux1->sig != NULL );
				if(b==1){
					free(aux1);
					printf("\nEliminado 3!!\n");
				} 
			}
		}
		if(b==2) printf("\nEL usuario no exite...\n");
	}
	wait();
}
//Orden por a a la z
void por_alfa(Usuarios **inicio, Usuarios **final){
	Usuarios *aux1,*aux2,*aux3;
	limpia();
	printf("			Usuarios por Orden Alfabetico\n");
	if((*inicio)->nombre==NULL){
		printf("No hay usuarios\n");
	}else{
		if((*inicio)==(*final)){
			uss(*inicio);
		}else{
			aux1=*inicio;
			while(aux1->sig != NULL ){
				aux2=aux1->sig;
				do{
					if(strcmp(aux1->nombre,aux2->nombre) > 0){
						aux3=aux2;
						aux2=aux1;
						aux1=aux3;
					}
					aux2=aux2->sig;
				}while(aux2 != NULL);
				aux1=aux1->sig;
			}
			uss(*inicio);
		}
	}
	wait();
}
//orden por edad
void por_edad(Usuarios **inicio, Usuarios **final){
	Usuarios *aux1,*aux2,*aux3;
	limpia();
	printf("\n\n			Usuarios por Orden Edad\n");
	if((*inicio)->nombre==NULL){
		printf("No hay usuarios\n");
	}else{
		if((*inicio)==(*final)){
			uss(*inicio);
		}else{
			aux1=*inicio;
			while(aux1->sig != NULL ){
				aux2=aux1->sig;
				do{
					if(aux1->edad > aux2->edad){
						aux3=aux2;
						aux2=aux1;
						aux1=aux3;
					}
					aux2=aux2->sig;
				}while(aux2 != NULL);
				aux1=aux1->sig;
			}
			uss(*inicio);
		}
	}
	wait();
}
//Menu de mostrar
void mostrar(Usuarios **inicio,Usuarios **final){
	int m=1;
	do{
		limpia();
		printf("\n			Mostrar usuarios\n");
		printf("\n	Seleccione una opción: \n");
		printf("\n<---------------------->\n\n");
		printf("1)Por orden Alfabetico\n");
		printf("2)Por edad(Mayor a menor)\n");
		printf("\n<---------------------->\n");
		printf("\n0)Salir Menu principal\n");
		printf("\n->");
		scanf("%d",&m);
		switch(m){
			case 1:
				//uss(*inicio);
				//wait();
				por_alfa(inicio,final);
				break;
			case 2:
				por_edad(inicio,final);
				break;
			default:
				if(m!=0)
					printf("\n Opcion no disponible \n");
				break;
		}
	}while(m!=0);
}
