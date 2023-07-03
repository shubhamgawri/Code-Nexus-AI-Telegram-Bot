#include<stdio.h>
#include<stdlib.h>
#define MAX 4

int q[MAX];
int f=-1,r=-1;

int isFull()
{
    if(r==(MAX-1))
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
    if(f==-1 & r==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void insert()
{
    int add_item;
    if (r == MAX - 1)
    printf("Overflow \n");
    else
    {
        if (f == - 1)
        f = 0;
        printf("Insert the element in queue : ");
        scanf("%d", &add_item);
        r = r + 1;
        q[r] = add_item;
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
        f++;
    }
    return (x);
}

void display()
{
    int i;
    if (f == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = f; i <= r; i++)
            printf("%d ", q[i]);
        printf("\n");
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
                insert();
                break;
            }
            case 2:
            {
                s = rem();
                printf("Removed element = %d\n",s);
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