#include<stdio.h>
#include<string.h>
int main() 
{
    char s[50]="madam";
    int i,flag=0;
    int len =strlen(s);
    for(i=0;i<len/2;i++)
    {
        if(s[i]!=s[len-i-1])
        {
            flag=1;
            break;
        }
    }
if(flag==0) printf("\n %s is Palindrome",s);
else
printf("\n %s is not a palindrome",s);
return 0;
}
