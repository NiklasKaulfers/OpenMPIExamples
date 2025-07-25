
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include "mpi.h"


main(int argc, char **argv){
    char message[256];
    int i,rank,size,tag=99;
    char machine_name[256];

    MPI_Status status;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    gethostname(machine_name, 255);





    if (rank==0){
        printf("M with MPI_Send/MPI_Recv \n");
    }
    for (i=0;i<size;i++){
        sprintf(message,"Hello world from process %d running on %s",rank,machine_name);
        MPI_Send(message, 256,MPI_CHAR,0,tag,MPI_COMM_WORLD);
        MPI_Recv(message,256,MPI_CHAR,i,tag,MPI_COMM_WORLD,&status);
        printf("Message %d : %s\n",i,message);
    }

    /*
    printf("M without MPI functions\n");
    for (i=0;i<size;i++){
        sprintf(message,"Hello world from rank %d running on %s",rank,machine_name);
        printf("Message from process = %d : %s\n",i,message);
    }
    */

    MPI_Finalize();
    

    return 0;

}



