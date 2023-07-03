/* Practical Exam : Program 2 - Merging two 1D arrays and sorting them ,FEC , 9371, Shubham Gawri  */ 
#include<stdio.h>
int main()
{
    int n1,n2,n3,i,j,temp;
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
for(i=0;i<n3-1;i++)
  {
     for(j=0;j<n3-1-i;j++) //Bubble Sort Algorithm
   {
      if(c[j]>c[j+1])
      {
       temp=c[j];
       c[j]=c[j+1];
       c[j+1]=temp;
      }
   }  
  } 
    printf("\n Array Elements after merging: \n"); //Printing Result Array
    for(i=0;i<n3;i++)
    {
        printf("%d \t",c[i]);
    }
    printf("\n");
    return 0;
}

