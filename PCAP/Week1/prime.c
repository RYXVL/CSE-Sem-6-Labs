#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
    int size, rank;
    int start = 1, end = 100;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if(rank == 0) {
        int start0 = start;
        int end0 = end/2;
        int flag;
        for(int i=start0; i<=end0; i++) {
            flag = 1;
            for(int j=2; j<=i/2; j++) {
                if(i%j==0) {
                    flag = 0;
                    break;
                }
            }
            if(i==1) continue;
            else if(flag==1) printf("%d ", i);
        }
        printf("\n");
    }
    else if (rank == 1) {
        int start1 = end/2+1;
        int end1 = end;
        int flag;
        for(int i=start1; i<=end1; i++) {
            flag = 1;
            for(int j=2; j<=i/2; j++) {
                if(i%j==0) {
                    flag = 0;
                    break;
                }
            }
            if(i==1) continue;
            else if(flag==1) printf("%d ", i);
        }
    }
    printf("\n");
    MPI_Finalize();
    return 0;
}