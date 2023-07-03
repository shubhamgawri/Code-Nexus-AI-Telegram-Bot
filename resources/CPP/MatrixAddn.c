#include <stdio.h>
void main()
{
    int matrix1[5][5], matrix2[5][5], matrix3[5][5];
    int i, j, k, choice, row1, column1, row2, column2;

    printf("Enter number of rows and columns of matrix 1. \n");
   scanf("%d %d", &row1, &column1);
   printf("\n Order of matrix 1: %d x %d. \n", row1, column1);
   printf("Enter values for matrix 1. \n");
   for(i = 0; i < row1; i++)
  {
     for(j = 0; j < column1; j++)
     scanf("%d", &matrix1[i][j]);
}

printf("\n Matrix 1 is as follows: \n"); /*Display matrix 1 */
for(i = 0; i < row1; i++)
{
    for(j = 0; j < column1; j++)
    printf("%d\t", matrix1[i][j]);
   printf("\n");
}
printf("Enter number of rows and columns of matrix 2. \n");
scanf("%d %d", &row2, &column2);
printf("\n Order of matrix 2: %d X %d. \n", row2, column2);
printf("Enter values for matrix 2. \n");
for(i = 0; i < row2; i++)
{
     for(j = 0; j < column2; j++)
     scanf("%d", &matrix2[i][j]);
}

printf("\n Matrix 2 is as follows: \n"); /*Display matrix 2 */
for(i = 0; i < row2; i++)
{
      for(j = 0; j < column2; j++)
      printf("%d\t", matrix2[i][j]); 
       printf("\n");
}
printf("Matrix Addition \n ");
if(row1 != row2 || column1 != column2) /*Check rule */
      printf("Matrix Addition is not possible.");
else
{
     for(i = 0; i < row1; i++)
    {
         for(j = 0; j < column1; j++)
                matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
                /*Addition result in third matrix i.e. matrix 3 */
    }
     printf("Result of matrix addition is as follows: \n");
    for(i = 0; i < row1; i++)
    {
          for(j = 0; j < column1; j++)
                  printf("%d \t", matrix3[i][j]); /*Display resultant matrix */
                   printf("\n");
      }   
}//else
} //main
