#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

int main(int argc, char *argv[]){
	double sum = 0;
	double h;
	double x = 0;
	int N = 0;
	int i;
	FILE *ff;
    int DEBUG=0;
    
    if(MPI_SUCCESS != MPI_Init(&argc, &argv)){
		printf("Error in MPI_Init\n"); 
		exit(-1); 
	}
	
    int size;
    if(MPI_SUCCESS != MPI_Comm_size(MPI_COMM_WORLD, &size)){
		printf("Error in MPI_Comm_size\n"); 
		exit(-1); 
	}
	
    int rank;
    if(MPI_SUCCESS != MPI_Comm_rank(MPI_COMM_WORLD, &rank)){
        printf("Error in MPI_Comm_rank\n"); 
		exit(-1); 
	}
    MPI_Status status;

    if(rank==0) {
        if((ff = fopen("pi.dat","r")) == NULL){
            printf("Error: open pi.dat\n"); 
			exit(-1);
        } 
        if(DEBUG) 
			printf("rank 0, \"pi.dat\" opened\n");
        fscanf(ff, "%d", &N);
        if(DEBUG) 
			printf("rank 0, N readed: %d\n", N);
        if(N <= 0) 
			N = 1000;
        fclose(ff);
        if(DEBUG) 
			printf("rank 0, start sending\n");
    }

    if(MPI_SUCCESS != MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD)){
        printf("Error in MPI_Bcast\n"); 
		exit(-1); 
	}
    h = 2.0 / N;

    double x_beg=(rank*N)/size*h;
    double x_beg_next=((rank+1)*N)/size*h;
    if(DEBUG) 
		printf("rank %d, x_beg=%f\n", x_beg);
	for(x = x_beg; x < x_beg_next - h; x += h){
	    sum += 0.5*(sqrt(4.0 - x*x)+sqrt(4.0-(x+h)*(x+h)))*h;
	}
	
    if(rank == size-1)
        sum += 0.5*sqrt(4.0-x*x)*(2.0-x);
    else
        sum += 0.5*(sqrt(4.0 - x*x)+sqrt(4.0-(x_beg_next)*(x_beg_next)))*(x_beg_next-x);
	
    if(DEBUG) printf("rank %d, counted sum: %f\n", rank, sum);


    double sum_final;
    if(MPI_SUCCESS != MPI_Reduce(&sum, &sum_final, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD)){
        printf("Error in MPI_Reduce\n");
		exit(-1); 
	}
    if(rank==0) 
		printf("Pi=%f\n", sum_final);

    if(MPI_SUCCESS != MPI_Finalize()){
         printf("Error in MPI_Finalise\n"); 
		 exit(-1); 
	}
    return 0;
}
