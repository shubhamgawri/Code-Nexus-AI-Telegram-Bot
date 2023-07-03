#include<stdio.h>
int main()
{
int i,j,k,key,p,arr[50],n;
printf("Enter the no. of elements: ");
    scanf("%d",&n);
    printf("\nEnter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
for(i=0;i<n-1;i++) {
key=arr[i];
for(j=i+1;j<n;j++) {
if(key>arr[j])
{
key=arr[j];
p=j; } }
arr[p]=arr[i];
arr[i]=key;
printf("For i=%d: ",i);
for(k=0;k<n;k++)
printf("%d\t",arr[k]);
printf("\n");
}
printf("\nThe sorted array is:\n");
for(i=0;i<n;i++)
printf("%d\t",arr[i]);
return 0; 
}

/* Output:
Enter the no. of elements: 5

Enter the elements: 67 4 77 3 2
For i=0: 2      4       77      3       67
For i=1: 2      3       77      4       67
For i=2: 2      3       4       77      67
For i=3: 2      3       4       67      77

The sorted array is:
2       3       4       67      77
*/