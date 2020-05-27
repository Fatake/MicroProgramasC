#include <stdio.h>
#include "omp.h"

void main(){
	int ID=5;
	//omp_set_num_threads(6);
	#pragma omp parallel num_threads(4)
	{
		//Variable de ambiente : $export OMP_NUM_THREADS = X
		//Función de biblioteca: omp_set_num_threads(X);
		//Directiva de compilador: #pragma omp parallel num_threads(X)
		
		/**

			#pragma omp parallel [clause ...]
			if (scalar_expression)
			private (list) variables privabadas 
			shared (list) variables compartidas
			default (shared | none)
			firstprivate (list)
			reduction (operator: list)
			copyin (list)
			num_threads (integer-expression

		 */ 
		ID = omp_get_thread_num();
		printf("Hello(%d) ",ID);
		printf("World(%d) \n",ID);
	}
}
