//Program to copy String , Shubham Gawri ,9371 ,FEC//
#include<stdio.h>
void xstrcpy(char s1[] ,char s2[]);
int main()
{
 char src[50], dest[50];
 printf("\n Enter source string:");
 gets(src);
 xstrcpy(dest,src);
 printf("\n After copy dest = %s \n",dest);
}
//Function definition
 void xstrcpy(char s1[] ,char s2[])
{
     int i=0;
     while(s2[i]!='\0')
     {
         s1[i]=s2[i];
         i++;
     }
     s1[i]='\0';
}
