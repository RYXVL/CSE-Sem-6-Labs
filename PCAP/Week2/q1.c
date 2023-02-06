#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
    int size, rank;
    char word[10];
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;
    if(rank == 0) {
        printf("Enter the word for the %d process: ", rank);
        scanf("%s", word);
        int len = strlen(word)+1;
        MPI_Ssend(&len, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Ssend(word, len, MPI_CHAR, 1, 1, MPI_COMM_WORLD);
        MPI_Recv(word, len, MPI_CHAR, 1, 1, MPI_COMM_WORLD, &status);
        printf("%s recieved at %d process.\n", word, rank);
    }
    else if (rank == 1) {
        int len;
        MPI_Recv(&len, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        MPI_Recv(word, len, MPI_CHAR, 0, 1, MPI_COMM_WORLD, &status);
        printf("%s recieved at %d process.\n", word, rank);
        int i = 0;
        while(word[i]) {
            if(word[i] >= 'a' && word[i] <= 'z')
				word[i] = word[i] - 32;
			else if(word[i] >= 'A' && word[i] <= 'Z')
				word[i] = word[i] + 32;
			i++;
        }
        MPI_Ssend(word, len, MPI_CHAR, 0, 1, MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}
