#include <stdio.h>
#include <mpi.h>

int factorial(int n) {
    int ans = 1;
    while(n > 0) {
        ans *= n--;
    }
    return ans;
}

int main(int argc, char* argv[]) {
    // printf("%d", factorial(5));
    // 1+2+6+24
    int size, rank, recvNum;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int mainArr[size];
    if(rank == 0) {
        printf("Enter the values of the array:\n");
        for(int i=0; i<size; i++)
            scanf("%d", &mainArr[i]);
    }
    MPI_Scatter(mainArr, 1, MPI_INT, &recvNum, 1, MPI_INT, 0, MPI_COMM_WORLD);
    recvNum = factorial(recvNum);
    MPI_Gather(&recvNum, 1, MPI_INT, mainArr, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if(rank == 0) {
        int temp = 0;
        for(int i=0; i<size; i++)
            temp += mainArr[i];
        printf("Final answer is: %d\n", temp);
    }
    MPI_Finalize();
    return 0;
}

