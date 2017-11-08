#include <mpi.h>
#include <stdio.h>
#include <math.h>
#include <time.h> 

double func(double x)
{
    return sqrt(1-x*x);
}
int main(int argc, char** argv) 
{
    MPI_Init(NULL, NULL);


    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    MPI_Barrier(MPI_COMM_WORLD);

    int n = 0;
    if(world_rank == 0)
    {
        n = 1000000000/world_size;
    }

    double global_from = -1;
    double global_to = 1;

    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
    double local = 0;

    double local_from = global_from + ((global_to - global_from)/world_size)*world_rank;
    double local_to = local_from + (global_to - global_from)/world_size;

    double window = (local_to-local_from)/n;
    
    for(int i = 0; i<n; i++)
    {
        local += func(local_from+i*window) * window;
    }
    
    double global= 0;

    MPI_Reduce(&local, &global, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if(world_rank == 0)
    {
       printf("Total: %35.32f\n", global*2);
    }
    MPI_Finalize();

}