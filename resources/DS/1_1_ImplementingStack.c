#include<stdio.h>
#include<stdlib.h>
int top=-1;
int stack[10];
void push(int);
void pop();
void stacktop();
void display();

int IsEmpty()
{
    if(top==-1)
     return 1;
    else
     return 0;
}

int IsFull()
{
    if(top==9)
     return 1;
    else
     return 0;
}

int main()
{

    int option=0,x;
while(1)
 {
      printf("\nChoose any option: \n 1. Push \n 2.Pop \n 3.StackTop \n 4.Display \n 5. Exit \n");
      scanf("%d",&option);
         switch(option)
    {
     default:
      printf("Choose valid option!");

         case 1:
         printf("\nEnter the element to be pushed: ");
         scanf("%d",&x);
         push(x);
         break;

         case 2:
         pop();
         break;

         case 3:
         stacktop();
         break;

         case 4:
         display();
         break;

         case 5:
         exit(0);

    }
 }
      return 0;
}

void push(int x)
{
   printf("\nElement pushed is %d",x);
   if(IsFull())
    printf("\n Overflow");
   else
   {
       top++;
       stack[top]= x;
   }
}

void pop()
{
   printf("\n The topmost element is popped\n");
   if(IsEmpty())
    printf("\n Underflow");
   else
   {    
        printf("Popped element is %d", stack[top]);
        top--;
   }
}

void stacktop()
{
    if(top<0)
        printf("\nUnderflow");
    else
        printf("\n Top of stack is %d",stack[top]);

}

void display()
{
    if(top<0)
        printf("\nThe Stack is empty");
   else
    {  printf("\nThe stack is ");
       for(int i=top;i>=0;i--)
       printf("%d ",stack[i]);
    }
}

/*Output: Choose any option:
 1. Push
 2.Pop
 3.StackTop
 4.Display
 5. Exit
1

 enter the element to be pushed: 7

Element pushed is 7
Choose any option:
 1. Push
 2.Pop
 3.StackTop
 4.Display
 5. Exit
1

 enter the element to be pushed: 8

Element pushed is 8
Choose any option:
 1. Push
 2.Pop
 3.StackTop
 4.Display
 5. Exit
2

 The topmost element is poppedPopped element is 8
Choose any option:
 1. Push
 2.Pop
 3.StackTop
 4.Display
 5. Exit
4

The stack is 7
Choose any option:
 1. Push
 2.Pop
 3.StackTop
 4.Display
 5. Exit
5
*/