#include <stdio.h>
#include <stdlib.h>
//
//variables globales
//
int vip[100], pal[50], n1[200], n2[500];
//
//funciones
//
void nuevo();
void Avip();
void Apal();
void An1();
void An2();
void cargar();
void guardar();
//
//main
//
int main (void) { 
	int y, el, i, x; 
		printf ("este progrma permite al usuario visualizar los datos acerca de los asientos del teatro nacional para un evento \n");
		cargar ();
		do {
		printf ("Bienvenido usuario \n Elija la seccion que quiera visualizar: \n 1)Zona VIP \n 2)Palcos \n 3)Nivel 1 \n 4)Nivel 2 \n 5)Salir \n");
		scanf ("%d", &el); //eleccion para el switch	
		fflush( stdin );
			switch (el){
				case 1: 
					printf("Usted eligio la zona VIP \n Esta seccion posee 100 asientos con un precio de 4700 \n ¿Que asiento desea ver? \n");
					Avip();//linea 9
					scanf("%d", &i);
					fflush( stdin );
					if (i<=99 && i>=0){
						if (vip[i]==1){
							printf("Asiento ocupado \n");
						}
						if (vip[i]==0){
							vip[i]=2;
							Avip(); //linea 11
							printf ("¿Desea este asiento? 1) si 2) no \n");
							scanf ("%d", &x);
							fflush( stdin );
							if (x==1){
								vip[i]=1;
							}
							else {
								vip[i]=0;
							}
						}
					}
					else {
						printf ("No existe ese asiento \n");
					}
					break;
				case 2: 
					printf("Usted eligio los palcos \n Esta seccion posee 50 asientos con un precio de 3500 \n ¿Que asiento desea ver? \n");
					Apal();
					scanf("%d", &i);
					fflush( stdin );
					if (i<=50 && i>=0){
						if (vip[i]==1){
							printf("Asiento ocupado \n");
						}
						if (pal[i]==0){
							pal[i]=2;
							Apal(); //linea 12
							printf ("¿Desea este asiento? 1) si 2) no \n");
							scanf ("%d", &x);
							fflush( stdin );
							if (x==1){
								pal[i]=1;
							}
							else {
								pal[i]=0;
							}
						}
					}
					else {
						printf ("No existe ese asiento \n");
					}
					break;
				case 3: 
					printf("Usted eligio el nivel 1 \n Esta seccion posee 200 asientos con un precio de 2825 \n ¿Que asiento desea ver? \n");
					An1();
					scanf("%d", &i);
					fflush( stdin );
					if (i<=199 && i>=0){
						if (n1[i]==1){
							printf("Asiento ocupado \n");
						}
						if (n1[i]==0){
							n1[i]=2;
							An1(); //linea 13
							printf ("¿Desea este asiento? 1) si 2) no \n");
							scanf ("%d", &x);
							fflush( stdin );
							if (x==1){
								n1[i]=1;
							}
							else {
								n1[i]=0;
							}
						}
					}
					else {
						printf ("No existe ese asiento \n");
					}
					break;
				case 4: 
					printf("Usted eligio el nivel 2 \n Esta seccion posee 500 asientos con un precio de 1500 \n ¿Que asiento desea ver? \n");
					An2();
					scanf("%d", &i);
					fflush( stdin );
					if (i<=499 && i>=0){
						if (n2[i]==1){
							printf("Asiento ocupado \n");
						}
						if (n2[i]==0){
							n2[i]=2;
							An2(); //linea 14
							printf ("¿Desea este asiento? 1) si 2) no \n");
							scanf ("%d", &x);
							fflush( stdin );
							if (x==1){
								n2[i]=1;
							}
							else {
								n2[i]=0;
							}
						}
					}
					else {
						printf ("No existe ese asiento \n");
					}
					break;
				case 5:
					y=0; 
					guardar ();
					exit (1); 
					break;
				default: 
					printf("Opción no valida \n");
					break;
			}
		} while (y=!0);
	return 0;
}
//
//
//Da valor 0 a las matrices
void nuevo(){
	int i;
	for (i=0; i<100; i++){
		vip[i]=0;
	}
	for (i=0; i<50; i++){
		pal[i]=0;
	}
	for (i=0; i<200; i++){
		n1[i]=0;
	}
	for (i=0; i<500; i++){
		n2[i]=0;
	}
}
//Imprime la matriz de VIP
void Avip(){
	int c, i;
	c=0;
	for (i=0; i<100; i++ ){
	printf ("%d \t", vip[i]);
	c++;
	if (c==10){
		printf ("\n");
		c=0;
		}
	}
}
//Imprime la matriz de palcos
void Apal(){
	int c1, c2, i;
	c1=0;
	c2=0;
	for (i=0; i<50; i++ ){
	printf ("%d \t", pal[i]);
	c1++;
	c2++;

	if (c1==5){
		printf ("\n");
		c1=0;
		c2=0;
		}
	if (c2==3){
		printf ("\t \t \t \t");
		c2=0;
	}
	}
}
//Imprime la matriz del nivel 1
void An1(){
	int c, i;
	c=0;
	for (i=0; i<200; i++ ){
	printf ("%d \t", n1[i]);
	c++;
	if (c==10){
		printf ("\n");
		c=0;
		}
	}
}
//Imprime la matriz del nivel 2
void An2(){
	int c, i;
	c=0;
	for (i=0; i<500; i++ ){
	printf ("%d \t", n2[i]);
	c++;
	if (c==10){
		printf ("\n");
		c=0;
		}
	}
}
//Carga el archivo
void cargar(){
	int i;
	FILE *fp;
	fp = fopen("ventaboletos.bin", "r");
	if (fp==NULL){
		nuevo();
	}
	else{
		i=0;
		while(fread(&vip[i],sizeof(vip[i]),1,fp)){
			i++;
		}
		i=0;
		while(fread(&pal[i],sizeof(pal[i]),1,fp)){
			i++;
		}
		i=0;
		while(fread(&n1[i],sizeof(n1[i]),1,fp)){
			i++;
		i=0;
		}
		while(fread(&n2[i],sizeof(n2[i]),1,fp)){
			i++;
		}
	}
}
//guardar el archivo
void guardar(){
	int i;
	FILE *fp; 
	fp = fopen("ventaboletos.bin", "w");
    	for (i=0; i<100; i++){
    		fwrite (&vip[i],sizeof(vip[i]),1,fp);
    	}
    	for (i=0; i<50; i++){
    		fwrite (&pal[i],sizeof(pal[i]),1,fp);
    	}
    	for (i=0; i<200; i++){
    		fwrite (&n1[i],sizeof(n1[i]),1,fp);
    	}
    	for (i=0; i<500; i++){
    		fwrite (&n2[i],sizeof(n2[i]),1,fp);
    	}
    fclose (fp);
}
