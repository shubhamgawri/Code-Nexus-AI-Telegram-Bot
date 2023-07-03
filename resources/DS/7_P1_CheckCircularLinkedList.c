#include <stdio.h>
#include <stdlib.h>

struct Node 
{
  int data;          
  struct Node *next; 
};

typedef struct 
{
  struct Node *start;
} LL;

int isCircular(LL *l1) 
{
  struct Node *p, *q;
  p = l1->start;
  if (p->next == NULL)
  {
    return 1;
  }
  else
  {
    q = l1->start;
    while (q != NULL)
    {
      if (q->next == p)
      {
        return 1;
      }
      q = q->next;
    }
    return 0;
  }
}

void circ(LL *l, int x) 
{
  struct Node *p, *q;
  p = (struct Node *)malloc(sizeof(struct Node));
  p->data = x;
  p->next = NULL;
  if (l->start == NULL) 
  {
    l->start = p;
    p->next = l->start;
  }
  else
  {
    q = l->start;
    while (q->next != l->start) 
    {
      q = q->next;
    }
    q->next = p; 
    p->next = l->start;
  }
}

void notcirc(LL *l, int x) 
{
  struct Node *p, *q;
  p = (struct Node *)malloc(sizeof(struct Node));
  p->data = x;
  p->next = NULL;
  if (l->start == NULL)
  {
    l->start = p;
  }
  else
  {
    q = l->start;
    while (q->next != NULL) 
    {
      q = q->next;
    }
    q->next = p; 
  }
}

int main()
{
  LL l1, l2;
  l1.start = NULL;
  l2.start = NULL;

  int circ1, circ2, n, i, x;

  printf("\nElements for circular Linked List: ");
  printf("\nEnter number of elements in linked list: "); 
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    printf("Enter %d element: ", i + 1);
    scanf("%d", &x);
    circ(&l1, x);
  }

  printf("\nElements for non circular Linked List: ");
  printf("\nEnter number of elements in linked list: "); 
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    printf("Enter %d element: ", i + 1);
    scanf("%d", &x);
    notcirc(&l2, x);
  }

  circ1 = isCircular(&l1);
  circ2 = isCircular(&l2);

  if (circ1 == 1)
  {
    printf("\nThe first linked list is circular.");
  }
  else if (circ1 == 0)
  {
    printf("\nThe first linked list is not circular.");
  }
  if (circ2 == 1)
  {
    printf("\nThe second linked list is circular.");
  }
  else
  {
    printf("\nThe second linked list is not circular.");
  }
}

/*

Elements for circular Linked List:
Enter number of elements in linked list: 5
Enter 1 element: 22
Enter 2 element: 33
Enter 3 element: 55
Enter 4 element: 44
Enter 5 element: 11

Elements for non circular Linked List:
Enter number of elements in linked list: 4
Enter 1 element: 55555
Enter 2 element: 888
Enter 3 element: 99
Enter 4 element: 67

The first linked list is circular.

*/