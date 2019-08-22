#include <stdio.h>
#include <string.h>

void bien();
void leec(char ch[]);
int tam(char ch[]);
int com(char fra[], int t);
int pali(int res);
//
//main
//
int main(){
	int t, r=1;
	char ch[200];
	bien();
	leec(ch);
	pali(com(ch, tam(ch)));
	return 0;
}
//inicio
void bien(){
	printf ("\nPrograma que lee una frase y dicta si es un palindrome*\n");
}
//lee la frase
void leec(char ch[]) {
	printf ("\nEsbrine una frase\n -> ");
	fflush(stdout);//limpia buffer
	gets(ch);
}
//Tamaño de frase
int tam(char ch[]) {
	int n=strlen(ch);
	return n;
}
//compara de adelante hacia atras
int com(char fra[], int t){
	int i, j, res=1;
	j=t-1;
	for (i=0; i<t/2; i++, j--) {
		if (*(fra+i) != *(fra+j)) {
			res=0;
			break;
		}
	}
	return res;
}
//Dice si es o no palindrome
int pali(int res){
	if (res)
		printf ("\n Es palindrome\n");
	else
		printf ("\n No es palindrome\n");
}
