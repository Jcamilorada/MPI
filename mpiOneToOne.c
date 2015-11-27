#include <stdio.h>
#include <ctype.h>
#include "mpi.h"
#include <string.h>


int main(int argc,char *argv[]){
        int size, rank, dest, source, count, tag=1;
        char inmsg[2];
        char outmsg[2];
        MPI_Status Stat;

        MPI_Init(&argc,&argv);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);

        if (rank == 0) {
          dest = 1;
          source = 1;
          printf("Insert char here:\n");
          outmsg[0] = getchar();
          MPI_Send(outmsg, 1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
          MPI_Recv(inmsg, 1, MPI_CHAR, source, tag, MPI_COMM_WORLD, &Stat);
          printf("\nMsg received in %d: %s\n", rank, inmsg);
        }else if (rank == 1) {
          dest = 0;
          source = 0;
          MPI_Recv(inmsg, 1, MPI_CHAR, source, tag, MPI_COMM_WORLD, &Stat);
          char upper[2];
          upper[0] = toupper(inmsg[0]);
          strcpy(outmsg, upper);
          MPI_Send(outmsg, 1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
         }

        MPI_Get_count(&Stat, MPI_CHAR, &count);
        printf("\nTask %d: Received %d char(s) from task %d with tag %d \n",
                   rank, count, Stat.MPI_SOURCE, Stat.MPI_TAG);

        MPI_Finalize();
}
