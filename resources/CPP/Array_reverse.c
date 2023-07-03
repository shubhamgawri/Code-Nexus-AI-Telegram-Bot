#include <stdio.h>
void reverse(int a[],int n)
{
int i,t;
for(i=0;i<n/2;i++)
{
t=a[i];
a[i]=a[n-i-1];
a[n-i-1]=t;
}
printf("\nReversed array is :");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
}
int main()
{
int a[100],n,i;
printf("Enter the number of elements");
scanf("%d", &n);
printf("\nStart entering values");
for(i=0;i<n;i++)
scanf("%d", &a[i]);
///user defined ftn reverse
reverse(a,n);
return 0;
}