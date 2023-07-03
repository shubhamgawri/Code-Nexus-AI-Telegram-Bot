#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;

void beginsert ();
void lastinsert ();
void insertspecific();
void begin_delete();
void last_delete();
void delete_specific();
void display();
void search();
int main ()
{
    int choice =0;
    while(choice != 7)
    {
        printf("\n1.Insert in begining\n2.Insert at last\n3.insert in between\n4.Delete from Beginning\n5.Delete from last\n6.Delete at specific position\n7.Search for an element\n8.Display\n9.Exit\n");
        printf("\nEnter your choice:\n");
        scanf("\n%d",&choice);
        switch(choice)
        {
            case 1:
            beginsert();
            break;
            case 2:
            lastinsert();
            break;
            case 3:
            insertspecific();
            case 4:
            begin_delete();
            break;
            case 5:
            last_delete();
            break;
            case 6:
            delete_specific();
            break;
            case 7:
            search();
            break;
            case 8:
            display();
            break;
            case 9:
            exit(0);
            break;
            default:
            printf("Please enter valid choice");
        }
    }
}
void beginsert()
{
    struct node *ptr,*temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter the node data:");
        scanf("%d",&item);
        ptr -> data = item;
        if(head == NULL)
        {
            head = ptr;
            ptr -> next = head;
        }
        else
        {
            temp = head;
            while(temp->next != head)
                temp = temp->next;
            ptr->next = head;
            temp -> next = ptr;
            head = ptr;
        }
        printf("\nnode inserted\n");
    }

}
void lastinsert()
{
    struct node *ptr,*temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        printf("\nEnter Data:");
        scanf("%d",&item);
        ptr->data = item;
        if(head == NULL)
        {
            head = ptr;
            ptr -> next = head;
        }
        else
        {
            temp = head;
            while(temp -> next != head)
            {
                temp = temp -> next;
            }
            temp -> next = ptr;
            ptr -> next = head;
        }

        printf("\nnode inserted\n");
    }

}

void insertspecific()
{
    int i,loc,item;
    struct node *ptr, *temp;
    ptr = (struct node *) malloc (sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter element value");
        scanf("%d",&item);
        ptr->data = item;
        printf("\nEnter the location after which you want to insert ");
        scanf("\n%d",&loc);
        temp=head;
        for(i=0;i<loc;i++)
        {
            temp = temp->next;
            if(temp == NULL)
            {
                printf("\ncan't insert\n");
                return;
            }

        }
        ptr ->next = temp ->next;
        temp ->next = ptr;
        printf("\nNode inserted");
    }
}

void begin_delete()
{
    struct node *ptr;
    if(head == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if(head->next == head)
    {
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
    }

    else
    {   ptr = head;
        while(ptr -> next != head)
            ptr = ptr -> next;
        ptr->next = head->next;
        free(head);
        head = ptr->next;
        printf("\nnode deleted\n");

    }
}
void last_delete()
{
    struct node *ptr, *preptr;
    if(head==NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if (head ->next == head)
    {
        head = NULL;
        free(head);
        printf("\nnode deleted\n");

    }
    else
    {
        ptr = head;
        while(ptr ->next != head)
        {
            preptr=ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr -> next;
        free(ptr);
        printf("\nnode deleted\n");

    }
}

void delete_specific()
{
    struct node *ptr,*ptr1;
    int loc,i;
    printf("\n Enter the location of the node after which you want to perform deletion \n");
    scanf("%d",&loc);
    ptr=head;
    for(i=0;i<loc;i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;

        if(ptr == NULL)
        {
            printf("\nCan't delete");
            return;
        }
    }
    ptr1 ->next = ptr ->next;
    free(ptr);
    printf("\nDeleted node %d ",loc+1);
}

void search()
{
    struct node *ptr;
    int item,i=0,flag=1;
    ptr = head;
    if(ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to search:\n");
        scanf("%d",&item);
        if(head ->data == item)
        {
        printf("item found at location %d",i+1);
        flag=0;
        }
        else
        {
        while (ptr->next != head)
        {
            if(ptr->data == item)
            {
                printf("item found at location %d ",i+1);
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }
        }
        if(flag != 0)
        {
            printf("Item not found\n");
        }
    }

}

void display()
{
    struct node *ptr;
    ptr=head;
    if(head == NULL)
    {
        printf("\nnothing to print");
    }
    else
    {
        printf("\n printing values ... \n");

        while(ptr -> next != head)
        {

            printf("%d\n", ptr -> data);
            ptr = ptr -> next;
        }
        printf("%d\n", ptr -> data);
    }

}

/*

1.Insert in begining
2.Insert at last
3.insert in between
4.Delete from Beginning
5.Delete from last
6.Delete at specific position
7.Search for an element
8.Display
9.Exit

Enter your choice?
1

Enter the node data?8

PS C:\Users\Shubham\Documents\Programs\C\Data Structures> cd "c:\Users\Shubham\Documents\Programs\C\Data
Structures\" ; if ($?) { gcc 7_CircularLinkedList.c -o 7_CircularLinkedList } ; if ($?) { .\7_CircularLinkedList }

1.Insert in begining
2.Insert at last
3.insert in between
4.Delete from Beginning
5.Delete from last
6.Delete at specific position
7.Search for an element
8.Display
9.Exit

Enter your choice:
1

Enter the node data:10

node inserted

1.Insert in begining
2.Insert at last
3.insert in between
4.Delete from Beginning
5.Delete from last
6.Delete at specific position
7.Search for an element
8.Display
9.Exit

Enter your choice:
2

Enter Data:20

node inserted

1.Insert in begining
2.Insert at last
3.insert in between
4.Delete from Beginning
5.Delete from last
6.Delete at specific position
7.Search for an element
8.Display
9.Exit

Enter your choice:
2

Enter Data:70

node inserted

1.Insert in begining
2.Insert at last
3.insert in between
4.Delete from Beginning
5.Delete from last
6.Delete at specific position
7.Search for an element
8.Display
9.Exit

Enter your choice:
4

node deleted

1.Insert in begining
2.Insert at last
3.insert in between
4.Delete from Beginning
5.Delete from last
6.Delete at specific position
7.Search for an element
8.Display
9.Exit

Enter your choice:
8

 printing values ...
20
70

1.Insert in begining
2.Insert at last
3.insert in between
4.Delete from Beginning
5.Delete from last
6.Delete at specific position
7.Search for an element
8.Display
9.Exit

Enter your choice:
7

Enter item which you want to search:
20
item found at location 1

*/