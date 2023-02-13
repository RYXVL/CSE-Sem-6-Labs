#include <stdio.h>
#include <mpi.h>
#include <string.h>

// int main() {
//     char str[10];
//     scanf("%s", str);
//     printf("%s %ld\n", str, strlen(str));
//     return 0;
// }

int main(int argc, char* argv[]) {
    int size, rank, nvpc = 0;
    int M;
    char str[100], tempstr[100];
    int tempStrLen;
    // double avgP = 0;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;
    int finalArr[size];
    if(rank == 0) {
        printf("Enter the string: ");
        scanf("%s",str);
        tempStrLen = strlen(str)/size;
        // printf("%d %s\n", tempStrLen, str);
        for(int i=1; i<size; i++)
            MPI_Send(&tempStrLen, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
    }
    else {
        MPI_Recv(&tempStrLen, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
    }
    // int mainArr[size*M];
    // int arr[M];
    // if(rank == 0) {
    //     printf("Enter the values of the main array:\n");
    //     for(int i=0; i<(size*M); i++)
    //         scanf("%d", &mainArr[i]);
    // }
    // printf("%d %d\n", tempStrLen, rank);
    ////////////
    MPI_Scatter(str, strlen(str)/size, MPI_CHAR, tempstr, tempStrLen, MPI_CHAR, 0, MPI_COMM_WORLD);
    tempstr[tempStrLen] = '\0';
        // printf("%s %d\n", tempstr, rank);
//////////////

    // avgP /= M;
    for(int i = 0; i<(tempStrLen); i++)
        if(tempstr[i]!='a' && tempstr[i]!='e' && tempstr[i]!='i' && tempstr[i]!='o' && tempstr[i]!='u' && tempstr[i]!='A' && tempstr[i]!='E' && tempstr[i]!='I' && tempstr[i]!='O' && tempstr[i]!='U') {
            // printf("%c\n", tempstr[i]);
            nvpc++; 
        }

    // printf("%d %d\n", nvpc, rank);
    MPI_Gather(&nvpc, 1, MPI_INT, finalArr, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if(rank == 0) {
        // double temp = 0;
        for(int i=0; i<size; i++)
            printf("Rank: %d -> %d\n", rank, finalArr[i]);
        printf("\n");
            // temp += finalArr[i];
        int temp = 0;
        for(int i=0; i<size; i++)
            temp += finalArr[i];
        printf("Final answer is: %d\n", temp);
    }
    MPI_Finalize();
    return 0;
}

