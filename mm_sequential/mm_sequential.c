#include<stdio.h>
#include<stdlib.h>
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
printf("Resultant matrix=\n");
for(i=0;i<row;i++)
{
for(j=0;j<column;j++)
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
for(j=0;j<column;j++)
{
printf("%d\t",resultant[i][j]);
}
printf("\n");
}
return 0;
}
