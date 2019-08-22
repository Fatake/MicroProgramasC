#include <stdio.h>
#include <string.h>
int main () {
	char cad[200],inv[200];
	int n, i;
	printf ("Ingrese una frase para mostrarla al revés\n");
	gets (cad);
	n = strlen(cad);
	for (i=0;i<=n;i++)
		inv[n-i]=cad[i];
	printf ("\nLa frase al revés: ");
	for (i=0;i<=n;i++) 
		printf ("%c",inv[i]);
	printf ("\n");
	return 0;
}
	
