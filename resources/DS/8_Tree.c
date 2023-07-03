#include <stdio.h>
#include <stdlib.h>

int c=0,max=-1,min=1000;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node * insert(struct node * root)
{
    int x;
    c++;
    printf("Enter the data: ");
    scanf("%d",&x);
    if(x>=max)
     max=x;
    if(x<=min)
        min=x;
    struct node *tmp, *tmp1, *p;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->data=x;
    tmp->left=tmp->right=NULL;
    if(root==NULL)
    {
        root=tmp;
    }
    else
    {
        tmp1=root;
        while(tmp1!=NULL)
        {
            if(x>tmp1->data)
            {
                p=tmp1;
                tmp1=tmp1->right;
            }
            else
            {
                p=tmp1;
                tmp1=tmp1->left;
            }
        }
        if(x>p->data)
            p->right=tmp;
        else
            p->left=tmp;
    }
    return(root);
}

void display(struct node *root)
{
    struct node *tmp1;
    if(root!=NULL)
    {
        tmp1=root;
        display(tmp1->left);
        printf("%d ",tmp1->data);
        display(tmp1->right);
    }
}

int search(struct node *root, int key)
{
    struct node *tmp, *p;
    int flag=0;
    if(root==NULL)
        return(-1);
    tmp=root;
    while(tmp!=NULL)
    {
        if(key==tmp->data)
        {
            flag=1;
            printf("Key found\n");
            return(1);
        }
        else if(key<tmp->data)
        {
            p=tmp;
            tmp=tmp->left;
        }
        else if(key>tmp->data)
        {
            p=tmp;
            tmp=tmp->right;
        }
    }
    if(flag==0)
        printf("Key not found");
}

struct node *minValueNode(struct node *node) {
  struct node *current = node;

  while (current && current->left != NULL)
    current = current->left;

  return current;
}

struct node *delete_node(struct node *root, int key) {
  if (root == NULL)
  return root;
  if (key < root->data)
    root->left = delete_node(root->left, key);
  else if (key > root->data)
    root->right = delete_node(root->right, key);

  else {
    
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }


    struct node *temp = minValueNode(root->right);

    root->data = temp->data;

    root->right = delete_node(root->right, temp->data);
  }
  return root;
}

int countLeafNode(struct node *root)
{
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNode(root->left) + countLeafNode(root->right);
}

void main()
{
    int ch,s,key,x,ln;
    struct node *root;
    root=NULL;
    while(1)
    {
        printf("\nEnter your choice\n1) Insert\n2) Search\n3) Delete\n4) Display\n5) Count\n6) Maximum\n7) Minimum\n8) Count leaf nodes\n9) Count internal nodes\n10) Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                root=insert(root);
                break;
            case 2:
                printf("Enter the search key\n");
                scanf("%d",&key);
                s=search(root,key);
                break;
            case 3:
                printf("Enter the key to be removed\n");
                scanf("%d", &x);
                root=delete_node(root,x);
                break;
            case 4:
                display(root);
                break;
            case 5:
                printf("Number of nodes are: %d",c);
                break;
            case 6:
                printf("Maximum value is: %d",max);
                break;
            case 7:
                printf("Minimum value is: %d",min);
                break;
            case 8:
                ln=countLeafNode(root);
                printf("Number of leaf nodes are: %d",ln);
                break;
            case 9:
                ln=countLeafNode(root);
                printf("Number of internal nodes are: %d",c-ln);
                break;
            case 10:
                exit(0);
            
        }
    }
}

/*

Enter your choice
1) Insert
2) Search
3) Delete
4) Display
5) Count
6) Maximum
7) Minimum
8) Count leaf nodes
9) Count internal nodes
10) Exit
1
Enter the data: 23

Enter your choice
1) Insert
2) Search
3) Delete
4) Display
5) Count
6) Maximum
7) Minimum
8) Count leaf nodes
9) Count internal nodes
10) Exit
1
Enter the data: 44

Enter your choice
1) Insert
2) Search
3) Delete
4) Display
5) Count
6) Maximum
7) Minimum
8) Count leaf nodes
9) Count internal nodes
10) Exit
1
Enter the data: 45

Enter your choice
1) Insert
2) Search
3) Delete
4) Display
5) Count
6) Maximum
7) Minimum
8) Count leaf nodes
9) Count internal nodes
10) Exit
4
23 44 45
Enter your choice
1) Insert
2) Search
3) Delete
4) Display
5) Count
6) Maximum
7) Minimum
8) Count leaf nodes
9) Count internal nodes
10) Exit
10
*/