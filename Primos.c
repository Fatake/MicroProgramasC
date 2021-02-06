#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//Definiciones
#define limpia() printf("\e[1;1H\e[2J")

//prototipos
void initArray(int **h, int number);
void addNumeroArray(int **h, int numToAdd);
void imprimeArry(int *h);
int sumatoria_hksMasP_sobreK(int *h,int p);
int sumatoria_hks_sobre_k(int *h);
int mcd(int a, int b);
int mcm(int a, int b);
bool esPrimo(int numero);

//Variales globales
int kSize = 0;
/**
 * Main
 */
int main(int argc, char **argv){
	int primoP = 0,i = 0;
	int lamndaMax = 1;
	int cofAlfa = 0,cofLamnda = 0, cons = 00;
	int *h;
	bool f = false;
	/**
	 * Ingreso de datosss
	 */
	// Ingreso de P
	printf("Ingrese un Primo \n\033[0;36mP\033[0m = ");
	scanf("%d",&primoP);

	// Ingreso de Lamnda
	printf("\nIngrese un λ maximo \n\033[0;36mλ\033[0m = ");
	scanf("%d",&lamndaMax);

	// Ingreso de h1,h2,...,hk
	do{
		int number = 0;
		printf("Ingrese \n\033[0;36mh%d \033[0m = ",(i+1));
		scanf("%d",&number);
		//se agrea el numero a la lista
		//Si es la primera vez inicializa el areglo
		if (!i){
			initArray( &h , number);
		}else{
			addNumeroArray( &h, number);
		}
		
		printf("Desea agregar otro numero?\nsi) 1\nno) 0\n->");
		scanf("%d",&number);
		if (!number){
			f = true;
		}
		limpia();
		i++;
	} while (!f);
	kSize ++;
	limpia();

	/**
	 * Inicio del teorema
	 */
	//Valores iniciales
	printf("\n\033[0;36mP\033[0m = %d, \033[0;36mk\033[0m = %d \n",primoP,kSize);
	imprimeArry(h);

	//
	// Empieza
	//
	// 1
	cofAlfa = sumatoria_hksMasP_sobreK(h,primoP);

	// 2
	cofLamnda = mcm(cofAlfa,10);

	// Print n = cofLamndaλ + p
	printf("\nSea \033[0;36mn\033[0m = %d\033[0;36mλ\033[0m + %d",cofLamnda,primoP);
	
	// 3
	cons = sumatoria_hks_sobre_k(h);

	// cofAlfaα - cons = cofLamndaλ + primoP
	printf("\nSea %d\033[0;36mα\033[0m - %d = %d\033[0;36mλ\033[0m + %d",cofAlfa,cons,cofLamnda,primoP);
	
	//Despeje de α
	cofLamnda = cofLamnda / cofAlfa;
	primoP = (primoP+cons) / cofAlfa;

	// α en terminos de λ
	printf("\n-> \033[0;36mα\033[0m = %d\033[0;36mλ\033[0m + %d",cofLamnda,primoP);
	
	// 4
	// q = cofAlfa((cofLamnda/cofAlfa)λ + ((primoP+cons)/cofAlfa))-cons
	printf("\nSea \033[0;36mq\033[0m = %d(%d\033[0;36mλ\033[0m + %d) - %d",cofAlfa,cofLamnda,primoP,cons);
	printf("\n\n");
	for ( i = 1; i <= lamndaMax; i++){
		int q = cofAlfa*(cofLamnda*i + primoP) - cons;
		if (esPrimo(q)){
			printf("\nPara \033[0;36mλ\033[0m = %d -> q = %d es primo",i,q);
		}
	}
	
	printf("\n\n");
	return 0;
}

void initArray(int **h, int number){
	*h = malloc(sizeof(int));
	if (*h == NULL){
		printf("\033[0;31m Error al asignar memoria\n");
		exit(EXIT_FAILURE);
	}
	(*h)[0]=number;
}

void addNumeroArray(int **h, int numToAdd){
	static int tamContador = 0;
	tamContador++;
	kSize = tamContador;
	int *aux;
	// reasignacion para agregar el nuevo numero
	aux = realloc( *h, (tamContador+1)*sizeof(int) );
	if (aux == NULL){
		printf("\033[0;31m Error al asignar memoria\n");
		exit(EXIT_FAILURE);
	}
	*h = aux;
	(*h)[tamContador]=numToAdd;
}

void imprimeArry(int *h){
	int i =0;
	for ( i = 0; i < kSize; i++){
		printf("h%d = %d ",(i+1),h[i]);
	}
	printf("\n<---------------------->\n");
}

int sumatoria_hksMasP_sobreK(int *h,int p){
	int suma = 0,i = 0;
	for ( i = 0; i < kSize; i++){
		suma += (h[i] + p);
		//printf("+(%d + %d) ",h[i],p);
	}
	//printf("= %d \n-----------------------------",suma);
	//printf("\n\t K = %d\n",kSize);
	return suma/kSize;
}

int sumatoria_hks_sobre_k(int *h){
	int suma = 0,i = 0;
	for ( i = 0; i < kSize; i++){
		suma += h[i];
	}
	return suma/kSize;
}

int mcd(int a, int b) {
    int temporal = 0;
    while (b != 0) {
        temporal = b;
        b = a % b;
        a = temporal;
    }
    return a;
}

int mcm(int a, int b) {
    return (a * b) / mcd(a, b);
}

bool esPrimo(int numero){
	/**
	 * Retorna:
	 * true si es primo
	 * false si no es primo
	 */
	int divisores = 2;
	while( divisores < numero ){
		if( numero % divisores == 0){
			return false;
		}
		divisores++;
	}
	return true;
}