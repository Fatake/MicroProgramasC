# include <stdio.h>
int cali(int *tot);
int calpro(int n,int total);
int sal();
int main(){
	int b,n=0,tot;
	do{
		tot=0;
		printf("\n Programa que calcula el promedio de a lumnos y se repite \n");
		n=cali(&tot);
		printf("\n el promedio es: %d",calpro(n,tot));
		b=sal();
	}while(b!=1);
	return 0;
}
//recibe calificaciones
int cali(int *tot){
	int i=0,n=0,cal=0;
	printf("Ingrese las calificaiones de los alumnos, si desea acabar ingrese cualquier cantidad negativa \n");
	while(i==0){
		printf("\n ->");
		scanf("%d",&cal);
		if(cal<0)
			i=1;
		else{
			*tot=*tot+cal;
			n++;
		}
	}
	return n;
}
//calcula promedios
int calpro(int n,int total){
	int pro=0;
	pro=total/n;
	return pro;
}
//salir
int sal(){
	int b;
	printf("\n ¿Desea salir?");
	printf("\n 1 para si");
	printf("\n Cualquier tecla para no\n ->");
	scanf("%d",&b);
	return b;
}
