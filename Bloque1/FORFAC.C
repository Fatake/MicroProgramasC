# include <stdio.h>
void bien();
int leer();
void dis();
int factor(int nu,int fa);
int main(){
	bien();
	dis();
	printf("\n");
	return 0;
}
void bien(){
	printf("Programa que calcula el factorial de un numero \n");
}
//lee numeros
int leer(){
	int num=0;
	printf("\n Ingrese un numero \n->");
	scanf("%d",&num);
	return num;
}
//calcula el factorial
int factor(int nu,int fa){
	int i;
	for(i=nu;i>=1;i--) fa=fa*i;
	return fa;
}
//discrimina numeros
void dis(){
	int fac=1;
	int num=leer();
	if(num==0)
		printf("El Factoria del \"0\" es: %d",fac," \n\t");
	else
		if(num<0)
			printf("Los numeros negativos no tienen factoria \n\t");
		else{
			printf("El factorial del numero %d \n",num);
			printf(" es: %d",factor(num,fac),"\n\t");
		}
}
