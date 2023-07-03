/* Question: Implement Remove function in Doubly Linked List ,Shubham Gawri ,9371*/
#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    struct node *prev;  
    struct node *next;  
    int data;  
};  
struct node *head;  
void insert();   
void remove_beginning();  
void remove_last();  
void remove_specified();  
void display();   
void main ()  
{  
int choice =0;  
    while(choice != 9)  
    {  
        printf("\n1.Insert in begining\n2.Delete from Beginning\n3.Delete from last\n4.Delete specific node\n5.Display\n6.Exit\n");  
        printf("\nEnter your choice:\n");  
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            insert();  
            break;  
            case 2: 
            remove_beginning();  
            break;  
            case 3:  
            remove_last();  
            break;  
            case 4:  
            remove_specified();  
            break;  
            case 5:  
            display();  
            break;  
            case 6:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice");  
        }  
    }  
}  
void insert()  
{  
   struct node *ptr;   
   int item;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
    printf("\nEnter item value:");  
    scanf("%d",&item);  
      
   if(head==NULL)  
   {  
       ptr->next = NULL;  
       ptr->prev=NULL;  
       ptr->data=item;  
       head=ptr;  
   }  
   else   
   {  
       ptr->data=item;  
       ptr->prev=NULL;  
       ptr->next = head;  
       head->prev=ptr;  
       head=ptr;  
   }  
   printf("\nNode inserted\n");  
}  
     
}  

void remove_beginning()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);  
        printf("\nnode deleted\n");  
    }  
    else  
    {  
        ptr = head;  
        head = head -> next;  
        head -> prev = NULL;  
        free(ptr);  
        printf("\nnode deleted\n");  
    }  
  
}  
void remove_last()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);   
        printf("\nnode deleted\n");  
    }  
    else   
    {  
        ptr = head;   
        if(ptr->next != NULL)  
        {  
            ptr = ptr -> next;   
        }  
        ptr -> prev -> next = NULL;   
        free(ptr);  
        printf("\nnode deleted\n");  
    }  
}  
void remove_specified()  
{  
    struct node *ptr, *temp;  
    int val;  
    printf("\n Enter the data after which the node is to be deleted : ");  
    scanf("%d", &val);  
    ptr = head;  
    while(ptr -> data != val)  
    ptr = ptr -> next;  
    if(ptr -> next == NULL)  
    {  
        printf("\nCan't delete\n");  
    }  
    else if(ptr -> next -> next == NULL)  
    {  
        ptr ->next = NULL;  
    }  
    else  
    {   
        temp = ptr -> next;  
        ptr -> next = temp -> next;  
        temp -> next -> prev = ptr;  
        free(temp);  
        printf("\nnode deleted\n");  
    }     
}  
void display()  
{  
    struct node *ptr;  
    printf("\n printing values:\n");  
    ptr = head;  
    while(ptr != NULL)  
    {  
        printf("%d\n",ptr->data);  
        ptr=ptr->next;  
    }  
}   

/*
Output:
1.Insert in begining
2.Delete from Beginning
3.Delete from last
4.Delete specific node
5.Display
6.Exit

Enter your choice:
1

Enter item value:10

Node inserted

1.Insert in begining
2.Delete from Beginning
3.Delete from last
4.Delete specific node
5.Display
6.Exit

Enter your choice:
1

Enter item value:20

Node inserted

1.Insert in begining
2.Delete from Beginning
3.Delete from last
4.Delete specific node
5.Display
6.Exit

Enter your choice:
1

Enter item value:30

Node inserted

1.Insert in begining
2.Delete from Beginning
3.Delete from last
4.Delete specific node
5.Display
6.Exit

Enter your choice:
2

node deleted

1.Insert in begining
2.Delete from Beginning
3.Delete from last
4.Delete specific node
5.Display
6.Exit

Enter your choice:
5

 printing values:
20
10

1.Insert in begining
2.Delete from Beginning
3.Delete from last
4.Delete specific node
5.Display
6.Exit

Enter your choice:
6
*/