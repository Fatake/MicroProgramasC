# include <stdio.h>
int valmax();
int sumt(int m);
void impr(int m);
int main(){
	printf("Código que calcula la sumatoria \n");
	impr(sumt(valmax()));
	printf("\n");
	return 0;
}
int valmax(){
	int n;
	printf("Ingrese  un valo maximo de suma \n");
	scanf("%d",&n);
	return n;
}
int sumt(int m){
	int sum=0,i;
	for(i=1;i<=m;i++){
		sum+=i;
	}
	return sum;
}
void impr(int m){
	printf("\nLa sumatoria es: %d",m);
}
