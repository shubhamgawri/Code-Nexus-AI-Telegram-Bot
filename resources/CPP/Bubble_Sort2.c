#include <stdio.h>
int main()
{
    int a[100],temp,number,i,j;
    printf("Enter the values of n: ");
    scanf("%d",&number);
    printf("\n");
    for(i=0;i<number;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&a[i]);
        printf("\n");
    }
    for (i=0;i<number;i++)
    {
        for (j=i+1;j<number;j++)
        {
            if(a[j]<a[i])
            {
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
            }
        }
    }
    printf("Array in ascending order is: \n");
    for(i=0;i<number;i++)
        {
            printf("%d\n",a[i]);
        }

    return 0;
}