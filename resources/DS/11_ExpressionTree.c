#include<stdio.h>
#include<string.h>

typedef struct node
{
  char data;
  struct node *left;
  struct node *right;
} node;

node *stack[10];
int top = -1;

void push (node * tmp)
{
  if (top != 9)
    stack[++top] = tmp;
}

node * pop ()
{
  if (top != -1)
    return (stack[top--]);
}

void display (struct node *root)
{
  if (root != NULL)
    {
      display (root->left);
      printf ("%c ", root->data);
      display (root->right);
    }
}

void evaluate (char postfix[10])
{
  int i;
  struct node *tmp;
  for (i = 0; postfix[i] != '\0'; i++)
    {
      if (isalnum (postfix[i]))
	{
	  tmp = (struct node *) malloc (sizeof (struct node));
	  tmp->data = postfix[i];
	  tmp->left = tmp->right = NULL;
	  push (tmp);
	}
      else
	{
	  tmp = (struct node *) malloc (sizeof (struct node));
	  tmp->data = postfix[i];
	  tmp->right = pop ();
	  tmp->left = pop ();
	  push (tmp);
    }}
  if (top != -1)
    tmp = pop ();
  display (tmp);
}


void main ()
{
  int i;
  char postfix[10];
  printf ("Enter a postfix expression: ");
  gets (postfix);
  evaluate (postfix);
}

/**Output
Enter a postfix expression: abc--
a - b - c 
**/
