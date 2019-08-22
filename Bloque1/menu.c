#include <stdio.h>
#include <stdlib.h>
//Alumno Paulo Cesar Ruiz Lozano
//Matricula: 201727952
//limpiar pantalla libreria stdlib.c
void clrscr()
{
    system("@cls||clear");
}
int factor(int nu,int fa){
	int i;
	for(i=nu;i>=1;i--) fa=fa*i;
	return fa;
}
//Factorial de un numero
int facc(){
  int num, fac=1;
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
}
//codigo ASCII
int ascii(){
int i=0, res=1,n=1;
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
}
//Promedio de numeros
int prom(){
  int num,f=1,sum=0,tn=0;
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
}

//contador de caracteres
int cu_char(void)
{
	char ch;
	int x;
	
	x=0;
	
	do
	{
	ch=getchar();
	putchar(ch);
	x++;
	}
	while (ch!='.');
	printf ("\n%d\n",x);
}

//sumatoria de un número
int sum(void){
	int n,i;
	int sum=0;
	printf("Código que calcula la sumatoria \n");
	printf("Ingrese  un valo maximo de suma \n");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		sum+=i;
	}
	printf("la sumatoria es %d",sum," \n");
}

//cambia la cadena a minusculas
int cadena(){
  char cadena[50];
	int i, y;
	y=1;
	do{
		printf("Escribe un letra o frase: \n");
		scanf("%s", &cadena);
		for(i = 0; cadena[i]; i++) 
			if (cadena[i]>97 && cadena[i]<122){
				cadena[i]=cadena[i]-32;
			}

	printf("\n%s\n", cadena);
	printf ("desea repetir o salir 1=repetir 0=salir \n");
	scanf ("%d", &y);
	} while(y != 0);
}
//
//principal
//
int main(void){
  int me=1, sel;
  do{
    printf("Programa que muestra un menu y tiene varios sub programas \n");
    printf("\n Bienvenido al menu, seleccione una opcion: \n");
    printf("a) Sumatoria de un numero \n");
    printf("b) Factoral de un numero \n");
    printf("c) Caracteres ascii \n");
    printf("d) Promedio \n");
    printf("e) Contador de caracteres \n");
    printf("f) Cambiar caracteres de mayusculas a minusculas \n");
    printf("Ingrse respuesta\n ->");
    scanf("%c",sel);
    switch(sel) {

       case 'a' :
          clrscr();
          sum();
          break;
          
       case 'b' :
          clrscr();
          facc();
          break;
          
       case 'c' :
          clrscr();
          ascii();
          break;
          
       case 'd' :
          clrscr();
          prom();
          break;
          
       case 'e' :
          clrscr();
          cu_char();
          break;
          
       case 'f' :
          clrscr();
          cadena();
          break;
          
       default :
        printf("Opcion no disponible");
    }
    printf("\n desea elegir un nuevo programa?");
    printf("\n \" 0 \" para no, cualquier tecla para si");
    scanf("%d",&me);
    }while(me==1);
	return 0;
}
