#include<stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node * create_linkedlist(struct node * head)
{
    int n,i;
    struct node * tmp;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    head=(struct node *)malloc(sizeof(struct node));
    printf("Enter node\n");
    scanf("%d",&head->data);
    tmp=head;
    for(i=1;i<n;i++)
    {
    tmp->next=(struct node *)malloc(sizeof(struct node)); 
    tmp=tmp->next;
    printf("Enter node\n");
    scanf("%d",&tmp->data);
    }
    tmp->next=NULL;
    return(head);
};

struct node * split(struct node * head)
{
    int pos, i;
    struct node * tmp, *head1;
    printf("Enter the position where you want to split the linked-list\n");
    scanf("%d",&pos);
    tmp=head;
    i=1;
    while(i<pos)
    {
    tmp=tmp->next;
    i++;
    }
    head1=tmp->next;
    tmp->next=NULL;
    printf("First part of linked list is\n");
    display(head);
    printf("Second part of linked list is\n");
    display(head1);
    return(head1);
}
struct node * concatenate(struct node * head)
{
    struct node * head1 ,* head2,* tmp;
    printf("Enter for first linked list\n");
    head1=create_linkedlist(head1);
    printf("Enter for second linked list\n");
    head2=create_linkedlist(head2);
    tmp=head1;
    while(tmp->next!=NULL)
    tmp=tmp->next;
    tmp->next=head2;
    printf("Concatenated linked list is :\n");
    display(head1);
    return(head1);
};

void display(struct node *head)
{
    struct node *tmp;
    tmp=head;
    while(tmp!=NULL)
    {
    printf("%d \t",tmp->data);
    tmp=tmp->next;
    }
}

void count (struct node*head)
{
    struct node *tmp;  
    tmp=head;
    int c=0;
    while(tmp!=NULL)
    {
     c++;
    tmp=tmp->next;
    }
    printf("The number of nodes are %d",c);
}

struct node * copy(struct node * head)
{
    struct node * tmp,* tmp1, *head1;
    head1=(struct node *)malloc(sizeof(struct
    node)); tmp=head;
    tmp1=head1;
    tmp1->data=tmp->data;
    while(tmp->next!=NULL)
    {
    tmp=tmp->next;
    tmp1->next=(struct node *)malloc(sizeof(struct node));
    tmp1=tmp1->next;
    tmp1->data=tmp->data;
    }
    tmp1->next=NULL;
    printf("First Linked list is:\n");
    display(head);
    printf("Copied Linked list is:\n");
    display(head1);
    return(head1) ;
};


struct node * reverse(struct node * head)
{
    struct node * p,* q,* r;
    p=NULL;
    q=head;
    r=q->next;
    while(q!=NULL)
    {
    r = q->next;
    q->next=p;
    p=q;
    q=r;
    }
    return(p);
};

int main()
{
    int ch;
    struct node * head;
    head=NULL;
        while(1)
        {
            printf("\n \t Enter your choice\n\n1.create linked list\n 2.split\n 3.concatenate \n 4.copy\n 5.reverse\n 6.display\n 7.count\n 8.exit\n");
            scanf("%d",&ch);
            switch(ch)
            {

            case 1:
                {
                     head=create_linkedlist(head);
                    break;
                }

                    case 2:
                    {
                    head=split(head);
                    break;
                    }
                    case 3:
                    {
                    head=concatenate(head);
                    }
                    case 4:
                    {
                    head=copy(head);
                    break;
                    }
                    case 5:
                    {
                    head=reverse(head);
                    break;
                    }

                    case 6:
                    {
                   display(head);
                    break;
                    }
                    case 8:
                        {
                            exit(0);
                        }

                    case 7:
                        {
                            count(head);
                        }
            }
         }
}

/*
1.create linked list
 2.split
 3.concatenate
 4.copy
 5.reverse
 6.display
 7.count
 8.exit
1
Enter number of nodes: 5
Enter nodes
1 2 3 4 5
Enter nodes
Enter nodes
Enter nodes
Enter nodes

         Enter your choice

1.create linked list
 2.split
 3.concatenate
 4.copy
 5.reverse
 6.display
 7.count
 8.exit
2
Enter the position where you want to split the linked-list
3
First part of linked list is
1       2       3       Second part of linked list is
4       5
         Enter your choice

1.create linked list
 2.split
 3.concatenate
 4.copy
 5.reverse
 6.display
 7.count
 8.exit
3
Enter for first linked list
Enter number of nodes: 3
Enter nodes
6
Enter nodes
7
Enter nodes
8
Enter for second linked list
Enter number of nodes: 1
Enter nodes
9
Concatenated linked list is :
6       7       8       9       First Linked list is:
6       7       8       9       Copied Linked list is:
6       7       8       9
         Enter your choice

1.create linked list
 2.split
 3.concatenate
 4.copy
 5.reverse
 6.display
 7.count
 8.exit
6
6       7       8       9
         Enter your choice

1.create linked list
 2.split
 3.concatenate
 4.copy
 5.reverse
 6.display
 7.count
 8.exit
7
The number of nodes are 4
         Enter your choice

1.create linked list
 2.split
 3.concatenate
 4.copy
 5.reverse
 6.display
 7.count
 8.exit
*/