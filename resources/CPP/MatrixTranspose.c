// Transpose of a Matrix , FEC ,Shubham Gawri ,9371 //
#include <stdio.h>
int main() {
  int a[10][10], transpose[10][10], row, column;
  printf("Enter rows and columns: ");
  scanf("%d %d", &row, &column);

  // asssigning elements to the matrix
  printf("\nEnter matrix elements:\n");
  for (int i = 0; i < row; ++i)
  for (int j = 0; j < column; ++j) {
    printf("Enter element a%d%d: ", i + 1, j + 1);
    scanf("%d", &a[i][j]);
  }

  // printing the matrix a[][]
  printf("\nEntered matrix: \n");
  for (int i = 0; i < row; ++i)
  for (int j = 0; j < column; ++j) {
    printf("%d  ", a[i][j]);
    if (j == column - 1)
    printf("\n");
  }

  // computing the transpose
  for (int i = 0; i < row; ++i)
  for (int j = 0; j < column; ++j) {
    transpose[j][i] = a[i][j];
  }

  // printing the transpose
  printf("\nTranspose of the matrix:\n");
  for (int i = 0; i < column; ++i)
  for (int j = 0; j < row; ++j) {
    printf("%d  ", transpose[i][j]);
    if (j == row - 1)
    printf("\n");
  }
  return 0;
}