#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char stack[10];
int top = -1;

void push (char ch)
{
    if (top != 9)
    stack[++top] =ch;
    
}

char pop()
{
    if (top!= -1)
    return (stack[top--]);
    
}

char stackTop()
{
    if (top!=1)
        return (stack[top]);
}


int precedence(char ch)
{
    if (ch =='^')
        return (6);
    else if (ch =='*')
        return(5);
    else if (ch =='/')
        return(4);
    else if (ch =='%')
        return(3);
    else if (ch =='+')
        return(2);
    else if (ch =='-')
        return(1);
    else 
    return(0);
  
}
void infixtopostfix(char infix[10], char postfix[10])
{
    int k = 0;
    char ch;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')           //opening bracket
            push (infix[i]);
        else if (infix[i]== ')')       //closing bracket
        {
            while ((ch = pop()) != '(' & top != -1)
                postfix[k++]=ch;
        }
        else if (isalnum(infix[i]))    // operand
            postfix[k++] = infix[i];
        else                           //operator
        {
            if(precedence(stackTop()) >= precedence(infix[i]) & top!=-1)
                postfix[k++] = pop();
            push(infix[i]);
        }
    }
    while(top!= -1)
    {
        postfix[k++] =pop();
    }
    postfix[k] ='\0';
    
    printf("Postfix Expresion :  ");
    puts(postfix);
}


int main()
{
    char infix[10], postfix[10];
    printf("Enter Infix expression:");
    gets(infix);
    infixtopostfix(infix,postfix);
    return 0;
}