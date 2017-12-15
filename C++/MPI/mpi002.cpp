#include <mpi.h>
#include <stdio.h>



int main() {
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Get the name of the processor
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    // Print off a hello world message
    printf("Hello world from processor %s, rank %d out of %d processors\n", processor_name, world_rank, world_size);
    MPI_Barrier(MPI_COMM_WORLD);


    int n = 0;
    if(world_rank == 0)
    {
        n = 1;
    }
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Hello world from processor %s, rank %d out of %d processors: %d\n", processor_name, world_rank, world_size,n);

    // Finalize the MPI environment.
    MPI_Finalize();
}
