#include <stdio.h>
#include <string.h>
//pu4 code
int main(void){
	int t=0;
	int b=1;
	int i;
	do{
		printf("Programa que lee vectores y los suma");
		printf("\n Ingrese el tamaño de los vectores \n ->");
		scanf("%d",&t);
		if (t<=0){
			printf("\n El vector no puede tener el tamaño ",t);
		}
		else{
			int v1[t], v2[t];
			printf("\n Ingrese los valores del primer vector, uno por uno \n ->");
			for(i=0;i<=t-1;i++)//vector 1
				scanf("%d",&v1[i]);
			printf("\n Ingrese los valores del segundo vector, uno por uno \n ->");
			for(i=0;i<=t-1;i++)//vector 2
				scanf("%d",&v2[i]);
			for(i=0;i<=t-1;i++)//suma de los vectores
				v1[i]=v1[i]+v2[i];
			printf("\n El vector resultante es \n");
			for(i=0;i<=t-1;i++)//el vector suma se guara en v1
				printf("\n ->%d",v1[i],"");
		}
		printf("\n Quiere realizar una nueva suma?");
		printf("\n \"1\" para si y cualquier tecla para no \n ->");
		scanf("%d",&b);
	}
	while (b==1);
	return 0;
}
