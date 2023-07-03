#include<stdio.h> 
#include<stdlib.h> 
typedef struct node 
{ 
 int data; 
 struct node *next; 
}node; 
node *create_node() 
{ 
 node *temp; 
 temp = (node*)(malloc(sizeof(node))); 
 printf("Enter data : "); 
 scanf("%d",&temp->data); 
 temp->next = NULL;
 return (temp); 
} 
node * insert_end(node*head) { 
 node *temp; 
 if(head!=NULL) 
 { 
 temp = head; 
 while(temp->next!=NULL)  
 { 
 temp = temp ->next;  } 
 temp->next = create_node(); 
 } 
 return (head); 
} 
void display(node *head) 
{ 
 node *temp;
 temp = head; 
 while(temp!=NULL) 
 { 
 printf("%d\t",temp->data); 
 temp = temp->next; 
 } 
 printf("\n"); 
} 
void middle(node *head) 
{ 
 int count=0,center,i=0,a,b; 
 node *temp,*newnode; 
 temp = head; 
 while(temp!=NULL) 
 { 
 count++; 
 temp = temp->next; 
 } 
 printf("The number of nodes = %d\n",count); 
 temp = head;
 center = (count+1)/2; 
 if(center%2==1) 
 { 
 while ((i<center-1)) 
 { 
 temp = temp->next; 
 i++; 
 } 
 a = temp->data; 
 printf("Middle of the linked list : %d\n",a);  } 
 else 
 { 
 while ((i<center-1)) 
 { 
 temp = temp->next; 
 i++; 
 } 
 newnode = temp->next; 
 a = temp->data; 
 b = newnode->data;
 printf("Middle of the linked list is %d\n",a,b);  } 
} 
int main() 
{ 
 node *head; 
 head = NULL; 
 int ch; 
 printf("Enter first element\n"); 
 head = create_node();  
 while(1) 
 { 
 printf("Enter choice 1.Insert at end 2.Display 3.Find middle 4.Exit : ");  
 scanf("%d",&ch); 
 switch(ch) 
 { 
 case 1 : 
 { 
 head = insert_end(head); 
 break;
 } 
 case 2 : 
 { 
 display(head); 
 break; 
 } 
 case 3 : 
 { 
 middle(head); 
 break; 
 } 
 case 4 : 
 { 
 exit(0); 
 } 
 default : 
 { 
 printf("Incorrect choice\n");  } 
 } 
 }
 return 0; 
 }

 /*
 Enter first element
Enter data : 10
Enter choice 1.Insert at end 2.Display 3.Find middle 4.Exit : 1
Enter data : 20
Enter choice 1.Insert at end 2.Display 3.Find middle 4.Exit : 1
Enter data : 30
Enter choice 1.Insert at end 2.Display 3.Find middle 4.Exit : 1
Enter data : 50
Enter choice 1.Insert at end 2.Display 3.Find middle 4.Exit : 2
10      20      30      50
Enter choice 1.Insert at end 2.Display 3.Find middle 4.Exit : 3
The number of nodes = 4
Middle of the linked list is 20
Enter choice 1.Insert at end 2.Display 3.Find middle 4.Exit : 4
*/