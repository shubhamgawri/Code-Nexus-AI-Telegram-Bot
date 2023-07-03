#include<stdio.h>
void swap(int a,int b);
int main()
{
    int n1,n2;
    printf("Enter the first number:");
    scanf("%d",&n1);
    printf("Enter the second number:");
    scanf("%d",&n2);
    printf("Inside function main before function call");
    printf("\n First number=%d \n Second number=%d \n",n1,n2);
    swap(n1,n2);
    printf("Inside function main after function call");
    printf("\n First number=%d \n Second number=%d \n",n1,n2);
    return 0;
}

void swap(int p,int q)
{
    int temp;
    temp=p;
    p=q;
    q=temp;   
    printf("Inside function call");
    printf("\n First number=%d \n Second number=%d \n",p,q);
}