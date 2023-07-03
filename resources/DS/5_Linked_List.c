#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node* link;
};
struct node* start = NULL;

void AddFront()
{
    int data;
    struct node* temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter element to be inserted: ");
    scanf("%d", &data);
    temp->info = data;
    temp->link = start;
    start = temp;
}

void display()
{
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else {
        temp = start;
        while (temp != NULL) {
            printf(" %d ",temp->info);
            temp = temp->link;
        }
    }
}

void AddEnd()
{
    int data;
    struct node *temp, *head;
    temp = malloc(sizeof(struct node));
      printf("\nEnter element to be inserted: ");
    scanf("%d", &data);
      temp->link = 0;
    temp->info = data;
    head = start;
    while (head->link != NULL) {
        head = head->link;
    }
    head->link = temp;
}

void InsertAtPosition()
{
    struct node *temp, *newnode;
    int pos, data, i = 1;
    newnode = malloc(sizeof(struct node));
    printf("\nEnter position and data :");
    scanf("%d %d", &pos, &data);
    temp = start;
    newnode->info = data;
    newnode->link = 0;
    while (i < pos - 1)
    {
        temp = temp->link;
        i++;
    }
    newnode->link = temp->link;
    temp->link = newnode;
}

void DeleteFirst()
{
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else {
        temp = start;
        start = start->link;
        free(temp);
    }
}

void DeleteEnd()
{
    struct node *temp, *prevnode;
    if (start == NULL)
        printf("\nList is Empty\n");
    else {
        temp = start;
        while (temp->link != 0) {
            prevnode = temp;
            temp = temp->link;
        }
        free(temp);
        prevnode->link = 0;
    }
}

void DeletePosition()
{
    struct node *temp, *position;
    int i = 1, pos;
    if (start == NULL)
        printf("\nList is empty\n");
    else
    {
        printf("\nEnter the index : ");
        scanf("%d", &pos);
        temp = start;
        while (i < pos - 1)
        {
            temp = temp->link;
            i++;
        }
        position = temp->link;
        temp->link = position->link;
        free(position);
    }
}

void main()
{
    int ch;
    while(1)
    {
        printf("\nEnter your choice: \n 1.Insert in the beginning\n 2.Insert at the end\n 3.Insert at a specific position\n 4.Delete beginning\n 5.Delete end node\n 6.Delete a specific position\n 7.Display\n 8.Exit\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                AddFront();
                break;
            case 2:
                AddEnd();
                break;
            case 3:
                InsertAtPosition();
                break;
            case 4:
                DeleteFirst();
                break;
            case 5:
                DeleteEnd();
                break;
            case 6:
                DeletePosition();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
        }
    }
}
/*Enter your choice:
 1.Insert in the beginning
 2.Insert at the end
 3.Insert at a specific position
 4.Delete beginning
 5.Delete end node
 6.Delete a specific position
 7.Display
 8.Exit
1

Enter element to be inserted: 23

Enter your choice:
 1.Insert in the beginning
 2.Insert at the end
 3.Insert at a specific position
 4.Delete beginning
 5.Delete end node
 6.Delete a specific position
 7.Display
 8.Exit
1

Enter element to be inserted: 55

Enter your choice:
 1.Insert in the beginning
 2.Insert at the end
 3.Insert at a specific position
 4.Delete beginning
 5.Delete end node
 6.Delete a specific position
 7.Display
 8.Exit
2

Enter element to be inserted: 645

Enter your choice:
 1.Insert in the beginning
 2.Insert at the end
 3.Insert at a specific position
 4.Delete beginning
 5.Delete end node
 6.Delete a specific position
 7.Display
 8.Exit
3

Enter position and data :2
33

Enter your choice:
 1.Insert in the beginning
 2.Insert at the end
 3.Insert at a specific position
 4.Delete beginning
 5.Delete end node
 6.Delete a specific position
 7.Display
 8.Exit
7
 55  33  23  645
Enter your choice:
 1.Insert in the beginning
 2.Insert at the end
 3.Insert at a specific position
 4.Delete beginning
 5.Delete end node
 6.Delete a specific position
 7.Display
 8.Exit
4

Enter your choice:
 1.Insert in the beginning
 2.Insert at the end
 3.Insert at a specific position
 4.Delete beginning
 5.Delete end node
 6.Delete a specific position
 7.Display
 8.Exit
7
 33  23  645
Enter your choice:
 1.Insert in the beginning
 2.Insert at the end
 3.Insert at a specific position
 4.Delete beginning
 5.Delete end node
 6.Delete a specific position
 7.Display
 8.Exit
8
*/