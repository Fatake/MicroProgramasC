//Getopt() manejo de opciones -algo
#include <stdio.h>
#include <unistd.h>
#define ARGUMENTOS "i:oh"

int main (int argc, char *argv[]) {
	int opcion = 0;
	char *opcion1Valores = NULL;

	while ( (opcion = getopt(argc, argv, ARGUMENTOS)) != -1) {
		switch( opcion ) {
			case 'i':
				/*
				 optarg tiene los valores despues del argumento
				 -algo valores
				 optarg = valores;

				 si no existen valores
				 optarg = (NULL);
				 */
				opcion1Valores = optarg;
				printf("\nOpcion i = %s", opcion1Valores);
			break;
			case 'o':
				printf("\nOpcion o ");
			break;
			case 'h':
				printf("Parametos admitidos\n -i valor \n");
				printf("-o\n -h ayuda\n");
				return 0;
			break;
			case '?':
				/*
				 getopt retorna ? para parametros desconocidos
				 */
				if (optopt == 'i') {
					printf("\nMissing mandatory input option");
				} else {
					printf("\nParametro desconocido");
				}
			break;
		}
	}

	printf("\n");
	return 0;
 }