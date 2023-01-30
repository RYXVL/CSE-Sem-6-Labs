#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
    int size, rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if(rank % 2 == 0)
        printf("Hello from the even rank process - %d.\n", rank);
    else
        printf("Hello from the odd rank process - %d.\n", rank);
    MPI_Finalize();
    return 0;
}