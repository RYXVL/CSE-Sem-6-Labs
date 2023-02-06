#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
    int size, rank; int len;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int num[100];
    MPI_Buffer_attach(num, sizeof(int)*100);
    MPI_Status status;
    if(rank == 0) {
        int arr[size];
        printf("Enter the elements of array for the %d process:\n", rank);
        for(int i=0; i<size; i++)
            scanf("%d", &arr[i]);
        for(int i=1; i<size; i++)        
            MPI_Bsend(&arr[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
    }
    else if (rank%2==0) {
        int num;
        MPI_Recv(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        printf("%d at %d process.\n", num*num, rank);
    }
    else {
        int num;
        MPI_Recv(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        printf("%d at %d process.\n", num*num*num, rank);
    }
    MPI_Buffer_detach(num,&len);
    MPI_Finalize();
    return 0;
}