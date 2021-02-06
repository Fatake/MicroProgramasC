#include <stdio.h>
void bien();
int bas();
int alt();
int area(int alt,int bas);
void tot(int area);

/**
 * Main
 */
int main(){
	bien();
	tot(area(alt(),bas()));
	printf("\n");
	return 0;
}

void bien(){
	printf("Programa que calcula el area de un triangulo \n");
}

int bas(){
	int base;
	printf("\n Proporcione una Base\n ->");
	scanf("%d", &base);
	return base;
}

int alt(){
	int al;
	printf("\n Proporcione una altura \n ->");
	scanf("%d", &al);
	return al;
}
int area(int alt,int bas){
	int are=(bas*alt)/2;
	return are;
}
void tot(int area){
	printf("\n El area del triagulo es: %d",area);
}
