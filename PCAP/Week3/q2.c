#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
    int size, rank, M;
    double avgP = 0;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;
    double finalArr[size];
    if(rank == 0) {
        printf("Enter the value of M: ");
        // for(int i=0; i<size; i++)
        scanf("%d", &M);
        for(int i=1; i<size; i++)
            MPI_Send(&M, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
    }
    else {
        MPI_Recv(&M, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
    }
    int mainArr[size*M];
    int arr[M];
    if(rank == 0) {
        // int mainArr[size*M];
        // int arr[M];
        printf("Enter the values of the main array:\n");
        for(int i=0; i<(size*M); i++)
            scanf("%d", &mainArr[i]);
    }
    MPI_Scatter(mainArr, M, MPI_INT, arr, M, MPI_INT, 0, MPI_COMM_WORLD);
    for(int i=0; i<M; i++)
        avgP += arr[i];
    avgP /= M;
    // printf("%d %f\n", rank,  avgP);
    // recvNum = factorial(recvNum);
    MPI_Gather(&avgP, 1, MPI_DOUBLE, finalArr, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
        // MPI_Gather(&recvNum, 1, MPI_INT, mainArr, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // for(int i=0; i<size; i++)
    //         printf("%f", finalArr[i]);
    // MPI_Barrier(MPI_COMM_WORLD);
    if(rank == 0) {
        double temp = 0;
        // for(int i=0; i<size; i++)
        //     printf("%f", finalArr[i]);
        for(int i=0; i<size; i++)
            temp += finalArr[i];
        // printf("%f", temp);
        temp /= size;
        printf("Final answer is: %f\n", temp);
    }
    MPI_Finalize();
    return 0;
}

