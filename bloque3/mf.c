#include <stdio.h>

int main(int argc, char **argv){
	printf("Programa que muestra un archivo\n");
	FILE *arc;
	char c;
	arc=fopen("ejem.c","r");
	while(!feof(arc)){
		fscanf(arc,"%c",&c);
		printf("%c",c);
	}
	return 0;
}
