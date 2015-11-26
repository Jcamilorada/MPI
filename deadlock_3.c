#include <stdio.h>
#include "mpi.h"
#include <ctype.h>

int main(nt argc, char** argv)
{
    int size, rank, dest, source, count, tag = 1;

    MPI_Status Stat;

    char recvbuf1[20];
    char recvbuf2[20];
    char sendbuf1[20] = "message from 1";
    char sendbuf2[20] = "message from 2";

    MPI_Init(NULL,NULL);

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank == 0)
    {
      dest = 1;
      source = 1;

      MPI_Sendrecv (
          sendbuf1, 1,
          MPI_CHAR,
          dest,
          tag,
      		recvbuf1,
          1,
          MPI_CHAR,
          source,
          tag,
          MPI_COMM_WORLD, &Stat);

    }
    else if (rank == 1)
    {
        dest = 0;
      	source = 0;

        MPI_Sendrecv (
            sendbuf2,
            1,
            MPI_CHAR,
            dest,
            tag,
        		recvbuf2,
            1,
            MPI_CHAR,
            source,
            tag,
            MPI_COMM_WORLD, &Stat);
     }

    MPI_Get_count(&Stat, MPI_CHAR, &count);
    printf(
        "Task %d: Received %d char(s) from task %d with tag %d \n",
       	rank, count, Stat.MPI_SOURCE, Stat.MPI_TAG);

    MPI_Finalize();
}
