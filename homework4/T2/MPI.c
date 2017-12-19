#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int fun(int n){//判断n是否是素数
    int i;
    for(i=2;i<n;i++)
        if(n%i==0) return 0;
    return 1; 
} 

int main (int argc, char **argv)
{
   int done = 0, n, myid, numprocs, i;
   int x;
   double startwtime = 0.0, endwtime;
   int  namelen;
   char processor_name[MPI_MAX_PROCESSOR_NAME];
   MPI_Init (&argc, &argv); //并行开始
	 MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
   MPI_Comm_rank(MPI_COMM_WORLD,&myid);
   MPI_Get_processor_name(processor_name,&namelen);
   fprintf(stderr,"Process %d on %s\n",myid, processor_name);

    n = 0;
    while (!done)
    {
        if (myid == 0)
        {
/*
            printf("Enter the number of intervals: (0 quits) ");
            scanf("%d",&n);
*/
            if (n==0) n=100; else n=0;
            startwtime = MPI_Wtime();

            
        }
        MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
        if (n == 0)
            done = 1;
        else
        {
          freopen("output.txt", "w", stdout); 
          int m=0;
          for(x=2;x<=100000;x++)      //循环判断
           {    
            if(fun(x))
            {
             printf("%d ",x);;
             m++;
            }
           }
           fclose(stdout);
           MPI_Reduce(&m, &x, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

            if (myid == 0)
            {
                endwtime = MPI_Wtime();
                fprintf(stderr,"mpi : the number of prime between 2-100000 is : %d   running time is %f \n", m, endwtime-startwtime);
            }
        }
    }
                

    MPI_Finalize();
    return 0;
}



