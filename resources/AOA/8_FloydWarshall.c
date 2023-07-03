#include <stdio.h>

int min(int a,int b)
{
    return a > b ? b : a;
}
int main()
{
    int n;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
   
    int A[n][n],B[n][n];
   
    printf("\nEnter adjacency matrix of graph: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                A[i][j] = min(A[i][j],A[i][k]+A[k][j]);
            }
        }
        printf("\nArray after each iteration: \n");
        for(int l=0;l<n;l++)
        {
            for(int m=0;m<n;m++)
            {
                printf("%d ",A[l][m]);
            }
            printf("\n");
        }
    }
    return 0;
}

/*
Enter number of vertices: 4

Enter adjacency matrix of graph:
0
3
999
5
2
999
4
999
1
999
999
999
3

Array after each iteration:
0 3 999 5
2 0 999 4
999 1 0 999
999 999 3 0

Array after each iteration:
0 3 999 5
2 0 999 4
3 1 0 5
999 999 3 0

Array after each iteration:
0 3 999 5
2 0 999 4
3 1 0 5
6 4 3 0

Array after each iteration:
0 3 8 5
2 0 7 4
3 1 0 5
6 4 3 0
*/