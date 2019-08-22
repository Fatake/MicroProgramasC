#include <stdio.h>
#include <malloc.h>
int main(int argc, char **argv)
{
	int n=10;
	int *p,i,*aux;
	//p=&n;
	printf("%d,%x \n", p, p);
	aux=p=(int*)malloc(sizeof(int)*n);
	printf("%d,%x \n", *p, p);
	for(i=0;i<n;i++){
		*p=1;p++;
	}
	p=aux;
	for(i=0;i<n;i++){
		printf("%d,%x \n", *p, p);
		p++;
	}
	return 0;
}
