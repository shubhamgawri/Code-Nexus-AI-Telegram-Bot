/* Practical Exam : Program 1 - Merging two 1D arrays ,FEC , 9371, Shubham Gawri  */ 
#include<stdio.h>
int main()
{
    int n1,n2,n3,i,j;
    printf("Enter number of elements in first array: \n"); //No. of Elements of 1st array
    scanf("%d",&n1);
    int a[n1];
    printf("Enter elements of first array: \n"); // Initalising 1st array
    for(i=0;i<n1;i++)
    {
        scanf("%d",&a[i]);
    }// for i    
    printf("Enter number of elements in second array: \n"); //No. of Elements of 2nd array
    scanf("%d",&n2);
    int b[n2];
    printf("Enter elements of second array: \n");  // Initalising 2nd array
    for(i=0;i<n2;i++)
    {
        scanf("%d",&b[i]);
    }// for i 
    n3=n1+n2; // Total array size
    int c[n3];
    for(i=0;i<n1;i++)
    {
        c[i]=a[i];
    }
    for(i=0,j=n1;j<n3 && i <n2;i++,j++)
    {
        c[j]=b[i];
    }
    printf("\n Array Elements after merging: \n"); //Printing Result Array
    for(i=0;i<n3;i++)
    {
        printf("%d \t",c[i]);
    }
    printf("\n");
    return 0;
}
