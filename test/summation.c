#include <stdio.h>
#include <mpi.h>
#define N 1000

int main(int argc, char **argv) {

    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int start = rank * N / size;
    int end = (rank + 1) * N / size;

    int sum = 0;
    int total_sum = 0;

    for(int i = start; i < end; i++) {
        sum += i;
    }
    printf("Rank %d: %d\n", rank, sum);
    MPI_Reduce(&sum, &total_sum, 1, MPI_LONG, MPI_SUM, 0, MPI_COMM_WORLD);
    
    MPI_Finalize();
    if (rank == 0) {
        printf("Total sum: %d\n", total_sum);
    }
    return 0;
}
