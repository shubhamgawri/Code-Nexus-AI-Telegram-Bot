//Program to compare two strings, FEC ,9371 ,Shubham Gawri//
#include<stdio.h>
int main()
{
    char s1[40],s2[40];
    int i=0;
    printf("Enter string one:");
    scanf("%s",s1);
      printf("Enter string two:");
    scanf("%s",s2);
    while(s1[i]==s2[i])
    {
        if(s1[i] == '\0')
        break;
        i++;
    }
if(s1[i]<s2[i])
 printf("\n S2 > S1 \n");
else if(s1[i]>s2[i])
  printf("\n S1 > S2 \n");
else
printf("\n S1 = S2 \n");
return 0;
}