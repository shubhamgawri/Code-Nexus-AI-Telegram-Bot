#include<stdio.h>
#include<stdlib.h>
#define MAX 4

int q[MAX];
int f,r;

int isFull()
{
    if(f == (r+1)%MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if(f==-1 && r==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void insert(int ele)
{
    if (isFull())
    {
        printf("Overflow\n");
        return;
    }
    else if(isEmpty())
    {
        f = r = 0;
        q[r]=ele;
    }
    else
    {
        r = (r+1)%MAX;
        q[r] = ele;
    }
}

int rem()
{
    int x;
    if(isEmpty())
    {
        printf("Underflow\n");
        return (-1);
    }
    else if(r==f) 
    {
        x=q[f];
        f=r=-1;
    }
    else
    {
        x=q[f];
        f = (f+1)%MAX;
    }
    return (x);
}

void display()
{
    int i;
    if (isEmpty())
        printf("Circular Queue is empty \n");
    else
    {
        for (i=f;i!=r;i=((i+1)%MAX))
        {
            printf("%d\t",q[i]);
        }
        printf("%d\n",q[i]);
    }
}

int main()
{
    int ch,x;
    int s;
    f=-1;r=-1;
    while(1)
    {
        printf("Enter your choice: \n1.Insert \n2.Remove \n3.Display \n4.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("Enter element = ");
                scanf("%d",&x);
                insert(x);
                break;
            }
            case 2:
            {
                printf("Removed element = %d\n",rem());
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                exit(0);
            }
            default:
            {
                printf("Wrong choice entered\n");
            }
        }
    }
    return 0;
   
}
/*
Enter your choice:
1.Insert
2.Remove
3.Display
4.Exit
1
Enter element = 45
Enter your choice:
1.Insert
2.Remove
3.Display
4.Exit
1
Enter element = 55
Enter your choice:
1.Insert
2.Remove
3.Display
4.Exit
2
Removed element = 45
Enter your choice:
1.Insert
2.Remove
3.Display
4.Exit
3
55
Enter your choice:
1.Insert
2.Remove
3.Display
4.Exit
4
*/