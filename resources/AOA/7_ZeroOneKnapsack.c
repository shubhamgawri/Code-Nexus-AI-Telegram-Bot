#include<stdio.h>

int solution[50] = {0};

int max(int a, int b)
{
    return (a>b) ? a : b;
}

int knapSack(int W,int wt[],int val[],int n)
{
   int K[n+1][W+1];
   
    for(int i=0; i<=n; i++){
        for(int w=0; w<=W; w++){
            K[i][w] = 0;
        }
    }
        
   for(int i=1;i<=n;i++)
   {
       for(int w=1;w<=W;w++)
       {
           if (wt[i] <= w)
           {
           	if(K[i-1][w] < (K[i-1][w-wt[i]]+val[i]))
           		K[i][w] = K[i-1][w-wt[i]]+val[i];
           	else
           	{
           	    K[i][w] = K[i-1][w];
           	}
           			
           }
           else
           {
           	K[i][w] = K[i-1][w];
           }
       }
   }
   printf("%d, %d\n", n, W);
   int i=n, k=W;
   while (i>=0 && k>=0)
   {
   	if (K[i][k] != K[i-1][k])
   	{
   	    printf("%d, %d, %d\n", i, k, K[i][k]);
   		k = k-wt[i];
   		i--;
   		solution[i] = 1;
   	}
   	else
   		i--;
   }
   
   for(int i=0; i<=n; i++){
       for(int w=0; w<=W; w++){
           printf("%d ", K[i][w]);
       }
       printf("\n");
   }
   return K[n][W];
}   

int main()
{
    int n,W;
    printf("Enter number of items: ");
    scanf("%d",&n);
    printf("Enter size of knapsack: ");
    scanf("%d", &W);
   
    int p[n],w[n];
    for(int i=0;i<n;i++)
    {
        printf("\nEnter profit of item%d: ",i+1);
        scanf("%d", &p[i]);
        printf("Enter weight of item%d: ",i+1);
        scanf("%d", &w[i]);
    }
    
    
    printf("\nMaximum profit is: %d\n", knapSack(W,w,p,n));
    
    for(int i=0; i<n; i++){
        printf("%d, ", solution[i]);
    }
    
    return 0;
}


/*
Enter number of items: 6
Enter size of knapsack: 11

Enter profit of item1: 0
Enter weight of item1: 0

Enter profit of item2: 1
Enter weight of item2: 1 

Enter profit of item3: 6
Enter weight of item3: 2

Enter profit of item4: 18
Enter weight of item4: 5

Enter profit of item5: 22
Enter weight of item5: 6

Enter profit of item6: 28
Enter weight of item6: 7
6, 11
4, 11, 40
3, 5, 18
0, 0, 0
0 0 0 0 0 0 0 0 0 0 0 0 
0 1 1 1 1 1 1 1 1 1 1 1 
0 1 6 7 7 7 7 7 7 7 7 7 
0 1 6 7 7 18 19 24 25 25 25 25 
0 1 6 7 7 18 22 24 28 29 29 40 
0 1 6 7 7 18 22 28 29 34 35 40 
0 1 6 7 7 18 22 28 29 34 35 40 

Maximum profit is: 40
0, 0, 1, 1, 0, 0, 

...Program finished with exit code 0
Press ENTER to exit console.
*/
