#include<stdio.h>
int main()
{
 int a[100],temp,n,m,i,j;
 char ch;
 printf("Enter the number of elements:");
 scanf("%d",&n);
 printf("\nStart entering values:\n");
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 printf("Enter rotation type- A for Anticlockwise, C for clockwise:");
 scanf(" %c",&ch);
 switch(ch)
 {
     case 'A':
     printf("Enter no. of positions to rotate:");
     scanf("%d",&m);
     for(j=0;j<m;j++)
     {   
         temp=a[0];
         for(i=0;i<(n-1);i++)
         {
          a[i]=a[i+1];
         }
         a[n-1]=temp;
     }
     break;
     case 'C':
     printf("Enter no. of positions to rotate:");
     scanf("%d",&m);
     for(j=0;j<m;j++)
     {   
         temp=a[n-1];
         for(i=n-1;i>0;i--)
         {
          a[i]=a[i-1];
         }
         a[0]=temp;
     }
     break;
     default:
     printf("Wrong Input\n");
     break;    
 }
 if(ch == 'A' || ch== 'C')
 {
  printf("Rotated Array is:\n");
  for(i=0;i<n;i++)
  printf("%d\t",a[i]);
 }
return 0;
}