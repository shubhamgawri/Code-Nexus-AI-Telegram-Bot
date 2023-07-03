//Function to find string length, Shubham Gawri ,FEC ,9371//
#include<stdio.h>
int strlength(char str[]); //prototype
int main()
{
 char str[100];
 int i;
 printf("\n Enter String:");
 scanf("%s",str);
 i=strlength(str);
 printf("Length of string is=%d \n",i);
 return 0;
}
//Function delaration
int strlength(char str[])
{
    int i=0;
    while(str[i]!='\0')
    i++;
    return i;
}