# include <stdio.h>
# include <stddef.h>
void cha();
void in();
void floa();
void doubl();
int main(){
	cha();
	in();
	floa();
	doubl();
	printf("\n");
	return 0;
}
void cha(){
	printf("Tamaño de char %c",sizeof(char)," \n");
}
void in(){
	printf("Tamaño de int %d",sizeof(int)," \n");
}
void floa(){
	printf("Tamaño de float %f",sizeof(float)," \n");
}
void doubl(){
	printf("Tamaño de double %e",sizeof(double)," \n");
}
