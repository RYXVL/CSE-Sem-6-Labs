#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
    int size, rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;

    int n;
    if(rank==0) {
        printf("Enter n: ");
        scanf("%d", &n);
    }
    int arr[n];
    if(rank==0) {
        printf("Enter elements of the array: ");
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        for(int i=1; i<size; i++)
            MPI_Send(&n, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
    }
    else
        MPI_Recv(&n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);

    // printf("%d - %d\n", rank, n);
    if(rank==0) {
        // printf("Enter elements of the array: ");
        for(int i=1; i<size; i++)
            for(int j=0; j<n; j++)
                MPI_Send(&arr[j], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
    }
    else {
        for(int j=0; j<n; j++)
            MPI_Recv(&arr[j], 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
    }
    
// printf("%d", size);
    int psum = 0;
    int psumarr[size];
    // int (n/size) = (n-(n%size))/2;
    printf("%d", n/size);
    if(rank==(size-1)) {
        for(int i=rank*(n/size); i<n; i++)
            psum+=arr[i];
        printf("%d - Partial Sum = %d\n", rank, psum);
    }
    else {
        for(int i=rank*(n/size); i<rank*(n/size)+2; i++)
            psum+=arr[i];
        printf("%d - Partial Sum = %d\n", rank, psum);
    }

    if(rank!=0) {
        MPI_Send(&psum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    else {
        for(int j=1; j<size; j++)
            MPI_Recv(&psumarr[j], 1, MPI_INT, j, 0, MPI_COMM_WORLD, &status);
        psumarr[0] = psum;
        int sum = 0;
        for(int i=0; i<size; i++)
            sum+= psumarr[i];
        printf("Final answer at %d is %d.\n", rank, sum);
    }



    

    MPI_Finalize();
    return 0;
}
