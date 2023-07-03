#include<stdio.h>
#include<stdlib.h>
int top1=-1;
int top2=20;
int stack[20];
void push1(int);
void pop1();
void stacktop1();
void push2(int);
void pop2();
void stacktop2();
void display();

int IsEmpty1()
{
    if(top1==-1)
     return 1;
    else
     return 0;
}

int IsFull()
{
    if(top2-top1==1)
     return 1;
    else
     return 0;
}
int IsEmpty2()
{
    if(top2==-1)
     return 1;
    else
     return 0;
}

int main()
{

    int option=0,x,y;
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
         printf("Enter the stack no. to perform action on (1 or 2):\n");
         scanf("%d",&y);
         if(y==1)
         push1(x);
         else if(y==2)
         push2(x);
         else
         printf("Wrong Stack no.");
         break;

         case 2:
         printf("Enter the stack no. to perform action on (1 or 2):\n");
         scanf("%d",&y);
         if(y==1)
         pop1(x);
         else if(y==2)
         pop2(x);
         else
         printf("Wrong Stack no.");
         break;

         case 3:
         printf("Enter the stack no. to perform action on (1 or 2):\n");
         scanf("%d",&y);
         if(y==1)
         stacktop1(x);
         else if(y==2)
         stacktop2(x);
         else
         printf("Wrong Stack no.");
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

void push1(int x)
{
   printf("\n Element pushed is %d",x);
   if(IsFull())
    printf("\n Overflow");
   else
   {
       top1++;
       stack[top1]= x;
   }
}

void pop1()
{
   printf("\n The topmost element is popped");
   if(IsEmpty1())
    printf("\n Underflow");
   else
   {    
        printf("Popped element is %d", stack[top1]);
        top1--;
   }
}

void display()
{
    if(top1==-1)
        printf("\nStack 1 is empty");
   else
    {  printf("\n The stack 1 is ");
       for(int i=top1;i>=0;i--)
       printf("%d ",stack[i]);
    }
    if(top2==20)
        printf("\nStack 2 is empty");
   else
    {  printf("\n The stack 2 is ");
       for(int i=top2;i<=19;i++)
       printf("%d ",stack[i]);
    }
}
void push2(int x)
{
   printf("\n Element pushed is %d",x);
   if(IsFull())
    printf("\nOverflow");
   else
   {
       top2--;
       stack[top2]= x;
   }
}

void pop2()
{
   if(IsEmpty2())
    printf("\nUnderflow");
   else
   {    
        printf("Popped element is %d" , stack[top2]);
        top2++;
   }
}

void stacktop2()
{
    if(top2>19)
        printf("\nUnderflow");
    else
        printf("\n Top of stack 2 is %d",stack[top2]);

}

void stacktop1()
{
    if(top1<0)
        printf("\n Underflow");
    else
        printf("\n Top of stack 1 is %d",stack[top1]);

}
/*Choose any option:
 1. Push
 2.Pop
 3.StackTop
 4.Display
 5. Exit
1

Enter the element to be pushed: 32
Enter the stack no. to perform action on (1 or 2):
1

 Element pushed is 32
Choose any option:
 1. Push
 2.Pop
 3.StackTop
 4.Display
 5. Exit
1

Enter the element to be pushed: 33
Enter the stack no. to perform action on (1 or 2):
2

 Element pushed is 33
Choose any option:
 1. Push
 2.Pop
 3.StackTop
 4.Display
 5. Exit
1

Enter the element to be pushed: 4
Enter the stack no. to perform action on (1 or 2):
2

 Element pushed is 4
Choose any option:
 1. Push
 2.Pop
 3.StackTop
 4.Display
 5. Exit
1

Enter the element to be pushed: 55
Enter the stack no. to perform action on (1 or 2):
1

 Element pushed is 55
Choose any option:
 1. Push
 2.Pop
 3.StackTop
 4.Display
 5. Exit
4

 The stack 1 is 55 32
 The stack 2 is 4 33
Choose any option:
 1. Push
 2.Pop
 3.StackTop
 4.Display
 5. Exit
 5
 */