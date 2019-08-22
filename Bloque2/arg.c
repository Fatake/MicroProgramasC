#include <stdio.h>
void bien();
void leearg(char *argv[],int argc);
int main(int argc, char *argv[]){
	bien();
	leearg(argv,argc);
	printf("\n");
	return 0;
}
void bien(){
	printf("Programa que lee los argumentos de la linea de comandos\n");
}
//lector de argumentos
void leearg(char *argv[],int argc){
	int i=0;
	for(i=0;i<=argc;i++) printf("\n %s",argv[i]);
}

