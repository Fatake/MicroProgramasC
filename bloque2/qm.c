#include <stdio.h>
int factor(int nu,int fa){
	//Factorial de un numero
	int i;
	for(i=nu;i>=1;i--) fa=fa*i;
	return fa;
}
int main(){
	char op;
	int sum=0;
	int num, fac=1;
	int i=0, res=1,n=1;
	int f=1, tn=0, x=0, y;
	char sel;
	char ch;
	char cadena[50];
	do
	{
		printf("\n Programa que muestra un menu y tiene varios sub programas \n");
		printf("\n Bienvenido al menu, seleccione una opcion: \n");
		printf("a) Sumatoria de un numero \n");
		printf("b) Factoral de un numero \n");
		printf("c) Caracteres ascii \n");
		printf("d) Promedio \n");
		printf("e) Contador de caracteres \n");
		printf("f) Cambiar caracteres de mayusculas a minusculas \n");
		printf("\"x\") Salir \n");
		printf("Ingrse respuesta\n ->");
		printf("Opcion: ");
		scanf("%s",&op);
		switch (op){
			case 'a':
			//
			//sumatoria de un numero
			//
			printf("Código que calcula la sumatoria \n");
			printf("Ingrese  un valo maximo de suma \n");
			scanf("%d",&n);
			for(i=1;i<=n;i++){
				sum+=i;
			}
			printf("la sumatoria es %d",sum," \n");
			break;
			case 'b':
			//
			//Factoral de un numero 
			//
			printf("Programa que calcula el factorial de un numero \n");
			printf("\n Ingrese un numero \n->");
			scanf("%d",&num);
			if(num==0)
				printf("El Factoria del \"0\" es: %d",fac," \n\t");
			else
				if(num<0)
				printf("Los numeros negativos no tienen factoria \n\t");
				else{
				printf("El factorial del numero %d",num);
				printf(" es: %d",factor(num,fac),"\n\t");
			}
			break;
			case 'c':
			//
			// Caracteres ascii
			//
			n=0;
			for(i=0;i<256;i++) printf("%d-%c",i,(char)i);
			while(i<256){
				printf("%d-%c",i,(char)i);
				printf(" \n");
				i++;
				if(i==n*20){
					printf("Quiere seguir mostrando caracteres?  \n");
					printf("0 para no \n");
					printf("Cualquier tecla para si \n respuestas->");
					scanf("%d",&res);
					if(res!=0)
						n++;
					else
						i=257;
				}
			}
			break;
			case 'd':
			//
			// Promedio
			//
			sum=0;
			num=0;
			printf("Programa que calcula el promedio");
			printf("\n Ingrese numero para dar un promedio, cuando el valor dado sea negativo se detendra");
			while(f==1){
				printf("\n Ingrese un numero \n ->");
				scanf("%d",num);
				if(num<0)
					f=0;
				else{
					sum+=num;
					tn++;
				}
			}
			sum=sum/tn;
			printf("El promedio es: %d",sum);
			break;
			case 'e':
			//
			// Contador de caracteres
			//
			printf("Programa que lee el numero de caracteres de una cadena \n");
			x=0;
			do{
				printf("\n Ingrese una cadena y termine con un \".\" \n ->");
				ch=getchar();
				putchar(ch);
				x++;
			}while (ch!='.');
			printf ("\n%d\n",x);
			break;
			case 'f':
			//
			// Cambiar caracteres de mayusculas a minusculas
			//
			i=0;
			y=1;
			do{
				printf("Escribe un letra o frase: \n");
				scanf("%s",&cadena);
				for(i=0; cadena[i]; i++) 
					if (cadena[i]>97 && cadena[i]<122){
						cadena[i]=cadena[i]-32;
					}
					printf("\n%s\n", cadena);
					printf ("desea repetir o salir 1=repetir 0=salir \n");
					scanf ("%d", &y);
			} while(y != 0);
			break;
		}
	}
	while(op!='x');
}
