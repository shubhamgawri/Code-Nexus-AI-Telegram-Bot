#include <stdio.h>
int main() {
    int i,j,k,rows;
    printf("Enter number of rows:");
    scanf("%d",&rows);
    printf("\n");
    /*To print upper triangle*/
    for(i=1;i<=rows;i++)
    {
        for(j=1;j<=(rows-i);j++)
        {
            printf(" ");
        }// for j
       
        for(k=1;k<=(2*i-1);k++)
        {
            printf("*");
        }
        printf("\n");
         }/* for I */
/*To print lower triangle*/
 for(i=rows-1;i>=1;i--)
 {
     for(j=1;j<=(rows-i);j++)
     {
         printf(" ");
     }
     for(k=1;k<=(2*i-1);k++)
     {
         printf("*");
     }
     printf("\n");
 }/*for i*/
        return 0;
    }