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
    int size, rank;
    // int nvpc = 0;
    // int M;
    char str1[100], str2[100], scatteredStr1[100], scatteredStr2[100], mstr1[100];
    int tempStrLen1, tempStrLen2;
    // double avgP = 0;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;
    // int finalArr[size];
    if(rank == 0) {
        printf("Enter the first string: ");
        scanf("%s",str1);
        printf("Enter the second string: ");
        scanf("%s",str2);
        tempStrLen1 = strlen(str1)/size;
        tempStrLen2 = strlen(str2)/size;
        for(int i=1; i<size; i++) {
            MPI_Send(&tempStrLen1, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
            MPI_Send(&tempStrLen2, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
        // for
        // printf("Rank: %d ->  %d | %d\n", rank, tempStrLen1, tempStrLen2);

        // printf("%d %s\n", tempStrLen, str);
        // MPI_Bcast(&tempStrLen1, 1, MPI_INT, 0, MPI_COMM_WORLD);
        // MPI_Bcast(&tempStrLen2, 1, MPI_INT, 0, MPI_COMM_WORLD);
        // for(int i=1; i<size; i++)
        //     MPI_Send(&tempStrLen, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
    }
    // for(int i=0; i<rank; i++)
    // MPI_Barrier(MPI_COMM_WORLD);
    else {
        MPI_Recv(&tempStrLen1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        MPI_Recv(&tempStrLen2, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
    }
        // printf("Rank: %d ->  %d | %d\n", rank, tempStrLen1, tempStrLen2);

    MPI_Scatter(str1, strlen(str1)/size, MPI_CHAR, scatteredStr1, tempStrLen1, MPI_CHAR, 0, MPI_COMM_WORLD);
    MPI_Scatter(str2, strlen(str2)/size, MPI_CHAR, scatteredStr2, tempStrLen2, MPI_CHAR, 0, MPI_COMM_WORLD);
    scatteredStr1[tempStrLen1] = '\0';
    scatteredStr2[tempStrLen2] = '\0';

    // for(int i=0; i<size; i++)
        // printf("%d %s %s\n", rank, scatteredStr1, scatteredStr2);

    // tempstr[tempStrLen] = '\0';
    // for(int i = 0; i<(tempStrLen); i++)
    //     if(tempstr[i]!='a' && tempstr[i]!='e' && tempstr[i]!='i' && tempstr[i]!='o' && tempstr[i]!='u' && tempstr[i]!='A' && tempstr[i]!='E' && tempstr[i]!='I' && tempstr[i]!='O' && tempstr[i]!='U') {
    //         nvpc++; 
    //     }

    // MPI_Gather(&nvpc, 1, MPI_INT, finalArr, 1, MPI_INT, 0, MPI_COMM_WORLD);
    // if(rank == 0) {
    //     for(int i=0; i<size; i++)
    //         printf("Rank: %d -> %d\n", rank, finalArr[i]);
    //     printf("\n");
    //     int temp = 0;
    //     for(int i=0; i<size; i++)
    //         temp += finalArr[i];
    //     printf("Final answer is: %d\n", temp);
    // }
    MPI_Finalize();
    return 0;
}