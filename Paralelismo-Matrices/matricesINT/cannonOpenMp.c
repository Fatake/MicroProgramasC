#include <stdio.h>
#include <sys/resource.h>
#include "matrix.h"
#include "omp.h"

long get_mem_usage(){
    struct rusage myusage;
    getrusage(RUSAGE_SELF,&myusage);

    return myusage.ru_maxrss;
}

/**
 * multiply the corresponding submatrices of A and B.
 */
void process_mult(Matrix *A, Matrix *B, Matrix *C, int P_SQRT, float BLOCK_SZ,int P) {
    int r, c, id, k, 
        rbegin, rend, cbegin, cend, // block delimiters
        l, m;
    Matrix sa, sb, sc;

    #pragma omp parallel default(none) private(l, m, r, c, k, rbegin, rend, cbegin, cend, id, sa, sb, sc) shared(A, B, C,P_SQRT,BLOCK_SZ) num_threads(P)
    {
        id = omp_get_thread_num();
        rbegin = (id/P_SQRT)*BLOCK_SZ;
        rend = rbegin + BLOCK_SZ;

        cbegin = (id % P_SQRT) * BLOCK_SZ;
        cend = cbegin + BLOCK_SZ;

        create_matrix(&sa, BLOCK_SZ, BLOCK_SZ);
        create_matrix(&sb, BLOCK_SZ, BLOCK_SZ);
        create_matrix(&sc, BLOCK_SZ, BLOCK_SZ);

        //copy the blocks for this process
        for(r = rbegin, l = 0; r < rend; r++, l++){
            for(c = cbegin, m = 0; c < cend; c++, m++){
                sa.data[l][m] = A->data[r][c];
                sb.data[l][m] = B->data[r][c];
                sc.data[l][m] = C->data[r][c];
            }
        }
        
        matrix_product(&sc, &sa, &sb);

        //put results back to C
        for(r = rbegin, l = 0; r < rend; r++, l++){
            for(c = cbegin, m = 0; c < cend; c++, m++){
                C->data[r][c] = sc.data[l][m];
            }
        }
    }
}

int main(int argc, char **argv){
    int N = atoi(argv[1]);//Tam Matriz
    int P_SQRT =  atoi(argv[2]);//Num Procesos
    int P = (P_SQRT * P_SQRT); //number of processes
    float BLOCK_SZ = (N / P_SQRT) ;//block size

    Matrix A, B, C;
    double t1, t2;
    int i;
   
    create_matrix(&A, N, N);
    create_matrix(&B, N, N);
    create_matrix(&C, N, N);

    populate_matrix(&A);
    populate_matrix(&B);

    shift_matrix_left(&A,BLOCK_SZ, 1);
    shift_matrix_up(&B,BLOCK_SZ, 1);

    t1 = omp_get_wtime();
    for(i = 0; i < P_SQRT; i++){
        process_mult(&A, &B, &C,P_SQRT,BLOCK_SZ,P);
        shift_matrix_left(&A, BLOCK_SZ, 0);
        shift_matrix_up(&B, BLOCK_SZ, 0);
    }
    t2 = omp_get_wtime();

    printf("\nMatriz: %dx%d \nProcesos: %d\n",N,N,P_SQRT);
    printf("Tiempo: %.6f segundos\n", (t2 - t1));
    printf("Memoria utilizada: %1d en Kilobytes\n",get_mem_usage());
    return 0;
}

