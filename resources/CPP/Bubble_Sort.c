//Bubble Sort Algo-CP8 , Shubham Gawri , 9371 // 
#include<stdio.h>
int main()
{
int a[100],temp,i,number,j;
printf("Enter value of n:");
scanf("%d",&number);
printf("\n");
for(i=0;i<number;i++)
{
    printf("Enter elements:");
    scanf("%d",&a[i]);
    printf("\n");
}// for i
 for(i=0;i<number-1;i++)
 {
  for(j=0;j<number-1-i;j++)
  {
      if(a[j]>a[j+1])
      {
       temp=a[j];
       a[j]=a[j+1];
       a[j+1]=temp;
      }//Closing if loop
  }//for j
 }//for i
printf("\n Sorted list is:\n");
for(i=0;i<number;i++)
{
    printf("%d\n",a[i]);
}// for i
return 0;
}// end main
