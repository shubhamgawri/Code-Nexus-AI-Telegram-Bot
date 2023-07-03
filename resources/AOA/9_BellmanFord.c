#include <stdio.h>

int main()
{   int e,v;
    printf("Enter number of edges and vertices: ");
    scanf("%d %d",&e,&v);
    int M[e][3],d[v];
    printf("Enter u,v,w\n");
    for (int i=0;i<e;i++)
        for(int j=0;j<3;j++){
            scanf("%d",&M[i][j]);
        }
        printf("\n");
for (int i=0;i<e;i++){
        for(int j=0;j<3;j++){
            printf("%d ",M[i][j]);
        }
        printf("\n");
}

for(int i=0;i<v-1;i++)
    for(int j=0;j<e;j++){
       
    }

    return 0;
}

