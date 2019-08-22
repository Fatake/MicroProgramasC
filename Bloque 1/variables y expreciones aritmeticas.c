// tabla de valores entre grados celsius y fahrenhei variables y expreciones aritmeticas

#include <stdio.h>
/*imprime l a tablña fahrenhei-celsius
para fahr(fahrenhei)=0,20, ..., 300*/
int main()
{
	printf("tabla de valores entre grados celsius y fahrenhei\n\nVariables y expreciones aritmeticas\n\n\n");
	float fahr, celsius;
	int  lower, upper, step;
	lower = 0;
	upper = 300;
	step = 20;
	fahr = lower;
	while (fahr <= upper){
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	system("pause");
	return 0;
}

