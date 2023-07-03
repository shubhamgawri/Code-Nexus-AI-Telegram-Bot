#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int top=-1;
int stack[10];

void pop()
{
    if(top<0)
        printf("\nUnderflow");
    else
    {
        top--;
    }
}

void push(int n) 
{
    if(top>9)
        printf("Overflow");
    else
    {
        top++;
        stack[top] = n;
    }
}

void main()
{    
    int i=0;
    char exp[10];
    printf("Enter Expression: ");
    gets(exp);
	for (i=0; exp[i]!='\0'; i++)
   {
	if(exp[i]=='(')
		push(exp[i]);
	else if (exp[i]==')' )
	{	if(top!=-1)
		   pop();
		else
		 {  
			printf("invalid Expression");
			exit(0);
		}

	}	
   }
   if(top==-1)
	printf("Valid Expression");
   else
       printf("Invalid Expression");
}