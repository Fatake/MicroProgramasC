# include <stdio.h>
void bien();
void assci();
int main(){
	bien();
	assci();
	return 0;
}
void bien(){
	printf("Programa que muestra caracteres assci \n");
}
void assci(){
	int n=1,i=0,val=20,z=0;
	for(i=0;i<256;i++){
		printf("%d : %c",i,(char)i);
		printf(" \n");
		if(i==val*n){
			//0printf("Mostrando los primero %d caracteres \n",n*i);
			//printf("quiere agregar mas caracteres precione enter \n");
			scanf("%d",&z);
			n++;
		}
	}
}

	/*
	// otra forma con getch(), y con get char();
	n=1;
	int val=20;
	for(i=0;i<256;i++){
		printf("%d-%c",i,(char)i);
		printf(" \n");
		if(i==val*n){
			getchar();
			n++;
		}
	}*/
	/*
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
	}*/
