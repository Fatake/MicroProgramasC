#include <stdio.h>
#include <string.h>

int main(int argc, char **argv, char **envp){
	int i = 0;
	char **aux = envp;
	for ( i = 0; i < argc; i++)
		printf("argv[%d]= %s  \n",i,argv[i]);


	printf("\n\nVariables de entorno envp:\n");
	while (*envp)
		printf("%s \n\n",*envp++);


	printf("\n<------------------->\n");
	while (*aux){
		char * str = *aux++;
		if (str[0] == 'U')
			printf("Hola %s\n",str);
	}

	printf("\n\n");
	return 0;
}
