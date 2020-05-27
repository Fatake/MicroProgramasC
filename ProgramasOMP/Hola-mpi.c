#include <mpi.h>
#include <stdio.h>
int main(int argc, char *argv[]){
	/**
	 * mpirun -np 4
	 * 
	 * 
	 * saber cuantos procesos se va a usar 
	 * {
		 * host 
		 * ip add (DNs)
		 * lista de ips que forma el closhet
		 * 
		 * 127.0.0.1 localhost
		}
	 */
	int rank, size;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	printf(“Hello, I am %d of %d\n", rank, size);
	MPI_Finalize();
	return 0;
}
