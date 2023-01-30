#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
    int size, rank;
    int a = 5, b = 7;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if(rank == 0)
        printf("Addition - %d.\n", a + b);
    else if (rank == 1)
        printf("Subtraction - %d.\n", a - b);
    else if (rank == 2)
        printf("Multiplication - %d.\n", a * b);
    else if (rank == 3)
        printf("Division - %d.\n", a / b);
    MPI_Finalize();
    return 0;
}