#include<time.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>

#define size 4        

int firstMatrix[size][size],secondMatrix[size][size],thirdMatrix[size][size];


void fill_matrix(int m[size][size])
{
   static int n=1;
   int i,j;
   for(i=0;i<size;i++)
   {
     for(j=0;j<size;j++)
     {
       m[i][j]=n++;
       }
       }
}
void printMatrix(int m[size][size])
{
printf("Enter the values for first matrix");
int i,j=0;
for(i=0;i<size;i++)
{
printf("\n\t| ");
for(j=0;j<size;j++)
{
printf("%2d ",m[i][j]);
}
printf("|");
}
}
void printMatrix2(int m[size][size])
{
printf("Enter the values for second matrix");
int i,j=0;
for(i=0;i<size;i++)
{
printf("\n\t| ");
for(j=0;j<size;j++)
{
printf("%2d ",m[i][j]);
}
printf("|");
}
}
void printMatrixoutput(int m[size][size])
{
printf("Enter the values for output matrix");
int i,j=0;
for(i=0;i<size;i++)
{
printf("\n\t| ");
for(j=0;j<size;j++)
{
printf("%2d ",m[i][j]);
}
printf("|");
}
}

int main(int argc, char **argv)
{
  int tasks,id,numworkers,source,dest,i,j,k;
  int tag=666;

  struct timeval start, stop;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &id);
  MPI_Comm_size(MPI_COMM_WORLD, &tasks);

  if(size%tasks!=0)
  {
    if (id==0) printf("matrix size not divisible by number of processes\n");
    MPI_Finalize();
    exit(-1);
    }
    
  source= id * size/tasks;
  dest=(id+1) * size/tasks;
  


  if (id == 0) {
  fill_matrix(firstMatrix);
  fill_matrix(secondMatrix);
  }
  
  MPI_Bcast (secondMatrix, size*size, MPI_INT, 0, MPI_COMM_WORLD);
  MPI_Scatter(firstMatrix, size*size/tasks,MPI_INT, firstMatrix[source], size*size/tasks, MPI_INT, 0, MPI_COMM_WORLD);
  
    for (i=source; i<dest; i++) {
      for (j=0; j<size; j++) {
        thirdMatrix[i][j]=0;
        for(k=0;k<size;k++)
        {
        thirdMatrix[i][j] +=firstMatrix[i][k]+secondMatrix[k][j];
              }
              }
    }
  MPI_Gather (thirdMatrix[source],size*size/tasks,MPI_INT, thirdMatrix,size*size/tasks, MPI_INT, 0, MPI_COMM_WORLD);
  
  if(id ==0)
  {
  printf("\n\n");
  printMatrix(firstMatrix);
  printf("\n\n\t         \n");
  printMatrix2(secondMatrix);
  printf("\n\n\t         \n");
  printMatrixoutput(thirdMatrix);
  printf("\n\n");
  }
  
  MPI_Finalize();
  return 0;
  }
