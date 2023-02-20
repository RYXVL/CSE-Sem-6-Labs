#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
    int size, rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int sendN = rank+1, recvN;
    MPI_Scan(&sendN, &recvN, 1, MPI_INT, MPI_PROD, MPI_COMM_WORLD);
    MPI_Scan(&recvN, &sendN, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    if(rank == size-1)
        printf("Answer is: %d\n", sendN);
    MPI_Finalize();
    return 0;
}
