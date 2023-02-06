#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;
    if(rank == 0) {
        int arr[size];
        for(int i=0; i<size; i++)
            scanf("%d", &arr[i]);
        for(int i=1; i<size; i++)
            MPI_Send(&arr[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        int num = arr[0];
        int flag = 1;
        for(int i=2; i<num/2; i++) {
            if(num%i==0) {
                flag = 0;
                break;
            }
        }
        if(!flag)
            printf("Not prime in %d.\n", rank);
        else
            printf("Prime in %d.\n", rank);
            
    }
    else {
        int num;
        MPI_Recv(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        int flag = 1;
        for(int i=2; i<=num/2; i++) {
            if(num%i==0) {
                flag = 0;
                break;
            }
        }
        if(!flag)
            printf("Not prime in %d.\n", rank);
        else
            printf("Prime in %d.\n", rank);
    }
    MPI_Finalize();
    return 0;
}