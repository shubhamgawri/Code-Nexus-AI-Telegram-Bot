#include<stdio.h>
int fact(int n);
int main()
{
    int n,r,ncr=0,npr=0,nfact,rfact,nmrfact;   
    printf("Enter two numbers:");
    scanf("%d%d",&n,&r);
    nfact = fact(n);
    nmrfact = fact(n-r);
    rfact = fact(r);
    npr = nfact/nmrfact;
    printf("\n The npr of %d and %d is %d",n,r,npr);
    ncr = nfact / (rfact*nmrfact);
    printf("\n The npr of %d and %d is %d \n",n,r,ncr);
    return 0;
}

int fact(int a)
{
    int i=1,fact=1;
    while(i<=a)
    {
     fact=fact*i;
     i++;    
    }
     return fact;
}