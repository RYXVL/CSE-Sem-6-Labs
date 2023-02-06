#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
    int size, rank, num;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;
    if(rank == 0) {
        printf("Enter the number for the %d process: ", rank);
        scanf("%d", &num);
        for(int i=1; i<size; i++)
            MPI_Send(&num, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
    }
    else {
        MPI_Recv(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        printf("%d recieved at %d process.\n", num, rank);
    }
    MPI_Finalize();
    return 0;
}