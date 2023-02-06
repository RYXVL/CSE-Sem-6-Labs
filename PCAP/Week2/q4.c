#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
    int size, rank; 
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;
    if(rank == 0) {
        int num;
        printf("Enter the number for the %d process: ", rank);
        scanf("%d", &num);
        num++;
        MPI_Ssend(&num, 1, MPI_INT, (rank+1)%size, 0, MPI_COMM_WORLD);
        MPI_Recv(&num, 1, MPI_INT, size-1, 0, MPI_COMM_WORLD, &status);
        printf("%d at %d process.\n", num, rank);
    }
    else {
        int num;
        MPI_Recv(&num, 1, MPI_INT, rank-1, 0, MPI_COMM_WORLD, &status);
        printf("%d at %d process.\n", num, rank);
        num++;
        MPI_Ssend(&num, 1, MPI_INT, (rank+1)%size, 0, MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}