#include<stdio.h>

int adj[20][20] ={0};
int visited[20] = {0};
int stack[20];
int top=-1, n;

void push(int n){
    printf("\nPush element: %d", n);
    if(top>9)
        printf("Overflow");
    else{
        top++;
        stack[top] = n;
    }
}
void pop(){
    if(top==-1)
        printf("\nUnderflow");
    else{
        stack[top] = 0;
        top--;
    }
}

void DFS(){
    int start=1, i=0;
    printf("%d", start);
    visited[start] = 1;

    stack[++top] = start;
    while(top != -1)
    {
        for(i = 0; i < n; i++)
        {
            start = stack[top];
            if(adj[start][i] && visited[i] == 0)
            {
                stack[++top] = i;
                printf("-> %d", i);
                visited[i] = 1;
                break;
            }
        }
        if(i == n)  top--;
    }
}

int main(){
    printf("Enter the number of elements: n=");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("enter element a[%d][%d] = ", i+1, j+1);
            scanf("%d", &adj[i][j]);
        }
    }
    printf("DFS traversal is:\n");
    DFS();
}
/*
Enter the number of elements: n=3
enter element a[1][1] = 1
enter element a[1][2] = 2
enter element a[1][3] = 3
enter element a[2][1] = 4
enter element a[2][2] = 5
enter element a[2][3] = 6
enter element a[3][1] = 7
enter element a[3][2] = 8
enter element a[3][3] = 9
DFS traversal is:
1-> 0-> 2
*/
