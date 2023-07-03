#include <stdio.h>
int main()
{
    int m,n;
    printf("enter 2 nos:");
    scanf("%d %d", &m, &n);
    while(n>0)
    {
        int r= m%n;
        m=n;
        n=r;
    }
    printf("GCD of given number is: %d\n",m);
    return 0;
}