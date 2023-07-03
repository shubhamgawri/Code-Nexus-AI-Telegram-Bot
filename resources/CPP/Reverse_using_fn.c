#include<stdio.h>
int reverse(int n)
{
    int temp,sum=0;
    if(n!=0)
    {
        temp=n%10;
        sum=sum*10+temp;
        reverse(n/10);
    }
    else
    {
        printf("%d",sum);
        return sum;
    }
}
int main()
{
int num,rev;
printf("Enter number\n");
scanf("%d",&num);
rev=reverse(num);
printf("Reverse of entered number is %d\n",rev);
 return 0;
}
