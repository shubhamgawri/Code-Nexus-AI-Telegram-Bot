#include<stdio.h>
#include <stdlib.h>
 
int Top=-1;
int stack[10];
 
//push: add object to the top of the stack
void push(int n)
{
    printf("\nPush element: %d", n);
    if(Top>9)
        printf("Overflow");
    else
    {
        Top++;
        stack[Top] = n;
    }
}
//pop: remove the topmost object from the stack
void pop()
{
    printf("\nPop topmost element");
    if(Top<0)
        printf("\nUnderflow");
    else
    {
        printf("Popped element is %d", stack[Top]);
        Top--;
    }
}
//stack top / peek: returns the topmost element of the stack
void stackTop() {
    if (Top < 0)
        printf("\nStack is empty.");
    else
        printf("\nStack Top = %d", stack[Top]);
}
//print the stack elements
void DisplayStack()
{
    if(Top<0)
        printf("\nStack is empty");
    else
    {
        printf("\nThe stack is: ");
        for(int i=0; i<=Top;i++)
            printf("%d\t", stack[i]);
    }
}
 
int main()
{
    int opt = 0, x;
    while (1)
    {
        printf("\nEnter your option:\n1. Push\n2. Pop\n"
               "3. StackTop\n4. Display\n5. Exit\n");
        scanf("%d", &opt);
 
        switch (opt) {
            default:
                printf("Choose valid option!");
            case 1:
                printf("\nEnter the element to be pushed.");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                stackTop();
                break;
            case 4:
                DisplayStack();
                break;
            case 5:
                exit(0);
        }
    }
}