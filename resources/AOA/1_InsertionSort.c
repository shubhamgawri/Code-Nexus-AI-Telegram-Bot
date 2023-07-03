#include<stdio.h>
#include<conio.h>
int main()
{
    int n,i,j,temp,a[50],swap=0;
    printf("Enter the no. of elements:");
    scanf("%d",&n);
    printf("\nEnter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
 
   for(i=0;i<n;i++)
   {
       temp=a[i];
       j=i-1;
       while((temp<a[j])&&(j>=0))
       {
           a[j+1]=a[j];
           swap++;
           j=j-1;
       }
       a[j+1]=temp;
       printf("\nSorting Elements %d: ",i+1);
           for(int k=0;k<n;k++)
           {
           printf("%d ",a[k]);
           }
   }
    printf("\nSorted elements are: ");
    for(i=0;i<n;i++)
    {
    printf("%d ",a[i]);
    }
    printf("\nTotal Swaps= %d",swap);
   return 0;
}
/* Output: 
Enter the no. of elements:5

Enter the elements: 56 3 77 2 1

Sorting Elements 1: 56 3 77 2 1
Sorting Elements 2: 3 56 77 2 1
Sorting Elements 3: 3 56 77 2 1
Sorting Elements 4: 2 3 56 77 1
Sorting Elements 5: 1 2 3 56 77
Sorted elements are: 1 2 3 56 77
Total Swaps= 8
*/