#include<stdio.h>
int stack[20];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char exp[20];
    int n1,n2,n3,num;
    printf("Enter the expression: ");
    scanf("%s",exp);
    for(int i=0;exp[i] !='\0';i++)
    {
        if(isdigit(exp[i]))
        {
            num = exp[i] - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(exp[i])
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push(n3);
        }
    }
    printf("\nThe result of expression %s  =  %d\n\n",exp,pop());
    return 0;
}