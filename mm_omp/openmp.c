#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>
int main()
{
int firstMatrix[10][10],secondMatrix[10][10],resultant[10][10],row,column,i,j,k;
system("cls");
printf("enter the number of row=");
scanf("%d",&row);
printf("enter the number of column=");
scanf("%d",&column);
printf("enter the first matrix element=\n");
for(i=0;i<row;i++)
{
for(j=0;j<column;j++)
{
scanf("%d",&firstMatrix[i][j]);
}
}
printf("enter the second matrix element=\n");
for(i=0;i<row;i++)
{
for(j=0;j<column;j++)
{
scanf("%d",&secondMatrix[i][j]);
}
}
 struct timeval t0, t1;
gettimeofday(&t0, 0);
printf("Resultant matrix=\n");
for(i=0;i<row;i++)
{
for(j=0;j<column;j++
{
resultant[i][j]=0;
for(k=0;k<column;k++)
{
resultant[i][j]+=firstMatrix[i][k]*secondMatrix[k][j];
}
}
}
for(i=0;i<row;i++)
{
for(j=0;j<column;j++)    {
printf("%d\t",resultant[i][j]);
}
printf("\n");
}
  gettimeofday(&t1, 0);
double elapsed = (t1.tv_sec-t0.tv_sec) * 1.0f + (t1.tv_usec - t0.tv_usec) / 1000000.0f;
printf("\ntime required to run %lf",elapsed);
return 0;
}
