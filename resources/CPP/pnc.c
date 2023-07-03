#include<stdio.h>
int fact(int n);
int main()
{
    int n,r,ncr,npr;   
    printf("Enter two numbers:");
    scanf("%d%d",&n,&r);
    npr = fact(n)/fact(n-r);
    printf("\n The npr of %d and %d is %d",n,r,npr);
    ncr = fact(n)/(fact(r)*fact(n-r));
    printf("\n The npr of %d and %d is %d \n",n,r,ncr);
    return 0;
}

int fact(int a)
{
    if(a==0 || a==1)
     return(1);
    else
     return (a*fact(a-1));
}