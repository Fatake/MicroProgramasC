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
//
//funciones
//
void clear();
void inter(struct Datos dato[],int i, int i2);
int agrega(struct Datos dato[],int *i);
int borrar(struct Datos dato[],int *cant);
int encuser(struct Datos usuari[],int cant,int *tmp);
void usuarios(struct Datos user[],int cant);
void por_alfa(struct Datos user[],int cant);
void por_edad(struct Datos user[],int cant);
void mostrar(struct Datos user[],int cant);
void guardar(struct Datos user[],int cant);
void cargar(struct Datos user[],int *cant);
//
//Main
//
int main(int argc, char **argv){
	int m=1,i=0,f=0;
	struct Datos reg[10];
	do{
		limpia();
		printf("\n Bienvenido al programa de registros\n");
		printf("\nSeleccione una opción \n");
		printf("\n<---------------------->\n\n");
		printf("1)Agregar nuevo Usuario\n");
		printf("2)Borrar Usuarios\n");
		printf("3)Mostrar usuarios\n");
		printf("\n<---------------------->\n\n");
		printf("4)Guardar Arreglo en documento\n");
		printf("5)Cargar Arreglo de un documento\n");
		printf("\n<---------------------->\n\n");
		printf("\n0)Salir\n");
		printf("\n->");
		scanf("%d",&m);
		switch(m){
			case 1:
				do{
					f=agrega(reg,&i);
				}while(i++<10 && f!=0);
				break;
			case 2:
				borrar(reg,&i);
				break;
			case 3:
				mostrar(reg,i);
				break;
			case 4:
				guardar(reg,i);
				break;
			case 5:
				cargar(reg,&i);
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
//Limpia Buffer
void clear(){    
	int c;
	while ( (c = getchar()) != '\n' && c != EOF ) { }
}
//agrega usuario
int agrega(struct Datos dato[],int *i){
	char cad[50];
	int sal=0;
	limpia();
	printf("\nIngrese nombre\n->");
	gets(cad);
	gets(cad);
	strcpy(dato[*i].nombre,cad);
	printf("Ingrese edad\n->");
	scanf("%d",&dato[*i].edad);
	printf("Ingrese Sexo\n m)masculino \n f)femenino \n->");
	scanf("%s",&dato[*i].sexo);
	printf("Ingrese una dirección\n->");
	gets(&dato[*i].dir);
	gets(&dato[*i].dir);
	printf("\n Desea agregar mas personas?\n 0)para no\n cualquier tecla si\n->");
	scanf("%d",&sal);
	return sal;
}
//Muestra usuarios
void usuarios(struct Datos user[],int cant){
	int i=0;
	printf("Usuarios registrados:\n");
	printf("\n<---------------------->\n\n");
	for(i=0;i<=cant-1;i++){
		printf("numero: %d\n",i+1);
		printf("Nombre-> %s\n",user[i].nombre);
		printf("Edad-> %d\n",user[i].edad);
		printf("Sexo-> %c\n",user[i].sexo);
		printf("Direcion->%s\n",user[i].dir);
		printf("\n<---------------------->\n");
		printf("\n");
	}
}
//Encuentra usuario
int encuser(struct Datos usuari[],int cant,int *tmp){
	char nom[50];
	int i=0,f=0;
	printf("\nIngrese nombre A borrar\n->");
	gets(nom);
	gets(nom);
	do{
		if(!strcmp(usuari[i].nombre,nom)){
			f=1;
			*tmp=i;
			printf("\nBorrando a %s\n",usuari[i].nombre);
		}
	}while(f!=1 && i++<=cant);
	return f;
}
//borrausuario
int borrar(struct Datos dato[],int *cant){
	int tmp=10,f=0,c,i;
	limpia();
	usuarios(dato,*cant);
	f=encuser(dato,*cant,&tmp);
	if(f==0){
		printf("\nUsuario no exitente o ya borrado\n");
	}else{
		for(i=tmp;i<*cant;i++){
			dato[i]=dato[i+1];
		}
		*cant=*cant-1;
	}
	limpia();
	usuarios(dato,*cant);
	printf("\n<---------------------->\n\n");
	printf("Continuar...");
	scanf("%d",&c);
	return tmp;
}
//intercambia entradas
void inter(struct Datos dato[],int i, int i2){
	struct Datos tmp;
	tmp=dato[i];
	dato[i]=dato[i2];
	dato[i2]=tmp;
}
//Orden por a a la z
void por_alfa(struct Datos user[],int cant){
	int i=0,j=0,k=0,aux1,c;
	limpia();
	for(i=0;i<cant-1;i++){
		aux1=i;
		for(j=i+1;j<cant;j++){
			for(k=0;k<strlen(user[j].nombre);k++){
				if(user[j].nombre[k]<user[aux1].nombre[k]){
					aux1=j;
					inter(user,i,aux1);
				}else{
					if(user[j].nombre[k]!=user[aux1].nombre[k])
					break;
				}
			}
		}
	}
	usuarios(user,cant);
	printf("\n\n");
	printf("Continuar...");
	scanf("%d",&c);
}
//orden por edad
void por_edad(struct Datos user[],int cant){
	int i=0,j=0,aux,c;
	limpia();
	for(i=0;i<cant-1;i++){
		aux=i;
		for(j=i+1;j<cant;j++){
			if(user[j].edad<user[aux].edad)
				aux=j;
			inter(user,i,aux);
		}
	}
	usuarios(user,cant);
	printf("\n\n");
	printf("Continuar...");
	scanf("%d",&c);
}
//Menu de mostrar
void mostrar(struct Datos user[],int cant){
	int m=1;
	do{
		limpia();
		printf("\n Mostrar usuarios\n");
		printf("\nSeleccione una opción: \n");
		printf("\n<---------------------->\n\n");
		printf("1)Por orden Alfabetico\n");
		printf("2)Por edad");
		printf("\n<---------------------->\n\n");
		printf("\n0)Salir Menu principal\n");
		printf("\n->");
		scanf("%d",&m);
		switch(m){
			case 1:
				por_alfa(user,cant);
				break;
			case 2:
				por_edad(user,cant);
				break;
			default:
				if(m!=0)
					printf("\n Opcion no disponible \n");
				break;
		}
	}while(m!=0);
}
//Guardar en documento
void guardar(struct Datos user[],int cant){
	int c,i;
	FILE *fp;
	limpia();
	if(cant==0){
		printf("\n ¡¡Usted no a agregado usuarios!!\n");
	}else{
		fp = fopen ("usr.dat", "w");
		for(i=0;i<=cant-1;i++){
				fwrite(&user[i],sizeof(user[i]),1,fp);
				printf("numero: %d\n",i+1);
				printf("Nombre-> %s\n",user[i].nombre);
				printf("Edad-> %d\n",user[i].edad);
				printf("Sexo-> %c\n",user[i].sexo);
				printf("Direcion->%s\n",user[i].dir);
				printf("\n<---------------------->\n");
		}
		fclose(fp);
		printf("\n Usuarios Guardados :) \n");
	}
	printf("\n<-------------------->\n");
	printf("Continuar...");
	scanf("%d",&c);
}
//Cargar de documento
void cargar(struct Datos user[],int *cant){
	int c,i=0;
	FILE *fp;
	limpia();
	fp = fopen("usr.dat","r");
	while(fread(&user[i],sizeof(user[i]),1,fp)) {
		printf("numero: %d\n",i+1);
		printf("Nombre-> %s\n",user[i].nombre);
		printf("Edad-> %d\n",user[i].edad);
		printf("Sexo-> %c\n",user[i].sexo);
		printf("Direcion->%s\n",user[i].dir);
		printf("\n<---------------------->\n");
		i++;
	}
	*cant=i;
	fclose(fp);
	//
	printf("\n<-------------------->\n");
	printf("Continuar...");
	scanf("%d",&c);
}
