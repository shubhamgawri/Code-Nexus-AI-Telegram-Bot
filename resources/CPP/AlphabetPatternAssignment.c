#include<stdio.h>
int main()
{
    int i,j,rows;
    printf("Enter number of rows:");
    scanf("%d",&rows);
    for(i=1;i<=rows;i++)
    {
        for(j=1;j<=rows-i;j++)
        {
        printf(" ");
        }
        for(j=i;j>=1;j--)
        {
            printf("%c",(char)(j+64));
        }
        for(j=2;j<=i;j++)
        {
            printf("%c",(char)(j+64));
        }
        printf("\n");
    }
    return 0;
}    
        