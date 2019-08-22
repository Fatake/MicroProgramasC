#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
//programa con vectores y apuntadores con arreglos
int main(int argc, char **argv){
	int t=0;
	int b=1;
	int i=0;
	int *v1,*v2,*v3;
	int *aux1,*aux2,*aux3;
	char sel;
	do{//dowhile
		printf("Programa que lee vectores y los suma y resta");
		printf("\n Ingrese el tamaño de los vectores \n ->");
		scanf("%d",&t);
		printf("\n");
		if (t<=0){//1 if
			printf("\n El vector no puede tener el tamaño ",t);
		}//1 if
		else{//1 else
			printf("\n seleccione \"s\" para sumar y \"r\"para restar \n ->");
			setbuf(stdin,NULL);
			scanf("%c",&sel);
			if(tolower(sel)=='s'){//2 if
			
				aux1=v1=(int*)malloc(sizeof(t)*t);
				aux2=v2=(int*)malloc(sizeof(t)*t);
				aux3=v3=(int*)malloc(sizeof(t)*t);

				printf("\n Ingrese los valores del primer vector, uno por uno \n ->");
				for(i=1;i<=t;i++){//vector 1
					scanf("%d",v1);
					v1++;
				}
				printf("\n Ingrese los valores del segundo vector, uno por uno \n ->");
				for(i=1;i<=t;i++){//vector 2
					scanf("%d",v2);
					v2++;
				}
				v1=aux1;
				v2=aux2;
				for(i=1;i<=t;i++){//suma de los vectores
					*v3=*v1+*v2;
					v1++;
					v2++;
					v3++;
				}
				v3=aux3;
				printf("\n El vector resultante es \n");
				for(i=1;i<=t;i++){ //mostrando vector V3
					printf("\n ->%d",*v3,"");
					v3++;
				}
			}//2 if
			else{ // 2 else
					if (tolower(sel)=='r'){// 3 if
			
					aux1=v1=(int*)malloc(sizeof(t)*t);
					aux2=v2=(int*)malloc(sizeof(t)*t);
					aux3=v3=(int*)malloc(sizeof(t)*t);

					printf("\n Ingrese los valores del primer vector, uno por uno \n ->");
					for(i=1;i<=t;i++){ //vector 1
						scanf("%d",v1);
						v1++;
					}
					printf("\n Ingrese los valores del segundo vector, uno por uno \n ->");
					for(i=1;i<=t;i++){ //vector 2
						scanf("%d",v2);
						v2++;
					}
					v1=aux1;
					v2=aux2;
					for(i=1;i<=t;i++){ //suma de los vectores
						*v3=*v1-*v2;
						v1++;
						v2++;
						v3++;
					}
					v3=aux3;
					printf("\n El vector resultante es \n");
					for(i=1;i<=t;i++){ //mostrando vector V3
						printf("\n ->%d",*v3,"");
						v3++;
					}
				}// 3 if
				else printf("\n respuesta no existente");
				
			}// 2 else
		}//1 else
		printf("\n \n Quiere realizar una nueva operacion?");
		printf("\n \"1\" para si y cualquier tecla para no \n ->");
		scanf("%d",&b);
	}while (b==1);//dowhile
	return 0;
}
