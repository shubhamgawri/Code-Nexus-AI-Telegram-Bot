#include<stdio.h>

int q[5];
int f = -1, r = -1;

int isEmpty ()
{
  if (f == -1 && r == -1)
    return 1;
  else
    return 0;
}

void insert (int e)
{
  int add;
  if (r == 4)
    printf ("Overflow\n");
  else
    {
      if (f == -1)
	f = 0;
      r++;
      q[r] = e;
    }
}

int rem ()
{
  int x;
  if (isEmpty ())
    {
      printf ("Underflow\n");
      return -1;
    }
  else if (r == f)
    {
      x = q[f];
      f = r = -1;
    }
  else
    {
      x = q[f];
      f++;
    }
  return x;
}

void BFS_Algo (int adj[5][5], int visit[])
{
  int i, j, w;
  int start = 0;
  insert (start);
  visit[0] = 1;
  printf ("%d ", start);
  while (!isEmpty ())
    {
      w = rem ();
      for (i = 0; i < 5; i++)
	{
	  if (adj[w][i] && visit[i] == 0)
	    {
	      insert (i);
	      printf ("%d ", i);
	      visit[i] = 1;
	      break;}
	}
    }
}

void main ()
{
  int adj[5][5];
  int visit[5] = { 0 }, i, j;
  printf ("Enter Adjacent Matrix elements:\n");
  for (i = 0; i < 5; i++)
    for (j = 0; j < 5; j++)
      scanf ("%d", &adj[i][j]);
  printf ("BFS Traversal is: ");
  BFS_Algo (adj, visit);
}

/*
Output
Enter Adjacent Matrix elements:
0 1 0
0 0 1
1 0 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
BFS Traversal is: 0 1 3 2 4 
*/