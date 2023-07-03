#include<stdio.h>

int main()
{
    int a[50],i,f,temp,n;
    
    printf("Enter number of elements to be sorted: ");
    scanf("%d",&n);
    printf("Enter the  elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    for(int pass=0;pass<n-1;pass++)
    {
        f=0;  
        for(i=0;i<n-pass-1;i++)
        {
            if(a[i]>a[i+1])
            {
               temp=a[i];
               a[i]=a[i+1];
               a[i+1]=temp;
               f=1;
            }
        }
        printf("\nAfter %d pass: ",pass+1);
        for(i=0;i<n;i++)
            printf("%d ",a[i]);
        if(f==0)
           break;
    }
    
    printf("\nThe sorted array is:\n");
    for(i=0;i<n ;i++)
    {
        printf("%d\t",a[i]);
    }

    return 0;
}
/* Output:
Enter number of elements to be sorted: 5
Enter the  elements:45 3 2 55 1

After 1 pass: 3 2 45 1 55         
After 2 pass: 2 3 1 45 55         
After 3 pass: 2 1 3 45 55         
After 4 pass: 1 2 3 45 55         
The sorted array is:
1       2       3       45      55
*/